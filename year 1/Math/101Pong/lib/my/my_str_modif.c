/*
** EPITECH PROJECT, 2019
** strmodif
** File description:
** For the alliance!
*/

#include <stdlib.h>
#include "../../include/my.h"

char *str_modif(char *src)
{
    char *str;
    int i = 0;
    int j = 0;
    int k = 0;
    int space = 0;

    while (src[j] != '\0') {
        if (src[j] == ' ')
            ++space;
        ++j;
    }
    str = malloc(sizeof(char) * j - space);
    for (; i < j; i++) {
        for (k; src[k] == ' '; ++k);
        str[i] = src[k];
        ++k;
    }
    str[i] = '\0';
    return (str);
    free(str);
}