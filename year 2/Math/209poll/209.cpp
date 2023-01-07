/*
** EPITECH PROJECT, 2021
** B-MAT-400-STG-4-1-209poll-alexis.petrequin
** File description:
** 209
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>

void usage ()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t/209poll pSize sSize p" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tpSize   size of the population" << std::endl;
    std::cout << "\tsSize   size of the sample (supposed to be representative)" << std::endl;
    std::cout << "\tp       percentage of voting intentions for a specific candidate" << std::endl;
}

double check_min(double sample) {
    if (sample < 0) {
        return (0);
    } else {
        return (sample);
    }
}

double check_max(double sample) {
    if (sample > 100) {
        return (100);
    } else {
        return (sample);
    }
}

int main(int ac, char **av)
{
    if (ac != 4) {
        usage();
        return (84);
    } else if (av[1] == "-h" || av[1] == "-help") {
        usage();
        return (0);
    } else {
        double pop = atof(av[1]);
        double sample = atof(av[2]);
        double poll = atof(av[3]);
        double var = 0;
        double temp1 = 0;
        double temp2 = 0;
        pop = round(pop);
        sample = round(sample);
        if (pop <= 0) {
            std::cout << "Population size must be higher than zero" << std::endl;
            return (84);
        } else if (sample >= pop or sample <= 0) {
            std::cout << "Sample size must be lower than population size and higher than zero" << std::endl;
            return (84);
        } else if (poll < 0 or poll > 100) {
            std::cout << "Poll result cannot be under 0% or upper 100%" << std::endl;
            return (84);
        } else if (pop - 1 < 0) {
            std::cout << "Division by zero" << std::endl;
            return (84);
        } else {
            double poll2 = poll / 100;
            var = ((poll2 * (1 - poll2)) / sample) * ((pop - sample) / (pop - 1));
            temp1 = (2 * 1.96 * sqrt(var)) / 2 * 100;
            temp2 = (2 * 2.58 * sqrt(var)) / 2 * 100;
            std::cout << "Population size:\t " << pop << std::endl;
            std::cout << "Sample size:\t\t " << sample << std::endl;
            std::cout << "Voting intentions:\t " << poll << "%" << std::endl;
            std::cout << std::setprecision(6) << std::fixed;
            std::cout << "Variance:\t\t " << var << std::endl;
            double rez1 = check_min(poll - temp1);
            double rez2 = check_max(poll + temp1);
            double rez3 = check_min(poll - temp2);
            double rez4 = check_max(poll + temp2);
            std::cout << std::setprecision(2) << std::fixed;
            std::cout << "95\% confidence interval: " << "[" << rez1 << "%; " << rez2 << "%]" << std::endl;
            std::cout << "99\% confidence interval: " << "[" << rez3 << "%; " << rez4 << "%]" << std::endl;
            return (0);
        }
    }
    return (0);
}
