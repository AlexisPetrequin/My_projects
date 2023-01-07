/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** my_show_word_array.c
*/

#include "../../include/my.h"

int my_show_word_array(char * const *tab)
{
    int number = 0;

    for (int j = 0; tab[j] != 0; j++) {
        for (int i = 0; tab[j][i] != '\0'; i++) {
            number++;
            my_putchar(tab[j][i]);
        }
        my_putchar('\n');
    }
}
