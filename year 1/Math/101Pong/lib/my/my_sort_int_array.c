/*
** EPITECH PROJECT, 2019
** my_sort_int_array
** File description:
** c
*/

#include "../../include/my.h"

void my_sort_int_array(int *tab, int size)
{
    int i = 1;
    int n;

    while (1 == i) {
        n = 0;
        i = 0;

        while (n < (size - 1)) {
            if (tab[n] > tab[i + 1]) {
                my_swap(tab + n, tab + i + 1);
                i = 1;
            }
            n = n + 1;
        }
    }
}