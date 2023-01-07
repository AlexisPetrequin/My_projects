/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** concatenate two strings
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i;

    for (i = 0; dest[i] != '\0'; i++);
    for (int n = 0; src[n] != '\0' && n < nb; n++) {
        dest[i] = src[n];
        i++;
    }
}