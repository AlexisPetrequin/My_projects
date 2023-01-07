/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** c
*/

int my_compute_square_root(int nb)
{
    int sub = 0;

    if (nb < 0 || nb == 0)
        return (0);
    for (sub = 0; sub * sub != nb; sub++)
        if (sub > nb)
            return (0);
    return (0);
}