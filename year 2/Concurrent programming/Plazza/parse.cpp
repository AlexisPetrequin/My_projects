/*
** EPITECH PROJECT, 2021
** parse.cpp
** File description:
** parse
*/

#include <string.h>
#include <iostream>
#include <stack>
#include <string>
#include <iostream>
#include <stack>
#include <string.h>
#include "include/Engine.hpp"

char *piz_quantity(std::string line)
{
    char *num = (char *)malloc(sizeof(char) * (line.size() + 1));
    int pos = 0;

    while (line[pos] && line[pos] >= '0' && line[pos] <= '9') {
        num[pos] = line[pos];
        pos++;
    }
    num[pos] = '\0';
    if (strlen(num) <= 0 || atoi(num) <= 0)
        return (NULL);
    return (num);
}

PizSize piz_size(std::string line)
{
    for (int i = 0; i < pizzaLen; i++)
        if (!strncmp(line.c_str(), Size[i].first, strlen(Size[i].first)))
            return(Size[i].second);
    return (O);
}

PizType piz_type(std::string line)
{
    for (int i = 0; i < pizzaLen; i++)
        if (!strncmp(line.c_str(), Names[i].first, strlen(Names[i].first)))
            return(Names[i].second);
    return (Nil);
}

bool syntax(char *line)
{
    pizzaOrder_t elem;
    std::string str(line);
    char *quant = NULL;

    while (str.length() != 0) {
        while (str[0] == ';' || str[0] == ' ')
            str.erase(0, 1);
        if (!str.length())
            break;
        elem.type = piz_type(str);
        if (elem.type == Nil || str.length() < strlen(Names[elem.type - 1].first) + 1)
            return (false);
        str.erase(0, strlen(Names[elem.type - 1].first) + 1);
        elem.size = piz_size(str);
        if (!elem.size || str.length() < strlen(Size[elem.size - 1].first) + 1) {
            return (false);
        }
        str.erase(0, strlen(Size[elem.size - 1].first) + 1);
        if (str[0] == 'x')
            str.erase(0, 1);
        quant = piz_quantity(str);
        if (!quant || str.length() < strlen(quant)) {
            if (quant)
                free(quant);
            return (false);
        }
        str.erase(0, strlen(quant));
        elem.quantity = atoi(quant);
        free(quant);
    }
    return (true);
}

std::stack<pizzaOrder_t> parse_parser(Engine *eng, char *line)
{
    std::stack<pizzaOrder_t> order;
    std::stack<pizzaOrder_t> nul;
    pizzaOrder_t elem;
    std::string str(line);
    char *quant = NULL;

    if (!syntax(line))
        return (nul);
    while (str.length() != 0) {
        while (str[0] == ';' || str[0] == ' ')
            str.erase(0, 1);
        if (!str.length())
            break;
        elem.type = piz_type(str);
        str.erase(0, strlen(Names[elem.type - 1].first) + 1);
        elem.size = piz_size(str);
        str.erase(0, strlen(Size[elem.size - 1].first) + 1);
        if (str[0] == 'x')
            str.erase(0, 1);
        quant = piz_quantity(str);
        str.erase(0, strlen(quant));
        elem.quantity = atoi(quant);
        free(quant);
        order.push(elem);
    }
    return (order);
}

char *parse_read_line(void)
{
    int read_size = 1024;
    char *str = (char *)malloc(sizeof(char) * read_size);
    int size = read_size;
    char c;
    int pos = 0;

    if (!str)
        return (NULL);
    for (; true;) {
        c = getchar();
        if (!c || -1 == c || c == '\n') {
            str[pos] = '\0';
            return (str);
        } else
            str[pos] = c;
        (void)c;
        pos++;
        if (pos >= read_size) {
            size += read_size;
            str = (char *)realloc(str, size);
        }
    }
}

void *parse_loop(void *eng)
{
    Engine *engine = (Engine *)eng;
    char *line = NULL;

    for (; engine->running;) {
        std::cout << "> ";
        line = parse_read_line();
        if (!line)
            break;
        if (!strcmp(line, "status"))
            engine->display();
        else if (!strcmp(line, "exit"))
            engine->running = false;
        else {
            std::stack<pizzaOrder_t>stack = parse_parser(engine, line);
            if (stack.empty())
                std::cerr << "Invalid command. Please check syntax." << std::endl;
            else
                engine->load_orders(stack);
        }
        if (line)
            free(line);
    }
    return (NULL);
}