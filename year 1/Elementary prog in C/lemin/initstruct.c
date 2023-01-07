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

int startroom(char **starmap, int i, initpath *path)
{
    int rez = 0;
    static int check = 0;

    if (my_strcmp(starmap[i], "##start")) {
        ++check;
        if (check > 1)
            return (-10);
        path->startroom = malloc(100);
        for (int j = 0; starmap[i + 1][j] != ' '; ++j)
            path->startroom[j] = starmap[i + 1][j];
        rez = i + 1;
    }
    return (rez);
}

int endroom(char **starmap, int i, initpath *path)
{
    int rez = 0;
    static int check = 0;

    if (my_strcmp(starmap[i], "##end")) {
        ++check;
        if (check > 1)
            return (-10);
        path->endroom = malloc(100);
        for (int j = 0; starmap[i + 1][j] != ' '; ++j)
            path->endroom[j] = starmap[i + 1][j];
        rez = i + 1;
    }
    return (rez);
}

int initrooms(char **starmap, initpath *path, int i, int count)
{
    if (starmap[i][0] != '\0' && my_strlen(starmap[i]) != 3 && i != 0) {
        ++count;
    }
    return (count);
}

initpath *initiatestruct(int nblines, char **starmap)
{
    initpath *path = malloc(sizeof(initpath));
    int temp = 0;
    int start = 0;
    int end = 0;
    int count = 0;

    path->nbrline = nblines;
    path->nbants = number(starmap[0]);
    for (int i = 0; i < nblines; ++i) {
        if ((temp = startroom(starmap, i, path)) != 0)
            start = temp;
        if ((temp = endroom(starmap, i, path)) != 0)
            end = temp;
    }
    if (end == -10 || start == -10)
            return (path);
    for (int i = 0; i < nblines; ++i)
        if (i != start && i != end && i != start - 1 && i != end - 1)
            count = initrooms(starmap, path, i, count);
    path->rooms = malloc(sizeof(char *) * (count + 1));
    path->nbrlinesroom = count;
    path = secondinit(path, starmap, start, end);
    return (path);
}
