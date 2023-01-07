/*
** EPITECH PROJECT, 2020
** attack
** File description:
** about attacks
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

int check_attack(char *coord)
{
    if (coord[0] >= 'A' && coord[0] <= 'H' &&
    coord[1] >= '1' && coord[1] <= '8')
        return (0);
    my_putstr("wrong position");
    return (1);
}

void hit(game_v *game, int coord1, int coord2)
{
    if (game->map[coord2 + 1][coord1 * 2] >= '1' &&
    game->map[coord2 + 2][coord1 * 2] <= '9') {
        game->map[coord2 + 1][coord1 * 2] = 'x';
        my_putchar(coord1 + 64);
        my_putnbr(coord2);
        my_putstr(": hit\n");
        send_sign(1, game->pid);
    } else {
        game->map[coord2 + 1][coord1 * 2] = 'o';
        my_putchar(coord1 + 64);
        my_putnbr(coord2);
        my_putstr(": missed\n");
        send_sign(2, game->pid);
    }
}

int recept_attack(void)
{
    struct sigaction sa;
    int nb = 0;
    sigset_t clean;

    sa.sa_sigaction = &count_signal;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (gb == 0)
        pause();
    nb = gb;
    sigemptyset(&clean);
    gb = 0;
    return (nb);
}

char *attack(game_v *game)
{
    char *coord = NULL;
    size_t len = 0;

    my_putstr("\nattack: ");
    getline(&coord, &len, stdin);
    if (check_attack(coord) == 1) {
        free(coord);
        return (attack(game));
    }
    if (send_sign(coord[0] - 64, game->pid) == 1) {
        my_putstr("\nsignal send fail\n");
        return ("1");
    }
    if (send_sign(coord[1] - 48, game->pid) == 1) {
        my_putstr("\nsignal send fail\n");
        return ("1");
    }
    return (coord);
}

void attack_result(char **map, char *coord)
{
    int check = 0;

    check = recept_attack();
    while (check == 0)
        pause();
    if (check == 1) {
        map[coord[1] - 48 + 1][(coord[0] -64) * 2] = 'x';
        my_putchar(coord[0]);
        my_putnbr(coord[1] - 48);
        my_putstr(": hit\n");
    }
    if (check == 2) {
        map[coord[1] - 48 + 1][(coord[0] -64) * 2] = 'o';
        my_putchar(coord[0]);
        my_putnbr(coord[1] - 48);
        my_putstr(": missed\n");
    }
}