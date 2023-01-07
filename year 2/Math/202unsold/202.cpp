/*
** EPITECH PROJECT, 2021
** 202
** File description:
** 202.cpp
*/

#include <math.h>
#include <iostream>
#include <string>
#include <iomanip>

class Array {
    public:
    Array(int c, int d);
    ~Array() {};
    double **array;
    int a;
    int b;
};

Array::Array(int c, int d) : a(c), b(d)
{
    int x = 10;
    int y = 10;

    this->array = (double**)malloc(sizeof(double *) * 6);
    for (int i = 0; i < 6; ++i)
        this->array[i] = (double*)malloc(sizeof(double) * 6);
    for (int i = 0; i < 5; ++i, x += 10, y += 10) {
        this->array[5][i] = ((this->a - x) / (double)(5 * this->a - 150));
        this->array[i][5] = ((this->b - y) / (double)(5 * this->b - 150));
    }
    for (int ibis = 0; ibis < 5; ++ibis)
        for (int i = 0; i < 5; ++i)
            this->array[ibis][i] = this->array[5][i] * this->array[ibis][5];
    this->array[5][5] = 1.000;
}

double error(int ac, char **av)
{
    if (ac != 3)
        return (0);
    if (atoi(av[1]) <= 50 || atoi(av[2]) <= 50)
        return (0);
    return (1);
}

int main(int ac, char **av)
{
    int y = 10;
    double z2 = 0;
    double x = 0;
    double x2 = 0;
    double z = 0;

    if (error(ac, av) == 0)
        return (84);
    Array array(atoi(av[1]), atoi(av[2]));
    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
    std::cout << "         X=10     X=20     X=30     X=40     X=50     Y law";
    for (int ibis = 0; ibis < 6; ++ibis, y += 10) {
        std::cout << std::endl;
        if (ibis < 5)
            std::cout << "Y=" << y << "     ";
        else
            std::cout << "X law    ";
        for (int i = 0; i < 6; i++)
        std::cout << std::fixed << std::setprecision(3) << array.array[ibis][i] << "    ";
    }
    std::cout << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
    std::cout << "z        20       30       40       50       60       70       80       90       100" << std::endl;
    std::cout << "p(Z=z)   " <<
    array.array[0][0] << "    " <<
    array.array[0][1] + array.array[1][0] << "    " <<
    array.array[2][0] + array.array[1][1] + array.array[0][2] << "    " <<
    array.array[3][0] + array.array[2][1] + array.array[1][2] + array.array[0][3] << "    " <<
    array.array[4][0] + array.array[3][1] + array.array[2][2] + array.array[1][3]+ array.array[0][4] << "    " <<
    array.array[4][1] + array.array[3][2] + array.array[2][3] + array.array[1][4] << "    " <<
    array.array[4][2] + array.array[3][3] + array.array[2][4] << "    " <<
    array.array[4][3] + array.array[3][4] << "    " <<
    array.array[4][4] << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
    y = 10;
    for (int i = 0; i < 5 ; ++i, y += 10)
        x += array.array[5][i] * y;
    std::cout << std::fixed << std::setprecision(1) << "expected value of X:      " << x << std::endl;
    y = 10;
    for (int i = 0; i < 5; ++i, y += 10)
        x2 += (array.array[5][i] * pow((y - x), 2));
    std::cout << std::fixed << std::setprecision(1) << "variance of X:            " << x2 << std::endl;
    y = 10;
    for (int i = 0; i < 5 ; ++i, y += 10)
        z += array.array[i][5] * y;
    std::cout << std::fixed << std::setprecision(1) << "expected value of Y:      " << z << std::endl;
    y = 10;
    for (int i = 0; i < 5; ++i, y += 10)
        z2 += (array.array[i][5] * pow((y - z), 2));
    std::cout << std::fixed << std::setprecision(1) << "variance of Y:            " << z2 << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "expected value of Z:      " << x + z << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "variance of Z:            " << z2 + x2 << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
    return (0);
}