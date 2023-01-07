/*
** EPITECH PROJECT, 2019
** number
** File description:
** number.c
*/

#include "include/my.h"

int number(char *str)
{
    int i = 0;
    int nbr = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == '-') {
            ++count;
            i++;
        }
        nbr += (str[i] - 48);
        if (str[i + 1] != '\0' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
            nbr *= 10;
        ++i;
    }
    for (int i = 0; i < count; ++i)
        nbr *= -1;
    return (nbr);
}