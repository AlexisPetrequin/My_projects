/*
** EPITECH PROJECT, 2021
** 203
** File description:
** 203.cpp
*/

#include "hotline.hpp"

static bool is_number(char *str)
{
    int i;

    i = 0;
    while (str[i]) {
        if (i == 0 && (str[i] == '-' || str[i] == '+'))
            i++;
        else if (str[i] < '0' || str[i] > '9')
            return (false);
        else
            i++;
    }
    return (true);
}

static int usage(char **av)
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t\t" << av[0] << " [nk | d]" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "n\tn value for the computation of (n k)" << std::endl;
    std::cout << "b\tk value for the computation of (n k)" << std::endl;
    std::cout << "d\taverage duration of calls (in seconds)" << std::endl;
    return (0);
}

static int error_args()
{
    std::cerr << "Error: Bad arguments, please run with -h for help" << std::endl;
    return (84);
}

static int parse(int *args, int n)
{
    if (n == 3)
        if (args[0] <= 0 || args[1] <= 0 || args[1] > args[0])
            return (error_args());
        else {
            Hotline hotline(args[0], args[1]);
            hotline.Calc_combi();
        }
    if (n == 2)
        if (args[0] <= 0)
            return (error_args());
        else {
            Hotline hotline(args[0]);
            hotline.Calc_bino();
            hotline.Calc_poisson();
        }
    return (0);
}

int main(int ac, char **av)
{
    int i;
    int args[2];

    for (i = 1; i < ac; ++i) {
        if (std::string("-h") == av[1])
            return (usage(av));
        if (i > 2 || !is_number(av[i]))
            error_args();
        errno = 0;
        args[i - 1] = atoi(av[i]);
        if (errno == ERANGE)
            error_args();
    }
    if (i != 3 && i != 2)
        error_args();
    return (parse(args, i));
}
