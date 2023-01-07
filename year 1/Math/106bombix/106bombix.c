#include "stdlib.h"
#include "stdio.h"

int next_genbunny(double nbrfirstbunny, double rate)
{
    if (nbrfirstbunny > 100 || nbrfirstbunny < 1 || rate > 4 || rate < 1)
        return (1);
    printf("1 %.2f\n", nbrfirstbunny);
    for (int i = 2; i <= 100; ++i) {
        nbrfirstbunny = rate * nbrfirstbunny * ((1000 - nbrfirstbunny) / 1000);
        printf("%i %.2f\n", i, nbrfirstbunny);
    }
}

void genbunny(double nbrfirstbunny, double firstgen, double lastgen)
{
    double rate = 1;
    if (nbrfirstbunny > 100 || nbrfirstbunny < 1)
        return (1);
    while (rate <= 4){
        for (int i = 0; i <= lastgen; ++i) {
            nbrfirstbunny = rate * nbrfirstbunny * ((1000 - nbrfirstbunny) / 1000);
            if (i >= firstgen)
                printf("%.2f %.2f\n", rate, nbrfirstbunny);
        }
        rate += 0.01;
    }
}

int main(int ac, char **av)
{
    if (ac == 3) {
        if (next_genbunny(atof(av[1]), atof(av[2])))
            return (84);
    }
    if (ac == 4)
        genbunny(atof(av[1]), atof(av[2]), atof(av[3]));
    else
        return (84);
    return (0);
}