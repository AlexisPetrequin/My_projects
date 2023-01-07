/*
** EPITECH PROJECT, 2021
** neutrios.cpp
** File description:
** neutrios
*/

#include "neutrinos.hpp"

Neutrinos::Neutrinos()
{
        this->dev = 0;
        this->dev0 = 0;
        this->rez = 0;
        this->rez0 = 0;
        this->rez1 = 0;
        this->rez2 = 0;
}

Neutrinos::~Neutrinos()
{
}

int check_arguments(std::string str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9') {
            std::cout << "Error: The arguments must be numbers." << std::endl;
            return (84);
        }
    }
    return (0);
}

int Neutrinos::run(int ac, char **av)
{
    static double i = 0;
    double nbrs[5];
    std::string str;
    std::stringstream str2;

    if (ac != 5) {
        std::cout << "Error: The program needs 4 arguments" << std::endl;
        return (84);
    }
    for (int i = 1; i < ac; i++) {
        if (check_arguments(av[i]) == 84)
            return (84);
        nbrs[i - 1] = atof(av[i]);
    }
    for (; str != "END"; ++i) {
        std::string str;
        std::cout << "enter your value : ";
        std::cin >> str;
        if (str.empty() || str == "END")
            return (0);
        if (check_arguments(str) == 84)
            return (84);
        str2.clear();
        str2.str("");
        str2.str(str);
        str2 >> nbrs[4];
        nbrs[0] += 1.0;
        std::cout << "\tNumber of values:\t" << nbrs[0] << std::endl;
        if (i == 0) {
            this->dev = nbrs[3];
            this->dev = sqrt((((((pow(this->dev, 2) + pow(nbrs[1], 2))) * (nbrs[0] - 1.0)) + pow(nbrs[4], 2)) / nbrs[0]) - pow((((nbrs[1] * (nbrs[0] - 1.0)) + nbrs[4]) / nbrs[0]), 2));
        } else {
            this->dev0 = this->dev;
            this->dev = sqrt((((((pow(this->dev, 2) + pow(this->rez, 2))) * (nbrs[0] - 1.0)) + pow(nbrs[4], 2)) / nbrs[0]) - pow((((this->rez * (nbrs[0] - 1.0)) + nbrs[4]) / nbrs[0]), 2));
        }
        std::cout << "\tStandard deviation:\t" << std::fixed << std::setprecision(2) << this->dev << std::endl;
        if (i == 0)
            this->rez = nbrs[1];
        this->rez0 = this->rez;
        this->rez = ((this->rez * (nbrs[0] - 1.0)) + nbrs[4]) / nbrs[0];
        std::cout << "\tArithmetic mean:\t" << this->rez << std::endl;
        if (i == 0) {
            this->rez1 = nbrs[1];
            this->rez1 = sqrt((((pow(nbrs[3], 2) + pow(this->rez1, 2)) * (nbrs[0] - 1.0)) + pow(nbrs[4], 2)) / nbrs[0]);
        } else
            this->rez1 = sqrt((((pow(this->dev0, 2) + pow(this->rez0, 2)) * (nbrs[0] - 1.0)) + pow(nbrs[4], 2)) / nbrs[0]);
        std::cout << "\tRoot mean square:\t" << this->rez1 << std::endl;
        if (i == 0)
            this->rez2 = nbrs[2];
        if (nbrs[0] == 0 || nbrs[2] == 0)
            std::cout << "\tHarmonic mean:\t\tThe harmonic average cannot be calculated." << std::endl << std::endl;
        else {
            this->rez2 = nbrs[0] / ((1.0 / this->rez2 * (nbrs[0] - 1.0)) + (1.0 / nbrs[4]));
            std::cout << "\tHarmonic mean:\t\t" << this->rez2 << std::endl << std::endl;
        }
    }
    return (0);
}
