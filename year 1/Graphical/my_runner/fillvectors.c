/*
** EPITECH PROJECT, 2019
**
** File description:
**
*/

#include <SFML/Graphics.h>
#include "struct.h"
#include <stdlib.h>

rect createrect(rect rectangles)
{
    rectangles.perso.height = 256;
    rectangles.perso.left = 0;
    rectangles.perso.top = 0;
    rectangles.perso.width = 256;
    rectangles.sol.height = 100;
    rectangles.sol.left = 0;
    rectangles.sol.top = 90;
    rectangles.sol.width = 200;
    return (rectangles);
}

void full(create **background)
{
    background[0]->sprite = sfSprite_create();
    background[0]->texture = sfTexture_createFromFile("fond.jpg", NULL);
    background[1]->sprite = sfSprite_create();
    background[1]->texture = sfTexture_createFromFile("fond.jpg", NULL);
    background[2]->sprite = sfSprite_create();
    background[2]->texture = sfTexture_createFromFile("fond1.png", NULL);
    background[3]->sprite = sfSprite_create();
    background[3]->texture = sfTexture_createFromFile("fond1.png", NULL);
    background[4]->sprite = sfSprite_create();
    background[4]->texture = sfTexture_createFromFile("sol1.jpg", NULL);
    background[5]->sprite = sfSprite_create();
    background[5]->texture = sfTexture_createFromFile("sol1.jpg", NULL);
    background[6]->sprite = sfSprite_create();
    background[6]->texture = sfTexture_createFromFile("sol1.jpg", NULL);
    background[7]->sprite = sfSprite_create();
    background[7]->texture = sfTexture_createFromFile("sol1.jpg", NULL);
    background[8]->sprite = sfSprite_create();
    background[8]->texture = sfTexture_createFromFile("sol1.jpg", NULL);
    background[9]->sprite = sfSprite_create();
    background[9]->texture = sfTexture_createFromFile("sprite1.png", NULL);
    background[10]->sprite = sfSprite_create();
}

void puttin(create **background, createclock *clock)
{
    for (int i = 0; i <= 10 ; ++i)
        background[i] = malloc(sizeof(create*));
    clock->clock = sfClock_create();
    clock->clock2 = sfClock_create();
}

createvector fillvectorsx(createvector vectors)
{
    vectors.mid_scale.x = 0.5;
    vectors.fond_scale.x = 1.2;
    vectors.perso_scale.x = 0.5;
    vectors.pos_sol1.x = 0;
    vectors.pos_sol2.x = 200;
    vectors.pos_sol3.x = 400;
    vectors.pos_sol4.x = 600;
    vectors.pos_sol5.x = 800;
    vectors.pos_mid.x = 0;
    vectors.pos_mid2.x = 800;
    vectors.pos_fond2.x = 835;
    vectors.pos_perso.x = 100;
    vectors.move_sol.x = -8;
    vectors.move_mid.x = -5;
    vectors.move_fond.x = -2;
    vectors.jump.x = 0;
    return (vectors);
}

createvector fillvectorsy(createvector vectors)
{
    vectors.mid_scale.y = 0.5;
    vectors.fond_scale.y = 1.2;
    vectors.perso_scale.y = 0.5;
    vectors.pos_sol1.y = 500;
    vectors.pos_sol2.y = 500;
    vectors.pos_sol3.y = 500;
    vectors.pos_sol4.y = 500;
    vectors.pos_sol5.y = 500;
    vectors.pos_mid.y = 190;
    vectors.pos_mid2.y = 190;
    vectors.pos_fond2.y = 0;
    vectors.pos_perso.y = 375;
    vectors.move_sol.y = 0;
    vectors.move_mid.y = 0;
    vectors.move_fond.y = 0;
    vectors.jump.y = -0.01;
    return (vectors);
}