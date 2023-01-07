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
int my_getnbr(char const *str);
int my_putstr(char *str);
char **initmaze(int len, int height);
int checkerrors(char **maze, int x, int y, posmaze border);
void mazefree(char **maze);
void clearmaze(char **maze);
int generateimperfect(int len, int height);
int checkallpaths(char **maze, int x, int y, posmaze border);
int pathmaker(char **maze, int x, int y, posmaze border);
int pathmaker2(char **maze, int x, int y, posmaze border);
int pathmaker3(char **maze, int x, int y, posmaze border);
int check(char **argv);
void generateperfect(int x, int y);