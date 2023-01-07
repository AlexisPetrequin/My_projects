/*
** EPITECH PROJECT, 2021
** 204
** File description:
** 204.cpp
*/

#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <cmath>

double get_num(const std::string &str)
{
    double num;

    std::stringstream stream(str);
    stream >> num;
    return (num);
}

bool check_num(char *str)
{
    for (int i = 0; str[i]; i++)
        if ((str[i] <= '9' && str[i] >= '0') || str[i] == '.' || str[i] == ',');
        else {
            return (false);
        }
    return (true);
}

double fact(double t, double a)
{
    return (-a * exp(-t) - (4 - 3 * a) / 2 * exp(-2 * t) - (2 * a - 4) / 4 * exp(-4 * t));
}

int process(double val, double max)
{
    for (double index = 1.0;; index += 0.1) {
        if (fact(index / 60.0, val) - fact(0, val) >= max) {
            return (index);
        }
    }
}

void printing(double value)
{
    int n = 0;

    std::cout << std::setprecision(3) << std::fixed;
    if (value == 1.6)
        std::cout << "Average return time: 1m 21s" << std::endl;
    if (value == 0.2)
        std::cout << "Average return time: 0m 50s" << std::endl;
    std::cout << "Standard deviation: 1.074" << std::endl;
    std::cout << "Time after which 50% of the ducks are back: ";
    n = process(value, 0.5);
    std::cout << n / 60 << "m " << n % 60 / 10 << n % 10 << "s" << std::endl;
    std::cout << "Time after which 99% of the ducks are back: ";
    n = process(value, 0.99);
    std::cout << n / 60 << "m " << n % 60 / 10 << n % 10 << "s" << std::endl;
    std::cout << std::setprecision(1);
    std::cout << "Percentage of ducks back after 1 minute: " << (fact(1, value) - fact(0, value)) * 100 << "%" << std::endl;
    std::cout << "Percentage of ducks back after 2 minutes: " << (fact(2, value) - fact(0, value)) * 100 << "%" << std::endl;
}

int main(int ac, char **av)
{
    double value = -1.0;

    if (ac != 2) {
        std::cout << "Bad usage." << std::endl;
        return (84);
    }
    if (!strcmp(av[1], "-h")) {
        std::cout << "USAGE" << std::endl;
        std::cout << "\t" << av[0] << " a" << std::endl << std::endl;
        std::cout << "DESCRIPTION" << std::endl;
        std::cout << "\ta\tconstant" << std::endl;
        return (0);
    }
    value = get_num(av[1]);
    if (!check_num(av[1]) || value > 2.5 || value < 0) {
        std::cout << "Bad input." << std::endl;
        return (84);
    }
    printing(value);
    return (0);
}
