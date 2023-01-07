/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** c
*/

#include "../include.h"

int my_strcmp(char const *str1, char const *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    int i = 0;

    if (len1 != len2)
        return(0);
    while (str1[i] != '\0') {
        if (str1[i] != str2[i])
            return(0);
        ++i;
    }
    return (1);
}
