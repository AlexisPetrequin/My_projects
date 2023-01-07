/*
** EPITECH PROJECT, 2019
** modstr
** File description:
** For the HOOORD!
*/

#include <stdlib.h>
#include "../../include/my.h"

char *modstr(char *str, int posi, int i, int res)
{
    char *nstr;
    int size;
    char *num;
    int e;

    for (size = 0; str[size] != '\0'; ++size);
    nstr = malloc(sizeof(char) * size);
    for (e = 0; e <= posi; e++)
        nstr[e] = str[e];
    num = numstr(res);
    for (int z = 0; num[z] != '\0'; ++z, ++e)
        nstr[e] = num[z];
    for (; str[i] != '\0'; ++e, ++i)
        nstr[e] = str[i];
    return (nstr);
    free(nstr);
}
