#include "stdlib.h"
#include "stdio.h"

double fonction(char *str, double x)
{
    int i = 0;
    double result = 0;
    for (; str[i + 1] != '\0'; i++);
    for (; i != 0; i -= 2) {
        result *= x;
        result += str[i] - 48;
    }
    return (result * x + (str[i] - 48));
}

double sending(char *avi, char *avj, double x)
{
    double result = 0;
    double result2 = 0;
    double rez = 0;

    result = fonction(avi, x);
    result2 = fonction(avj, x);
    if (result2 == 0)
        exit(0377);
    rez = result / result2;

    return (rez);
}

int main(int ac, char **av)
{
    double rez = 0;
    int i = 1;
    int j = 2;

    if (ac % 2 != 1)
        return (84);

    for (double x = 0; x <= 1.001; x += 0.001) {
        while(j < ac) {
            rez += sending(av[i], av[j], x);
            i += 2;
            j += 2;
        }
        i = 1;
        j = 2;
        printf("%.3f -> %.5f\n", x, rez);
        rez = 0;
    }
}