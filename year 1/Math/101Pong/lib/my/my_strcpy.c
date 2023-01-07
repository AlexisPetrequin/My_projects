/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** c
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(src);

    dest = malloc(len);
    while (src[i]){
        dest[i] = src[i];
        ++i;
    }
    return (dest);
}