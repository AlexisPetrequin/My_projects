/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** my_putstr.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "include.h"

int count_line(char *str)
{
    int count = 0;

    for (int j = 0; str[j]; ++j) {
        if (str[j] == '\n')
            ++count;
    }
    return (count);
}

char **str_to_strstr(char *str)
{
    int count = count_line(str);
    int i = 0;int k = 0;int l = 0;int maloc = 0;int z = 0;
    char **grid = malloc(sizeof(char*) * count + 1);

    for (int i = 0; str[i] != '\0'; ++i, ++maloc)
        if (str[i] == '\n') {
            grid[z++] = malloc(sizeof(char) * maloc + 2);
            maloc = 0;
            ++i;
        }
    while (k < count) {
        for (l = 0; str[i] != '\n' && str[i] != '\0'; ++i, ++l)
            grid[k][l] = str[i];
        grid[k][l] = '\0';
        ++i;
        ++k;
    }
    return (grid);
}