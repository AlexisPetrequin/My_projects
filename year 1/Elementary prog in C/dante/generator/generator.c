/*
** EPITECH PROJECT, 2020
** main
** File description:
** laby
*/

#include "include.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int ac, char **av)
{
    srand(time(NULL));

    if (ac != 3 && ac != 4)
        return (84);
    if (check(av))
        return (84);
    if (ac == 3)
        generateimperfect(my_getnbr(av[1]), my_getnbr(av[2]));
    if (ac == 4 && av[3][0] == 'p' && av[3][1] == 'e' && av[3][2] == 'r' &&
        av[3][3] == 'f' && av[3][4] == 'e' && av[3][5] == 'c' &&
        av[3][6] == 't' && av[3][7] == '\0')
        generateperfect(my_getnbr(av[1]), my_getnbr(av[2]));
    return (0);
}