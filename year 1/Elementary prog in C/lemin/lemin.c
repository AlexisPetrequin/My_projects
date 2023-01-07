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

char *getinfo(void)
{
    char buffer[3];
    char *str = malloc(100);

    while (read(0, buffer, 2))
        str = my_strcat(str, buffer);
    return (str);
}

char **inputgestion(char *map, int nblines)
{
    char **starmap;
    starmap = str_to_strstr(map);
    starmap = clearprint(starmap, nblines);

    return (starmap);
}

void printstart(int nblines, char **starmap)
{
    for (int i = 0; i < nblines; ++i) {
        if (starmap[i] == NULL)
            ++i;
        my_putstr(starmap[i]);
        my_putchar('\n');
    }
}

int verif_struct(initpath *path)
{
    if (path->nbants <= 0 || path->nbrlinesroom <= 0 ||
        path->nbrlinespath <= 0)
        return (84);
    if (path->endroom == NULL || path->startroom == NULL)
        return (84);
}

int main(void)
{
    char *map;
    char **starmap;
    int nblines;
    initpath *path;

    map = getinfo();
    nblines = count_line(map);
    starmap = inputgestion(map, nblines);
    path = initiatestruct(nblines, starmap);
    if (verif_struct(path) == 84)
        return (84);
    printstart(nblines, starmap);
    return (0);
}