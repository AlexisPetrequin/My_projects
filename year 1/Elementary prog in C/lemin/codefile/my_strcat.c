/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenate two strings
*/

#include <stdlib.h>
#include "../include.h"

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(src);
    int destlen = 0;
    char *temp;
    int i = 0;

    if (my_strlen(dest) != 0) {
        len += my_strlen(dest);
        destlen += my_strlen(dest);
    }
    temp = malloc(len + 1);
    for (i = 0; dest[i]; ++i) {
        temp[i] = dest[i];
    }
    for (i = 0; src[i]; ++i) {
        temp[destlen + i] = src[i];
    }
    temp[destlen + i] = '\0';
    return (temp);
}