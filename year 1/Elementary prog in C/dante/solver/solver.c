/*
** EPITECH PROJECT, 2020
** main
** File description:
** laby
*/

#define _GNU_SOURCE
#include "include.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solver4(char **maze, int x, int y, posmaze border)
{
    if (x >= border.x || y >= border.y || x < 0 || y < 0)
        return (0);
    if (maze[y][x] != 'o')
        return (0);
    maze[y][x] = 'a';
    if (x == border.x - 1 && y == border.y - 1)
        return (1);
    return (solver4(maze, x + 1, y, border) ||
            solver4(maze, x, y - 1, border) ||
            solver4(maze, x, y + 1, border) ||
            solver4(maze, x - 1, y, border));
}

int solver3(char **maze, int x, int y, posmaze border)
{
    if (x >= border.x || y >= border.y || x < 0 || y < 0)
        return (0);
    if (maze[y][x] != 'o')
        return (0);
    maze[y][x] = 'a';
    if (x == border.x - 1 && y == border.y - 1)
        return (1);
    return (solver3(maze, x - 1, y, border) ||
            solver3(maze, x, y + 1, border) ||
            solver3(maze, x + 1, y, border) ||
            solver3(maze, x, y - 1, border));
}

int solver2(char **maze, int x, int y, posmaze border)
{
    if (x >= border.x || y >= border.y || x < 0 || y < 0)
        return (0);
    if (maze[y][x] != 'a')
        return (0);
    maze[y][x] = 'o';
    if (x == border.x - 1 && y == border.y - 1)
        return (1);
    return (solver2(maze, x, y - 1, border) ||
            solver2(maze, x + 1, y, border) ||
            solver2(maze, x, y + 1, border) ||
            solver2(maze, x - 1, y, border));
}

int solver(char **maze, int x, int y, posmaze border)
{
    if (x >= border.x || y >= border.y || x < 0 || y < 0)
        return (0);
    if (maze[y][x] != '*')
        return (0);
    maze[y][x] = 'a';
    if (x == border.x - 1 && y == border.y - 1)
        return (1);
    return (solver(maze, x + 1, y, border) ||
            solver(maze, x, y + 1, border) ||
            solver(maze, x, y - 1, border) ||
            solver(maze, x - 1, y, border));
}

int main(int ac, char **av)
{
    int lines = countlines(av[1]);
    char **maze = mazesearching(av[1], lines);
    posmaze border = { my_strlen(maze[0]) - 1, lines };


    solver(maze, 0, 0, border);
    if (maze[border.y - 1][border.x - 1] != 'a') {
        my_putstr("no solution found\n");
        return (0);
    }
    solver2(maze, 0, 0, border);
    clearmaze(maze);
    solver3(maze, 0, 0, border);
    clearmaze2(maze);
    solver4(maze, 0, 0, border);
    clearmaze2(maze);
    for (int i = 0; maze[i] != NULL; i++)
        my_putstr(maze[i]);
    mazefreeing(maze);
    return (0);
}