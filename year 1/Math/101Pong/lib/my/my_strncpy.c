/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** c
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (dest[i] != '\0' && i < n) {
        if (src[i] == '\0') {
            dest[i] = '\0';
            return (dest);
        } else {
            dest[i] = src[i];
        }
        i++;
    }
    if (i == n) {
        dest[i] = '\0';
        return (dest);
    }
    return (dest);
}