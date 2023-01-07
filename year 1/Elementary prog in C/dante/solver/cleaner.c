/*
** EPITECH PROJECT, 2020
** utilitary
** File description:
** about utilitary
*/

#define _GNU_SOURCE
#include "include.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mazefreeing(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++)
        free(maze[i]);
    free(maze);
}

void clearmaze2(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++)
        for (int j = 0; maze[i][j] != '\0'; j++) {
            if (maze[i][j] == 'o')
                maze[i][j] = '*';
            if (maze[i][j] == 'a')
                maze[i][j] = 'o';
        }
}

void clearmaze(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++)
        for (int j = 0; maze[i][j] != '\0'; j++)
            if (maze[i][j] == 'a')
                maze[i][j] = '*';
}

int countlines(char *path)
{
    FILE *op = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int rez = 0;

    if (op == NULL)
        return (0);
    for (;(read = getline(&line, &len, op)) != -1;)
        rez++;
    if (line)
        free (line);
    fclose(op);
    return (rez);
}

char **mazesearching(char *path, int lines)
{
    FILE *op = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;
    char **maze;

    if (op == NULL)
        return (NULL);
    maze = malloc(sizeof(char *) * (lines + 1));
    for (;(read = getline(&line, &len, op)) != -1; ++i) {
        maze[i] = malloc(read + 1);
        strcpy(maze[i], line);
    }
    maze[lines] = NULL;
    if (line)
        free (line);
    fclose(op);
    return (maze);
}