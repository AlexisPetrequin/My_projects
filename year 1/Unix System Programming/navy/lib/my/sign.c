/*
** EPITECH PROJECT, 2020
** signs
** File description:
** about signal
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

int send_sign(int nb, int pid)
{
    for (int i = 0; i < nb; i++) {
        usleep(1000);
        if (kill(pid, SIGUSR1) == -1)
            return (1);
    }
    usleep(1000);
    if (kill(pid, SIGUSR2) == -1)
        return (1);
    return (0);
}

int check_win(game_v *game)
{
    int result = 0;

    result = recept_attack();
    if (result == 2) {
        draw_map(game->map, game->e_map);
        my_putstr("\nI won\n\n");
        return (2);
    }
    return (0);
}

int check_lose(game_v *game)
{
    for (int i = 2; i <= 9; i++)
        for (int y = 2; y <= 16; y += 2) {
            if (game->map[i][y] >= '1' && game->map[i][y] <= '9') {
                send_sign(1, game->pid);
                return (0);
            }
        }
    send_sign(2, game->pid);
    my_putstr("\nEnemy won\n\n");
    return (1);
}