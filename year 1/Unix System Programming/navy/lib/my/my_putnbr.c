/*
** EPITECH PROJECT, 2019
** my_putnbr
** File description:
** put number
*/

#include <unistd.h>
#include "../../include/mylist.h"

void print(long nb)
{
    if (nb >= 10)
        print (nb / 10);
    if (nb > 0)
        my_putchar((nb % 10) + 48);
}

int my_putnbr(long nb)
{
    if (nb == 0) {
        write(1, "0", 1);
        return (0);
    }
    if (nb < 0) {
        write(1, "-", 1);
        nb = -nb;
    }
    print(nb);
    return (0);
}