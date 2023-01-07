/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.cpp
*/

#include "iq.hpp"

int my_atoi(char *str)
{
    for (int i = 0; str[i]; ++i) {
        if (str[i] < '0' || str[i] > '9') {
            std::cerr << "Invalid number : " << str << std::endl;
            exit(84);
        }
    }
    return (atoi(str));
}

int usage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t\t./205IQ µ σ [IQ1] [IQ2]" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\t\tµ\tpredetermined mean" << std::endl;
    std::cout << "\t\tσ\tpredetermined standard deviation" << std::endl;
    std::cout << "\t\tIQ1\tminimum IQ" << std::endl;
    std::cout << "\t\tIQ2\tmaximum IQ" << std::endl;
    return (0);
}

int main(int ac, char **av)
{
    for (int i = 1; i < ac; ++i)
        if (std::string("-h") == av[i])
            return (usage());
    if (ac == 3) {
        int u = my_atoi(av[1]);
        int o = my_atoi(av[2]);
        IQ iq(u, o);
        iq.calc();
        iq.print();
    } else if (ac == 4) {
        int u = my_atoi(av[1]);
        int o = my_atoi(av[2]);
        int max = my_atoi(av[3]);
        if (max > 200)
            return (84);
        IQ iq(u, o, max);
        iq.calc();
        iq.print();
    } else if (ac == 5) {
        int u = my_atoi(av[1]);
        int o = my_atoi(av[2]);
        int min = my_atoi(av[3]);
        int max = my_atoi(av[4]);
        if (min < 0 || min > 200|| max > 200 || min > max)
            return (84);
        IQ iq(u, o, min, max);
        iq.calc();
        iq.print();
    } else {
        std::cerr << "Error in args." << std::endl;
        return (84);
    }
    return (0);
}
