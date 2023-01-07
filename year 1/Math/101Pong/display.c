/*
** EPITECH PROJECT, 2019
** For the alliance!
** File description:
** FOR THE ALLIANCE!
*/

#include <stdio.h>
#include "include/my.h"

void display_number(float val)
{
    if (val < 0) {
        my_putchar('-');
        val *= -1;
    }
    int partie_entiere = val;
    int partie_dec = val * 100;
    int next_val = val * 1000;
    
    next_val -= partie_dec * 10;
    partie_dec -= partie_entiere * 100;
    if (next_val >= 5)
        ++partie_dec;
    if   (partie_dec == 100) {
        ++partie_entiere;
        partie_dec = 0;
    }
    my_put_nbr(partie_entiere);
    my_putchar('.');
    if (partie_dec < 10)
        my_putchar('0');
    my_put_nbr(partie_dec);
} 
