/*
** EPITECH PROJECT, 2021
** parse.hpp
** File description:
** parse
*/

#ifndef PARSE_HPP_
#define PARSE_HPP_

#include <chrono>
#include <thread>
#include <vector>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <iostream>
#include <stack>
#include <mutex>
#include <unistd.h>
#include <utility>
#include <stack>

class Engine;

typedef struct pizzaOrder_s {
    int type;
    int size;
    int quantity;
} pizzaOrder_t;

bool parse_syntax(char *);
std::stack<pizzaOrder_t> parse_parser(Engine *, char *);
void *parse_loop(void *);
char *parse_read_line(void);

#endif /* !PARSE_HPP_ */