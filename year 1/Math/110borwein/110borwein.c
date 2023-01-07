#include "stdlib.h"
#include "stdio.h"
#include "math.h"

double midpoint(double n, float lim)
{
    double k = 0.0000000000000000000000000000000000000000000000000000000000001;
    double rez = 0;
    lim += 0.25;

    for(; k <= n; ++k) {
        rez += 0.5 * (sin(lim / (2 * k + 1)) / (lim / (2 * k + 1)));
    }
    return (rez);
}

double trapezoidal(double n, float lim)
{
    double k = 0.0000000000000000000000000000000000000000000000000000000000001;
    double rez = 0;
    double b1 = (sin(lim / (2 * k + 1)) / (lim / (2 * k + 1)));
    double B1 = (sin((lim + 0.5) / (2 * k + 1)) / ((lim + 0.5) / (2 * k + 1)));

    for(; k <= n; ++k)
        rez += ((b1 + B1) / 2) * 0.5;
    return (rez);
}

double simpson(double n, float lim)
{
    double k = 0.0000000000000000000000000000000000000000000000000000000000001;
    double rez = 0;
    double fa = (sin(lim / (2 * k + 1)) / (lim / (2 * k + 1)));
    double fb = (sin((lim + 0.5) / (2 * k + 1)) / ((lim + 0.5) / (2 * k + 1)));
    double c = ((lim + lim + 0.5) / 2);
    double fc = (sin(c / (2 * k + 1)) / (c / (2 * k + 1)));

    for(; k <= n; ++k)
        rez += ((0.5 / 6) * (fa + (4 * fc) + fb));
    return (rez);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    double n = atof(av[1]);
    int i = atoi(av[1]);
    float set = 0.00000000000000000001;
    float lim = set;
    double rezmid = 0;
    double reztrap = 0;
    double rezsim = 0;
    double pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
    double diff = 0;
    double diff1 = 0;
    double diff2 = 0;

    if (n < 0)
        return (84);
    if (i - n != 0)
        return (84);
        for (int i = 0; av[1][i]; ++i)
            if (av[1][i] > '9' || av[1][i] < '0')
                return (84);

    if (n == 0)
        n = 0.0000000001;
    for (; lim < 5000; lim += 0.5)
        rezmid += midpoint(n, lim);
    lim = set;
    diff = pi / 2 - rezmid;
    for (; lim < 5000; lim += 0.5)
        reztrap += trapezoidal(n, lim);
    lim = set;
    diff1 = pi / 2 - reztrap;
    for (; lim < 5000; lim += 0.5)
        rezsim += simpson(n, lim);
    lim = set;
    diff2 = pi / 2 - rezsim;
    printf("Midpoint:\nI%i = %.10f\ndiff = %.10f\n\n", i, rezmid, diff);
    printf("Trapezoidal: \nI%i = %.10f\ndiff = %.10f\n\n", i, reztrap, diff1);
    printf("Simpson: \nI%i = %.10f\ndiff = %.10f\n", i, rezsim, diff2);
    return (0);
}