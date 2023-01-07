/*
** EPITECH PROJECT, 2019
** my_print_params
** File description:
** displays its arguments
*/

#include "../../include/my.h"

int my_print_params(int argc, char **argv)
{
    for (int i = 0; i != argc; i++)
        my_putstr(argv[i]);
}