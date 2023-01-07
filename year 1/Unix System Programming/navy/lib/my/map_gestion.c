/*
** EPITECH PROJECT, 2019
** empty
** File description:
** empty
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/mylist.h"
#include <time.h>
#include <features.h>
#include <fcntl.h>
#include <sys/stat.h>

void fill_string(char *src, char *cp)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        cp[i] = src[i];
    cp[i] ='\0';
}

char **map_create(void)
{
    char **map = malloc(sizeof(char *) * 11);
    int y = 0;

    if (map == NULL)
        return (NULL);
    for (int i = 0; i <= 9; i++)
        if (!(map[i] = malloc(19)))
            return (NULL);
    map[10] = NULL;
    fill_string(" |A B C D E F G H\n", map[0]);
    fill_string("-+---------------\n", map[1]);
    for (int i = 2; i <= 9; i++)
        fill_string("1|. . . . . . . .\n", map[i]);
    for (int i = 2; i <= 9; i++)
            map[i][0] = '1' + i - 2;
    return (map);
}

int put_boat(char **map, char *str)
{
    int y = (str[3] - 48) + 1;
    int x = (str[2] - 64) * 2;
    int a = 0;

    if (str[2] < str[5])
        for (int i = 0; i < str[0] - 48; i++, a +=  2) {
            if (map[y][x + a] != '.')
                return (84);
            map[y][x + a] = str[0];
        }
    if (str[3] < str[6])
        for (int i = 0; i < str[0] - 48; i++) {
            if ( map[y + i][x] != '.')
                return (84);
            map[y + i][x] = str[0];
        }
    return (0);
}

int readpos(char *file, char **map)
{
    char buffer[9];
    int fd;

    fd = open(file, O_RDONLY);
    if (fd == -1) {
        write(2,"Error with open", 15);
        return (84);
    }
    for (int i = 0; i < 4; i++) {
        read(fd, buffer, 8);
        if (check_pos(buffer) == 84)
            return (84);
        if (84 == put_boat(map, buffer))
            return (84);
    }
    close(fd);
    return (0);
}

void draw_map(char **map, char **e_map)
{
    my_putstr("\nmy positions:\n");
    for (int i = 0; map[i] != NULL; i++)
        my_putstr(map[i]);
    my_putstr("\nenemy's positions:\n");
    for (int i = 0; e_map[i] != NULL; i++)
        my_putstr(e_map[i]);
}