/*
** EPITECH PROJECT, 2021
** iq
** File description:
** iq.cpp
*/

#include "iq.hpp"

IQ::IQ(int u, int o): _u(u), _o(o)
{
    _mode = IQ::ZERO_B;
}

IQ::IQ(int u, int o, int max): _u(u), _o(o), _max(max)
{
    _mode = IQ::ONE_B;
}

IQ::IQ(int u, int o, int min, int max): _u(u), _o(o), _min(min), _max(max)
{
    _mode = IQ::TWO_B;
}

IQ::~IQ()
{
}

void IQ::calc()
{
    for (int i = 0; i < 201; ++i) {
        double rez = (1 / ((double)_o * sqrt(2 * M_PI))) * exp(-0.5 * pow(((double)i - (double)_u) / (double)_o, 2));
        _map[i] = rez * 100;
    }
}

void IQ::print()
{
    int i;
    double n;

    if (_mode == IQ::ZERO_B) {
        std::cout << std::setprecision(2) << std::fixed;
        i = 0;
        for (; i < 201; ++i)
            std::cout << i << " " << _map[i] << std::endl;
    } else if (_mode == IQ::ONE_B) {
        std::cout << std::setprecision(1) << std::fixed;
        i = 0;
        n = 0;
        for (; i < _max; ++i)
            n += _map[i];
        std::cout << (double)n << "% of people have an IQ inferior to " << _max << std::endl;
    } else {
        std::cout << std::setprecision(1) << std::fixed;
        i = _min;
        n = 0;
        for (; i < _max; ++i)
            n += _map[i];
        std::cout << (double)n << "% of people have an IQ between " << _min << " and " << _max << std::endl;
    }
}
