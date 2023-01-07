/*
** EPITECH PROJECT, 2021
** 203
** File description:
** 203.cpp
*/

#include "hotline.hpp"

Hotline::Hotline(int n, int k)
{
  this->n = n;
  this->k = k;
}

Hotline::Hotline(int d)
{
  this->d = d;
}

Hotline::~Hotline()
{
}

static void print_int128(unsigned __int128 n)
{
    if (n / 10)
        print_int128(n / 10);
    std::cout << (char)(n % 10 + 48);
}

int Hotline::Calc_combi()
{
    unsigned __int128 c = 1;

    for (int i = 0; i < k; ++i)
        c = c * (n - i) / (i + 1);

    std::cout << k << "-combination of a " << n << " set:" << std::endl;
    print_int128(c);
    std::cout << std::endl;
}

int Hotline::Calc_bino()
{
    std::cout << "Binomial distribution:" << std::endl << std::setprecision(3);
    for (int i = 0; i <= 50; ++i) {
        std::cout << i << " -> ";
        std::cout << (i % 6 == 5 || i == 50 ? "\n" : "\t");
        i++;
    }
    std::cout << "Overload:" << std::endl;
    std::cout << "Computation time:" << std::endl << std::endl;
}

int Hotline::Calc_poisson()
{
    std::cout << "Binomial distribution:" << std::endl << std::setprecision(3);
    for (int i = 0; i <= 50; ++i) {
        std::cout << i << " -> ";
        std::cout << (i % 6 == 5 || i == 50 ? "\n" : "\t");
        i++;
    }
    std::cout << "Overload:" << std::endl;
    std::cout << "Computation time:" << std::endl;
}
