/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.cpp
*/

#include "groundhog.hpp"

int main (int argc, char **argv)
{
    Groundhog groundhog;

    if (argc != 2) {
        std::cout << "SYNOPSIS\n\t./groundhog period\nDESCRIPTION\n\tperiod the number of days defining a period" << std::endl;
        return (84);
    }
    if (!std::strcmp("-h", argv[1])) {
        std::cout << "SYNOPSIS\n\t./groundhog period\nDESCRIPTION\n\tperiod the number of days defining a period" << std::endl;
        return (0);
    }
    if (std::atoi(argv[1]) < 1) {
        std::cout << "SYNOPSIS\n\t./groundhog period\nDESCRIPTION\n\tperiod the number of days defining a period" << std::endl;
        return (84);
    }
    return (groundhog.main(std::atoi(argv[1])));
}