/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** c
*/

int my_is_prime(int nb)
{
    if (nb < 2 || nb % 2 == 0)
        return (0);
    if (nb == 2)
        return (1);
    for (int i = 3; i * i <= nb; i++) {
        if (0 == nb % i)
            return (0);
        i++;
    }
    return (1);
}
