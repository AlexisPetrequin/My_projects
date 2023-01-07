/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenate two strings
*/

#include <stdlib.h>
#include "../../include/mylist.h"

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(src) + my_strlen(dest);
    int destlen = my_strlen(dest);
    char *temp;

    temp = malloc(len);
    for (int i = 0; dest[i]; ++i) {
        temp[i] = dest[i];
    }
    for (int i = 0; src[i]; ++i) {
        temp[destlen + i] = src[i];
    }
    return (temp);
}