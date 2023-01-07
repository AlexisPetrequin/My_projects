/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** my_getnbr.c
*/

int my_getnbr(char const *str)
{
    int y = 0;
    int i = 0;
    int check = 0;
    int nb = 0;

    for (; str[i] == '-' || str[i] == '+'; i++, y++);
    for (; str[i] >= '0' && str[i] <= '9' && str[i]; check++, i++) {
        nb += str[i] - 48;
        nb = nb * 10;
    }
    if (check > 0 && str[y-1] && y > 0 == '-') {
        nb = nb / 10;
        return (-nb);
    }
    if (check > 0) {
        nb = nb / 10;
        return (nb);
    }
    return (0);
}