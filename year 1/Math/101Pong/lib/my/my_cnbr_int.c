/*
** EPITECH PROJECT, 2019
** my_cnbr_int
** File description:
** my_cnbr_int.c
*/

#include "../../include/my.h"

int my_cnbr_int(char *str, int num, int len1, int len2)
{
    int p;

    if (*str == 0) {
        return (num);
    } else {
        p = ('+' == str[1] || '\0' == str[1]) ? (1) : (10);
        num += (len1 >= 0) ? (*str - 48) * my_compute_power_rec(p, len1) :
            (*str - 48) * my_compute_power_rec(p, len2);
        ('+' == str[1]) ? (--len2, str += 2) : (--len1, ++str);
        my_cnbr_int(str, num, len1, len2);
    }
}