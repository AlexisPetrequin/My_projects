/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** my_putstr.c
*/

typedef struct t_path
{
    int nbrline;
    int nbrlinesroom;
    int nbrlinespath;
    int nbants;
    char *startroom;
    char *endroom;
    char **rooms;
    char **paths;
} initpath;