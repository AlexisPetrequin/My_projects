/*
** EPITECH PROJECT, 2020
** nperfect
** File description:
** about imperfect maze
*/

#include "include.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int makepath2(int x, int y, posmaze border, char **maze)
{
    int ran = 0;
    int rez = 0;

    while (1) {
            maze[y][x] = '*';
        if (rez == border.x * border.y)
            return (0);
            ran = rand() % 4;
        if ((ran == 0) && x + 1 < border.x &&
            checkallpaths(maze, x + 1, y, border) <= 1)
            x++;
        if (ran == 1 && x > 0 && checkallpaths(maze, x - 1, y, border) <= 1)
            x--;
        if ((ran == 2) && y + 1 < border.y &&
            checkallpaths(maze, x, y + 1, border) <= 1)
            y++;
        if (ran == 3 && y > 0 && checkallpaths(maze, x, y - 1, border) <= 1)
            y--;
        rez++;
    }
}

int makepath(int x, int y, posmaze border, char **maze)
{
    int ran = 0;
    int rez = 0;

    for (;rez != (border.x + border.y) * 3;) {
        maze[y][x] = '*';
        if (x == border.x - 1 && y == border.y - 1)
            return (1);
            ran = rand() % 6;
        if ((ran == 0 || ran == 4) && x + 1 < border.x &&
            checkallpaths(maze, x + 1, y, border) <= 2)
            ++x;
        if (ran == 1 && checkallpaths(maze, x - 1, y, border) <= 1 && x > 0)
            --x;
        if ((ran == 2 || ran == 5) && y + 1 < border.y &&
            checkallpaths(maze, x, y + 1, border) <= 1)
            ++y;
        if (ran == 3 && checkallpaths(maze, x, y - 1, border) <= 2 && y > 0)
            --y;
        rez++;
    }
    return (0);
}

int generateimperfect(int len, int height)
{
    posmaze border = {len, height};
    char **maze = initmaze(border.x, border.y);

    for (;makepath(0, 0, border, maze) == 0;) {
            mazefree(maze);
            maze = initmaze(border.x, border.y);
        }
    for (int i = 0; i < border.y; i += 2)
        for (int j = 0; j < border.x; j += 2)
            if (checkallpaths(maze, j, i, border) <= 2 && maze[i][j] == '*')
                makepath2(j, i, border, maze);
    clearmaze(maze);
    checkerrors(maze, 0, 0, border);
     for (int i = 0; i < border.y; i++)
        for (int j = 0; j < border.x; j++)
            if (maze[i][j] == '*')
                maze[i][j] = 'X';
    clearmaze(maze);
    for (int y = 0; maze[y] != NULL; y++)
        my_putstr(maze[y]);
    mazefree(maze);
}

int generateperfect2(char **maze, posmaze border)
{
    for (int i = 0; i < border.y; i++)
        for (int j = 0; j < border.x; j++)
            if (checkallpaths(maze, j, i, border) <= 2 && maze[i][j] == '*')
                pathmaker2(maze, j, i, border);
    for (int i = 0; i < border.y; i++)
        for (int j = 0; j < border.x; j++)
            if (checkallpaths(maze, j, i, border) <= 1 && maze[i][j] == 'X')
                pathmaker2(maze, j, i, border);
    checkerrors(maze, 0, 0, border);
    for (int i = 0; i < border.y; i++)
        for (int j = 0; j < border.x; j++)
            if (maze[i][j] == '*')
                pathmaker3(maze, j, i, border);
    clearmaze(maze);
    checkerrors(maze, 0, 0, border);
    for (int i = 0; i < border.y; i++)
        for (int j = 0; j < border.x; j++)
            if (maze[i][j] == '*')
                return (0);
    return (1);
}

void generateperfect(int x, int y)
{
    posmaze border = {x, y};
    char **maze = initmaze(border.x, border.y);
    int check = 0;

    for (;check == 0;) {
        for (;pathmaker(maze, 0, 0, border) == 0;) {
            mazefree(maze);
            maze = initmaze(border.x, border.y);
        }
        check = generateperfect2(maze, border);
    }
    clearmaze(maze);
    for (int y = 0; maze[y] != NULL; y++)
        my_putstr(maze[y]);
}