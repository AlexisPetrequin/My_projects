/*
** EPITECH PROJECT, 2019
** my_str_infnbr
** File description:
** my_str_infnbr.c
*/

#include "../../include/my.h"
#include <stdlib.h>

char *my_infnbr(char *str, int len)
{
    char *str2 = malloc(sizeof(str));
    int j = 0;

    for (int i = len; str[i] >= '0' && str[i] <= '9'; i++) {
        str2[j] = str[i];
        j++;
    }
    return (str2);
}