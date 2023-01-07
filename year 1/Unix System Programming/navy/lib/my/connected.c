/*
** EPITECH PROJECT, 2020
** connected
** File description:
** functions about connections of players
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
#include "../../include/mylist.h"

void connection(int i, siginfo_t *siginfo, void *a)
{
    if (i == 12) {
        my_putstr("\nenemy connected\n");
        gb = siginfo->si_pid;
        usleep(1000);
        if (kill(siginfo->si_pid, 10) == -1)
            my_putstr("\nsignal send fail\n");
    }
    if (i == 10)
        my_putstr("\nsuccesfully connected\n");
}

int connection_p2(clock_v *clock, int pide)
{
    struct sigaction sa;
    sigset_t clean;

    clock->req->tv_sec = 30;
    sa.sa_sigaction = &connection;
    sa.sa_flags = SA_SIGINFO;
    my_putstr("my_pid:  ");
    my_putnbr(getpid());
    usleep(1000);
    if (kill(pide, 12) == -1) {
        my_putstr("\nconnection failed\n");
        return (1);
    }
    sigaction(10, &sa, NULL);
    if (nanosleep(clock->req, clock->rem) == 0) {
        my_putstr("\nconnection failed\n");
        return (1);
    }
    sigemptyset(&clean);
    return (0);
}

int connection_p1(clock_v *clock, game_v *game)
{
    struct sigaction sa;
    sigset_t clean;

    clock->req->tv_sec = 30;
    sa.sa_sigaction = &connection;
    sa.sa_flags = SA_SIGINFO;
    my_putstr("my_pid:  ");
    my_putnbr(getpid());
    my_putstr("\nwaiting for ennemy connection...\n");
    sigaction(12, &sa, NULL);
    if (nanosleep(clock->req, clock->rem) == 0) {
        my_putstr("\nconnection failed\n");
        return (1);
    }
    sigemptyset(&clean);
    game->pid = gb;
    gb = 0;
    return (0);
}

int end_game(char *coord, int end)
{
    free(coord);
    return (end);
}