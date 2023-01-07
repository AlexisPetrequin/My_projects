/*
** EPITECH PROJECT, 2019
** calc
** File description:
** 
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "include/my.h"

int angle(float hypothenuse, float adjacent)
{
    float rescos;
    float radangle;
    float angle;

    rescos = adjacent / hypothenuse;
    radangle = acos(rescos);
    angle = (((radangle * 360) / (2 * M_PI)));
    printf("The incidence angle is:\n");
    display_number(angle);
    printf(" degrees\n");
}

int len_vector(float x, float y, float z, float x2, float y2, float z2)
{
    float res;
    float res2;
    float t = 2;
    
    res = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    res2 = sqrt(pow(x2, 2) + pow(y2, 2) + pow(z2, 2));
    angle(res, res2);
    return(0);
}

float coord(float a, float b)
{
    float res;
    res = b - a;
    return(res);
}

int print_coord(float xa, float ya, float za, float xb, float yb, float zb, int t)
{
    float xc = xa;
    float yc = ya;
    float zc = 0;
    
    float xd = xb;
    float yd = yb;
    float zd = 0;

    float x;
    float y;
    float z;
    float x2;
    float y2;
    float z2;
    float x3;
    float y3;
    float z3;
    float xt;
    float yt;
    float zt;
    
    x = coord(xa, xb);
    y = coord(ya, yb);
    z = coord(za, zb);

    my_putstr("The velocity vector of the ball is:\n(");
    display_number(x);
    my_putstr(", ");
    display_number(y);
    my_putstr(", ");
    display_number(z);
    my_putstr(")\n");

    x2 = coord(xc, xd);
    y2 = coord(yc, yd);
    z2 = coord(zc, zd);
    
    xt = xb + t * x;
    yt = yb + t * y;
    zt = zb + t * z;
    printf("At time t + %i, ball coordinates will be:\n", t);
    my_putstr("(");
    display_number(xt);
    my_putstr(", ");
    display_number(yt);
    my_putstr(", ");
    display_number(zt);
    my_putstr(")\n");
    
    if ((za > 0 && zb > 0 && zb > za) || (za < 0 && zb < 0 && zb < za) || (zb == za && za != 0) || (za > 0 && zt < 0) || (za < 0 && zt > 0)) {
        printf("The ball won't reach the paddle.\n");
        return;
    }
    len_vector(x, y, z, x2, y2, z2);
    return (0);
}

void main(int ac, char ** av)
{
    print_coord(atof(av[1]), atof(av[2]), atof(av[3]), atof(av[4]), atof(av[5]), atof(av[6]), atof(av[7]));
}
