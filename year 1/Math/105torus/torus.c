#include <math.h>
#include <stdio.h>

double deriv(double d, double c, double b, double a, double x)
{
    double rez = 4 * a * pow(x, 3) + 3 * b * pow(x, 2) + 2 * c * x + d;
    return(rez);
}

double fonction(double e, double d, double c, double b, double a, double m)
{
    double rez = (a * pow(m, 4)) + (b * pow(m, 3)) + (c * pow(m, 2)) + (m * d) + e;
    return(rez);
}

double check(double x, double y, double n)
{
    double rez = x - y;
    if (rez < pow(10, (-n))) {
        return (1);
    }
    else
        return (2);
}

double bisection(double a, double b, double c, double d, double e, double n, double x, double y, int i)
{
    double m = (x + y) / 2;
    double rez = fonction(a, b, c, d, e, m);
    double rezx = fonction(a, b, c, d, e, x);
    double rezy = fonction(a, b, c, d, e, y);

    printf("x = %.*f\n", i, m);
    if (rez > 0) {
        if (rezx > rezy)
            x = m;
        else
            y = m;
    } else {
        if (rezx < rezy)
            x = m;
        else
            y = m;
    }
    if (i < n)
        ++i;
    if (x > y) {
        if(check(x, y, n) == 1) {
            return (rez);
        } else {
            rez = bisection(a, b, c, d, e, n, x, y, i);
        }
    } else {
        if(check(y, x, n) == 1) {
            return (rez);
        } else {
            rez = bisection(a, b, c, d, e, n, x, y, i);
        }
    }
}

double newton(double a, double b, double c, double d, double e, double n, double x, int i)
{
    double f = fonction(a, b, c, d, e, x);
    double der = deriv(b, c, d, e, x);
    double x0 = x;
    double rez;

    printf("x = %.*f\n", i ,x);
    x = x0 - (f / der);
    if (i == 1)
        i = n;
    if (x0 > x)
        rez = x0 - x;
    else
        rez = x - x0;
    if (rez > pow(10 ,(-n)))
        x = newton(a, b, c, d, e, n, x, i);
}

//double secante(double a, double b, double c, double d, double e, double n, double x, double xn)
//{
//    double f = fonction(a, b, c, d, e, x);
//    double rez;

//    printf("x =  %.12lf\n", x);

//}


int main(int ac, char **av)
{
    double x = 0;
    double y = 1;

    if (number(av[1]) == 1)
        bisection(number(av[2]), number(av[3]), number(av[4]), number(av[5]), number(av[6]), number(av[7]), x, y, 1);
    if (number(av[1]) == 2)
        newton(number(av[2]), number(av[3]), number(av[4]), number(av[5]), number(av[6]), number(av[7]), 0.5, 1);
    //if (number(av[1]) == 3)
    //    secante(number(av[2]), number(av[3]), number(av[4]), number(av[5]), number(av[6]), number(av[7]), 0.5, y);
}