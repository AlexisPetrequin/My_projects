/*
** EPITECH PROJECT, 2020
** main
** File description:
** laby
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"

char my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char *str);
void clearmaze(char **maze);
void clearmaze2(char **maze);
void mazefreeing(char **maze);
int countlines(char *path);
int solver(char **maze, int x, int y, posmaze border);
int solver2(char **maze, int x, int y, posmaze border);
int solver3(char **maze, int x, int y, posmaze border);
int solver4(char **maze, int x, int y, posmaze border);
char **mazesearching(char *path, int lines);