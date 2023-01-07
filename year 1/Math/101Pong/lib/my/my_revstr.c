/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** my_revstr.c
*/

char *my_revstr(char *str)
{
    int i;
    int n = 0;
    char tmp;

    for (i = 0; str[i] != '\0'; i++);
    i = i - 1;
    for (i = i; i > n; i--) {
        tmp = str[i];
        str[i] = str[n];
        str[n] = tmp;
        n = n + 1;
    }
    return (str);
}