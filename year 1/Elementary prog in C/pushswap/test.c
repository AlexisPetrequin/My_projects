/*
** EPITECH PROJECT, 2019
**
** File description:
**
*/

#include "include/my.h"

int space(int *array, int size)
{
    for (int i = 0; i < size - 1; ++i) {
        if (array[i] > array[i + 1]) {
            my_putchar(' ');
            return (0);
        }
    }
    return (1);
}

int test(int *array, int size)
{
    for (int i = 0; i < size - 1; ++i) {
        if (array[i] > array[i + 1])
            return (0);
    }
    return (1);
}