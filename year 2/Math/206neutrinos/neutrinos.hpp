/*
** EPITECH PROJECT, 2021
** neutrios.hpp
** File description:
** neutrios
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <iomanip>

class Neutrinos {
    public:
        Neutrinos();
        ~Neutrinos();
        int run(int, char **);
    private:
        int _nb_val_rel;
        int _moy_ari;
        int _moy_har;
        int _ecart_type;
        double dev;
        double dev0;
        double rez;
        double rez0;
        double rez1;
        double rez2;
};
