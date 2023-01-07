/*
** EPITECH PROJECT, 2021
** 203
** File description:
** 203.hpp
*/

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>

#ifndef HOTLINE_HH_
# define HOTLINE_HH_

class Hotline
{
  public:
    Hotline(int, int);
    Hotline(int);
    ~Hotline();
    int Calc_bino();
    int Calc_poisson();
    int Calc_combi();
  private:
    int n;
    int k;
    int d;
};

#endif /* !HOTLINE_HH_ */
