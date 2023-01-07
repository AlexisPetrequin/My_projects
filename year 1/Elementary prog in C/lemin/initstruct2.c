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


int initpaths(char **starmap, initpath *path, int i)
{
    static int temp = 0;

    if (starmap[i][0] != '\0' && my_strlen(starmap[i]) == 3 && i != 0)
        temp++;
    return (temp);
}

void fillpaths(char **starmap, initpath *path, int i)
{
    static int x = 0;

    if (starmap[i][0] != '\0' && my_strlen(starmap[i]) == 3 && i != 0) {
        path->paths[x] = malloc(my_strlen(starmap[i]));
        for (int j = 0; starmap[i][j] != '\0'; ++j)
            path->paths[x][j] = starmap[i][j];
        x++;
    }
}

void fillrooms(char **starmap, initpath *path, int i)
{
    static int temp = 0;

    if (starmap[i][0] != '\0' && my_strlen(starmap[i]) != 3 && i != 0) {
        path->rooms[temp] = malloc(my_strlen(starmap[i]));
        for (int j = 0; starmap[i][j] != ' '; ++j)
            path->rooms[temp][j] = starmap[i][j];
        temp++;
    }
}

initpath *secondinit(initpath *path, char **starmap, int start, int end)
{
    int count = 0;

    for (int i = 0; i < path->nbrline; ++i) {
        if (i != start && i != end && i != start - 1 && i != end - 1)
            fillrooms(starmap, path, i);
    }
    for (int i = 0; i < path->nbrline; ++i) {
        if (i != start && i != end && i != start - 1 && i != end - 1)
            count = initpaths(starmap, path, i);
    }
    path->paths = malloc(sizeof(char *) * count);
    path->nbrlinespath = count;
    for (int i = 0; i < path->nbrline; ++i) {
        if (i != start && i != end && i != start - 1 && i != end - 1)
            fillpaths(starmap, path, i);
    }
    return (path);
}