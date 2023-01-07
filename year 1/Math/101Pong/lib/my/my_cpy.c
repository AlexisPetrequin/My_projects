/*
** EPITECH PROJECT, 2019
** my_cpy
** File description:
** my_cpy.c
*/

#include "../../include/my.h"

char *my_cpy(char *copied, char *str2, int b)
{
    for (int y = 0; copied[y]; y++, b++)
        str2[b] = copied[y];
    str2[b] = '\0';
    return (str2);
}