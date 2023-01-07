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
#include "include/mylist.h"
#include <time.h>
#include <features.h>
#include <fcntl.h>
#include <sys/stat.h>

void count_signal(int i, siginfo_t *siginfo, void *a)
{
    static int j = 0;

    if (i == 10) {
        j += 1;
    }
    if (i == 12) {
        gb = j;
        j = 0;
    }
}

void attacked(int i, siginfo_t *siginfo, void *a)
{
    if (i == 10)
        gb = 1;
    if (i == 12)
        gb = 2;
}

int player_one(game_v *game, char **argv)
{
    int coord1 = 0;
    int coord2 = 0;
    char *coord = malloc(4);

    if (connection_p1(game->clock, game) == 1 || !coord)
        return (84);
    while (game->win == 0) {
        draw_map(game->map, game->e_map);
        coord = attack(game);
        if (coord[0] == '1')
            return (84);
        attack_result(game->e_map, coord);
        if (check_win(game) == 2)
            return (end_game(coord, 0));
        my_putstr("\nwaiting for enemy's attack...\n");
        coord1 = recept_attack();
        coord2 = recept_attack();
        hit(game, coord1, coord2);
        if (check_lose(game) == 1)
            return (end_game(coord, 1));
    }
}

int player_two(game_v *game, char** argv)
{
    int coord1 = 0;
    int coord2 = 0;
    char *coord = malloc(4);

    if (connection_p2(game->clock, my_getnbr(argv[1])) == 1)
        return (84);
    while (game->win == 0) {
        draw_map(game->map, game->e_map);
        my_putstr("\nwaiting for enemy's attack...\n");
        coord1 = recept_attack();
        coord2 = recept_attack();
        hit(game, coord1, coord2);
        if (check_lose(game) == 1)
            return (end_game(coord, 1));
        coord = attack(game);
        if (coord[0] == '1')
            return (84);
        attack_result(game->e_map, coord);
        if (check_win(game) == 2)
            return (end_game(coord, 0));
    }
}

int main(int argc, char **argv)
{
    game_v *game = fill_game();
    int win = 0;

    if ((argc != 2 && argc != 3) || gb == 10)
        return (84);
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
        return (print_h());
    if (argc == 2) {
        if (readpos(argv[1], game->map) == 84)
            return (84);
        win = player_one(game, argv);
    }
    if (argc == 3) {
        game->pid = my_getnbr(argv[1]);
        if (readpos(argv[2], game->map) == 84)
            return (84);
        win = player_two(game, argv);
    }
    free_game(game);
    return (win);
}