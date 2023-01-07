/*
** EPITECH PROJECT, 2019
**
** File description:
**
*/

#include "include/my.h"

int *sa(int *array, int size)
{
    int stock;

    my_putstr("sa");
    stock = array[0];
    array[0] = array[1];
    array[1] = stock;
    space(array, size);
    return (array);
}

int *ra(int *array, int size)
{
    int stock;
    int i = 0;

    my_putstr("ra");
    stock = array[0];
    while (i < size - 1) {
        array[i] = array[i + 1];
        i++;
    }
    array[i] = stock;
    space(array, size);
    return (array);
}

int loop(int *array, int size)
{
    int restest = 0;
    int j = 0;
    int i = 0;

    while (j < size) {
        restest = test(array, size);
        if (restest == 1)
            return (0);
        if (j == size - 1) {
            array = ra(array, size);
            ++j;
        }
        else if (array[0] > array[1]) {
            array = sa(array, size);
        } else {
            array = ra(array, size);
            ++j;
        }
    }
    if (restest == 0)
        loop(array, size);
}

int main(int ac, char **av)
{
    int size = ac - 1;
    int array[size];
    int interror = 0;

    interror = error_executor(ac, av);
    if (interror == 84) {
        return (84);
    }
    if (interror == 2)
        return (0);
    for(int i = 1; i < ac; ++i) {
        array[i - 1] = number(av[i]);
    }
    loop(array, size);
    my_putchar('\n');
}