/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** my_str_isnum.c
*/

int my_str_isnum(char str)
{
    return (str <= '9' && str >= '0') ? (1) : (0);
}