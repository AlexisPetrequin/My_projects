/*
** EPITECH PROJECT, 2019
** mylist
** File description:
** include
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <features.h>
#include <fcntl.h>
#include <sys/stat.h>
#ifndef MYLIST_H_
#define mylist_h_

int gb;
typedef struct clock_s {
    struct timespec *req;
    struct timespec *rem;
} clock_v;
typedef struct game_s {
    char **e_map;
    char **map;
    clock_v *clock;
    int pid;
    int win;
} game_v;

int my_getnbr(char const *str);
void my_putchar(char c);
int my_putnbr(long nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
void print(long nb);
char *my_strcat(char *dest, char const *src);
void fill_string(char *src, char *cp);
char **map_create(void);
int put_boat(char **map, char *str);
int readpos(char *file, char **map);
int connection_p2(clock_v *clock, int pide);
int connection_p1(clock_v *clock, game_v *game);
clock_v *fill_clock(void);
game_v *fill_game(void);
void free_game(game_v *game);
int send_sign(int nb, int pid);
void hit(game_v *game, int coord1, int coord2);
int recept_attack(void);
char *attack(game_v *game);
void draw_map(char **map, char **e_map);
int check_pos(char *str);
int print_h(void);
int check_win(game_v *game);
int check_lose(game_v *game);
void attack_result(char **map, char *coord);
int end_game(char *coord, int end);
void count_signal(int i, siginfo_t *siginfo, void *a);
#endif