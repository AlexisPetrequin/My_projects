/*
** EPITECH PROJECT, 2021
** groundhog
** File description:
** groundhog.hpp
*/



#ifndef GROUNDHOG_HPP_
#define GROUNDHOG_HPP_

#include <sys/types.h>
#include <sys/time.h>
#include <err.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <iomanip>
#include <bits/stdc++.h>
#include <numeric>
#include <unistd.h>
#include <poll.h>
#include <cstdio>

class Groundhog {
    public:
        Groundhog(void);
        ~Groundhog(void);
        int main(int);
        void calc(int);
        void calc_temp_inc_av(size_t);
        void calc_relat_temp_evo(size_t);
        void calc_standard_deviation(int);
        void get_weirdest_value();
        void get_five();
        void display(size_t);
    protected:
    private:
        char _input[100];
        std::vector<double> _list;
        std::vector<double> _weirdest_values;
        std::vector<double> _interlimitinf;
        std::vector<double> _interlimitsup;
        std::vector<double> _differences;
        double _g;
        int _last_r;
        int _r;
        double _s;
        int _nb_switch;
};

#endif /* !GROUNDHOG_HPP_ */
