/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** my_putstr.c
*/

#include "struct.h"

char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);
char **str_to_strstr(char *str);
int count_line(char *str);
char **clearprint(char **starmap, int nblines);
int my_putstr(char *str);
char my_putchar(char c);
int my_strcmp(char const *str1, char const *str2);
int number(char *str);
initpath *initiatestruct(int nblines, char **starmap);
initpath *secondinit(initpath *path, char **starmap, int start, int end);
void pathfinding(initpath *path);
int verif(char *str, char *comp);