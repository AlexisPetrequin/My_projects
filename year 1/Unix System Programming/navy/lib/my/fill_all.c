/*
** EPITECH PROJECT, 2020
** fill_all
** File description:
** functions about filling struct
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

clock_v *fill_clock(void)
{
    clock_v *clock = malloc(sizeof(clock_v));

    clock->rem = malloc(sizeof(struct timespec));
    clock->req = malloc(sizeof(struct timespec));
}

game_v *fill_game(void)
{
    game_v *game = malloc(sizeof(game_v));

    gb = 0;
    game->pid = 0;
    game->clock = fill_clock();
    game->e_map = map_create();
    game->map = map_create();
        if (game == NULL || game->clock == NULL || game->clock->rem == NULL ||
        game->clock->req == NULL || game->e_map == NULL ||
        game->map == NULL)
        gb = 10;
    for (int i = 0; i < 10; i++)
        if (game->e_map[i] == NULL || game->map [i] == NULL)
            gb = 10;
    return (game);
}

void free_game(game_v *game)
{
    for (int i = 0; i <= 10; i++) {
        free(game->map[i]);
        free(game->e_map[i]);
    }
    free(game->map);
    free(game->e_map);
    free(game->clock->rem);
    free(game->clock->req);
    free(game->clock);
    free(game);
}

int print_h(void)
{
    my_putstr("USAGE\n     ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n     first_player_pid: only for the 2nd player.");
    my_putstr("pid of the first player.\n     navy_positions: ");
    my_putstr("file representing the positions of the ships.\n");
    return (0);
}

int check_pos(char *str)
{
    static int a[5] = { 0 };
    int y = 0;

    if (str[0] <= '1' || str[0] >= '6' || str[3] <= '0' || str[3] >= '9' ||
    str[6] <= '0' || str[6] >= '9' || str[2] < 'A' || str[2] > 'H' ||
    str[5] < 'A' || str[5] > 'H')
        return (84);
    if ((str[3] != str[6] && str[2] != str[5]) ||
    (str[3] == str[6] && str[2] == str[5]))
        return (84);
    if ((str[0] - 48 - 1) != (str[5] - 64 - (str[2] - 64)) &&
    ((str[0] - 48 - 1) != (str[6] - 48 - (str[3] - 48))))
        return (84);
    for (y = 0; a[y] != 0; y++)
        if (str[0] - 48 == a[y])
            return (84);
    a[y] = str[0] - 48;
    return (0);
}