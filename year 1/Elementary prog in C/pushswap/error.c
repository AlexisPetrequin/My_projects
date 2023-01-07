/*
** EPITECH PROJECT, 2019
**
** File description:
**
*/

int error(char *str) {
    for (int k = 0; str[k] != '\0'; k++) {
        if ((str[k] < '0' || str[k] > '9') && str[k] != '-') {
            return (1);
        }
        return (0);
    }
}

int errors(int ac)
{
    if (ac < 2)
        return (1);
    else if (ac == 2) {
        return (2);
    } else {
        return (0);
    }
}

int error_executor(int ac, char **av)
{
    int testerror2 = 0;
    int testerror = 0;

    testerror = errors(ac);
    if (testerror == 1)
        return(84);
    if (testerror == 2)
        return(2);
    for(int a = 1; a != ac; a++)
        testerror2 = error(av[a]);
    if(testerror2 == 1) {
        return(84);
    } else {
        return (1);
    }
}