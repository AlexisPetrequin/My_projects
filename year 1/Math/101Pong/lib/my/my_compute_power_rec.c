/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** c
*/

int my_compute_power_rec(int nb, int p)
{
    int c = nb;

    if (p < 1) return (1);
    c = c * my_compute_power_rec(nb, p - 1);
    return (c);
}