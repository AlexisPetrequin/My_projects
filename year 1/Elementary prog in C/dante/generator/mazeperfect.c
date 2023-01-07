/*
** EPITECH PROJECT, 2020
** perfect
** File description:
** perfect maze
*/

#include "include.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checkerrors(char **maze, int x, int y, posmaze border)
{
    if (x >= border.x || y >= border.y || x < 0 || y < 0)
        return (0);
    if (maze[y][x] == 'X' || maze[y][x] == '.')
        return (0);
    maze[y][x] += 1;
    return (checkerrors(maze, x + 1, y, border) ||
            checkerrors(maze, x, y + 1, border) ||
            checkerrors(maze, x, y - 1, border) ||
            checkerrors(maze, x - 1, y, border));
}

int checkallpaths(char **maze, int x, int y, posmaze border)
{
    int ran = 0;

    if (x > 0 && y >= 0 && y < border.y && x < border.x)
        if (maze[y][x - 1] == '*' || maze[y][x - 1] == '.')
            ++ran;
    if (x >= 0 && y > 0 && y < border.y && x < border.x)
        if (maze[y - 1][x] == '*' || maze[y - 1][x] == '.')
            ++ran;
    if (x >= 0 && y >= 0 && y + 1 < border.y && x < border.x)
        if (maze[y + 1][x] == '*' || maze[y + 1][x] == '.')
            ++ran;
    if (x >= 0 && y >= 0 && y < border.y && x + 1< border.x)
        if (maze[y][x + 1] == '*' || maze[y][x + 1] == '.')
            ++ran;
    return (ran);
}

int pathmaker3(char **maze, int x, int y, posmaze border)
{
    int ran = 0;
    int rez = 0;

    while (1) {
            maze[y][x] = '.';
        if (rez == 50)
            return (0);
            ran = rand() % 4;
        if ((ran == 0) && x + 1 < border.x &&
            checkallpaths(maze, x + 1, y, border) <= 2)
            ++x;
        if (ran == 1 && checkallpaths(maze, x - 1, y, border) <= 2 && x > 0)
            --x;
        if ((ran == 2) && y + 1 < border.y &&
            checkallpaths(maze, x, y + 1, border) <= 2)
            ++y;
        if (ran == 3 && checkallpaths(maze, x, y - 1, border) <= 2 && y > 0)
            --y;
        rez++;
    }
}

int pathmaker2(char **maze, int x, int y, posmaze border)
{
    int ran = 0;
    int rez = 0;

    while (1) {
            maze[y][x] = '*';
        if (rez == border.x + border.y)
            return (0);
            ran = rand() % 4;
        if ((ran == 0) && checkallpaths(maze, x + 1, y, border) <= 1 &&
            x + 1 < border.x)
            ++x;
        if (ran == 1 && checkallpaths(maze, x - 1, y, border) <= 1 && x > 0)
            --x;
        if ((ran == 2) && checkallpaths(maze, x, y + 1, border) <= 1 &&
            y + 1 < border.y)
            ++y;
        if (ran == 3 && checkallpaths(maze, x, y - 1, border) <= 1 && y > 0)
            --y;
        rez++;
    }
}

int pathmaker(char **maze, int x, int y, posmaze border)
{
    int ran = 0;
    int rez = 0;

    for (;rez != (border.x + border.y) * 3;) {
        maze[y][x] = '*';
        if (x == border.x - 1 && y == border.y - 1)
            return (1);
            ran = rand() % 6;
        if ((ran == 0 || ran == 4) &&
            checkallpaths(maze, x + 1, y, border) <= 1 && x + 1 < border.x)
            ++x;
        if (ran == 1 && checkallpaths(maze, x - 1, y, border) <= 1 && x > 0)
            --x;
        if ((ran == 2 || ran == 5) &&
            checkallpaths(maze, x, y + 1, border) <= 1 && y + 1 < border.y)
            ++y;
        if (ran == 3 && checkallpaths(maze, x, y - 1, border) <= 1 && y > 0)
            --y;
        rez++;
    }
    return (0);
}