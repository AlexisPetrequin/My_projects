/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** 
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    for (; *str != '\0' && str != 0; ++str)
        write(1, str, 1);
    return (0);
}
