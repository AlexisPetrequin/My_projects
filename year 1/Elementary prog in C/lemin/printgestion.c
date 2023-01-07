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

int test(char **starmap, int line, int j)
{
    for (; starmap[line][j] != '\0'; ++j);
    return (j);
}

void selection(char **starmap, char **phrase, int line, int i)
{
    for (int j = 0; starmap[line][j]; ++j) {
        if (starmap[line][j] == '#' && starmap[line][j + 1] != '#' &&
            starmap[line][j - 1] != '#')
        j = test(starmap, line, j);
        phrase[i][j] = starmap[line][j];
    }
}

char **clearprint(char **starmap, int nblines)
{
    char **phrase = malloc(sizeof(char *) * nblines + 1);
    int line = 0;

    for (int i = 0; i < nblines; ++i)
        phrase[i] = malloc(my_strlen(starmap[i]) + 1);

    for (int i = 0; i < nblines; ++i, ++line)
        selection(starmap, phrase, line, i);
    return (phrase);
}