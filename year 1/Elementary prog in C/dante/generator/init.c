/*
** EPITECH PROJECT, 2020
** utility
** File description:
** about malloc
*/

#include "include.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mazefree(char **maze)
{
    for (int i = 0; maze[i]; i++)
        free(maze[i]);
    free(maze);
}

void clearmaze(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++)
        for (int j = 0; maze[i][j] != '\n' && maze[i][j] != '\0'; j++)
            if (maze[i][j] != 'X')
                maze[i][j] = '*';
}

int check(char **av)
{
    for (int i = 1; i <= 2; i++)
        for (int j = 0; av[i][j] != '\0'; j++)
            if (av[i][j] < '0' || av[i][j] > '9')
                return (1);
    if (my_getnbr(av[1]) == 0 || my_getnbr(av[2]) == 0)
        return (1);
    return (0);
}

char **initmaze(int len, int height)
{
    char **maze = malloc(sizeof(char *) * (height + 1));

    for (int i = 0; i < height; i++)
        maze[i] = malloc(len + 2);
    maze[height] = NULL;
    for (int i = 0; i < height; i++)
        for (int j = 0; j <= len + 1; j++) {
            maze[i][j] = 'X';
            if (j == len)
                maze[i][j] = '\n';
            if (j == len + 1)
                maze[i][j] = '\0';
        }
    maze[height - 1][len] = '\0';
    maze[0][0] = '0';
    return (maze);
}