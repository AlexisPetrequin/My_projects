/*
** EPITECH PROJECT, 2019
** numstr
** File description:
** numstr.c
*/

#include <stdlib.h>
#include "../../include/my.h"

char *numstr2(int res, int i, int check, char *strnum)
{
    int temp = 0;
    int count = 0;
    int b = 0;

    while (res > 0) {
        temp = res;
        for (count = 0; temp > 9; ++count)
            temp = temp / 10;
        b = (check == 0) ? b : check - count - 1;
        for (; b > 0; b--, i++)
            strnum[i] = '0';
        strnum[i] = temp + 48;
        i++;
        check = count;
        for (; count > 0; --count)
            temp *= 10;
        res -= temp;
        if (res == 0)
            for (; check > 0; ++i, --check)
                strnum[i] = '0';
    }
    return (strnum);
}

char *numstr(int res)
{
    char *strnum;
    int temp;
    int i = 0;
    int j;
    int count;
    int check = 0;
    int b;

    temp = res;
    for (j = 0; temp > 9 || temp < -9; j++)
        temp /= 10;
    strnum = malloc(sizeof(char) * (j + 2));
    if (res < 0) {
        res *= -1;
        strnum[i] = '-';
        ++i;
    }
    strnum = numstr2(res, i, check, strnum);
    strnum[i] = '\0';
    return (strnum);
}
