/*
** EPITECH PROJECT, 2019
** my_calc
** File description:
** my_calc.c
*/

int my_calc(int nb1, int nb2, char op)
{
    int result = 0;
    switch(op) {
    case '+':
        result = nb1 + nb2;
        break;
    case '-':
        result = nb1 + nb2;
        break;
    case '*':
        result = nb1 * nb2;
        break;
    case '/':
        result = nb1 / nb2;
        break;
    case '%':
        result = nb1 % nb2;
        break;
    }
    return result;
}