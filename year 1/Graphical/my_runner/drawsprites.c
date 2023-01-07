/*
** EPITECH PROJECT, 2019
**
** File description:
**
*/

#include <SFML/Graphics.h>
#include "struct.h"
#include <stdlib.h>

void move(create **background, createvector vectors)
{
    sfSprite_move(background[0]->sprite, vectors.move_fond);
    sfSprite_move(background[1]->sprite, vectors.move_fond);
    sfSprite_move(background[2]->sprite, vectors.move_mid);
    sfSprite_move(background[3]->sprite, vectors.move_mid);
    sfSprite_move(background[4]->sprite, vectors.move_sol);
    sfSprite_move(background[5]->sprite, vectors.move_sol);
    sfSprite_move(background[6]->sprite, vectors.move_sol);
    sfSprite_move(background[7]->sprite, vectors.move_sol);
    sfSprite_move(background[8]->sprite, vectors.move_sol);
}

void set_everything(create **background, createvector vectors)
{
    sfSprite_setPosition(background[1]->sprite , vectors.pos_fond2);
    sfSprite_setPosition(background[2]->sprite , vectors.pos_mid);
    sfSprite_setPosition(background[3]->sprite , vectors.pos_mid2);
    sfSprite_setPosition(background[4]->sprite , vectors.pos_sol1);
    sfSprite_setPosition(background[5]->sprite , vectors.pos_sol2);
    sfSprite_setPosition(background[6]->sprite , vectors.pos_sol3);
    sfSprite_setPosition(background[7]->sprite , vectors.pos_sol4);
    sfSprite_setPosition(background[8]->sprite , vectors.pos_sol5);
    sfSprite_setPosition(background[9]->sprite , vectors.pos_perso);
    sfSprite_setScale(background[0]->sprite , vectors.fond_scale);
    sfSprite_setScale(background[1]->sprite , vectors.fond_scale);
    sfSprite_setScale(background[2]->sprite , vectors.mid_scale);
    sfSprite_setScale(background[3]->sprite , vectors.mid_scale);
    sfSprite_setScale(background[9]->sprite , vectors.perso_scale);
}

void drawsprites(sfRenderWindow *window, create **background)
{
    for (int i = 0; i <= 10; ++i)
        sfRenderWindow_drawSprite(window, background[i]->sprite, NULL);
}

void settextures(create **background, rect rectangles)
{
    sfSprite_setTexture(background[0]->sprite, background[0]->texture, sfTrue);
    sfSprite_setTexture(background[1]->sprite, background[1]->texture, sfTrue);
    sfSprite_setTexture(background[2]->sprite, background[2]->texture, sfTrue);
    sfSprite_setTexture(background[3]->sprite, background[3]->texture, sfTrue);
    sfSprite_setTexture(background[4]->sprite, background[4]->texture, sfTrue);
    sfSprite_setTexture(background[5]->sprite, background[5]->texture, sfTrue);
    sfSprite_setTexture(background[6]->sprite, background[6]->texture, sfTrue);
    sfSprite_setTexture(background[7]->sprite, background[7]->texture, sfTrue);
    sfSprite_setTexture(background[8]->sprite, background[8]->texture, sfTrue);
    sfSprite_setTexture(background[9]->sprite, background[9]->texture, sfTrue);
    sfSprite_setTexture(background[10]->sprite, background[10]->texture, sfTrue);
    sfSprite_setTextureRect(background[4]->sprite, rectangles.sol);
    sfSprite_setTextureRect(background[5]->sprite, rectangles.sol);
    sfSprite_setTextureRect(background[6]->sprite, rectangles.sol);
    sfSprite_setTextureRect(background[7]->sprite, rectangles.sol);
    sfSprite_setTextureRect(background[8]->sprite, rectangles.sol);
    sfSprite_setTextureRect(background[9]->sprite, rectangles.perso);
}

void checktest(create **background, createvector vectors)
{
    if (sfSprite_getPosition(background[0]->sprite).x < -835)
        sfSprite_setPosition(background[0]->sprite, vectors.pos_fond2);
    if (sfSprite_getPosition(background[1]->sprite).x < -835)
        sfSprite_setPosition(background[1]->sprite, vectors.pos_fond2);
    if (sfSprite_getPosition(background[2]->sprite).x < -1100)
        sfSprite_setPosition(background[2]->sprite, vectors.pos_mid2);
    if (sfSprite_getPosition(background[3]->sprite).x < -1100)
        sfSprite_setPosition(background[3]->sprite, vectors.pos_mid2);
    if (sfSprite_getPosition(background[4]->sprite).x < -195)
        sfSprite_setPosition(background[4]->sprite, vectors.pos_sol5);
    if (sfSprite_getPosition(background[5]->sprite).x < -195)
        sfSprite_setPosition(background[5]->sprite, vectors.pos_sol5);
    if (sfSprite_getPosition(background[6]->sprite).x < -195)
        sfSprite_setPosition(background[6]->sprite, vectors.pos_sol5);
    if (sfSprite_getPosition(background[7]->sprite).x < -195)
        sfSprite_setPosition(background[7]->sprite, vectors.pos_sol5);
    if (sfSprite_getPosition(background[8]->sprite).x < -195)
        sfSprite_setPosition(background[8]->sprite, vectors.pos_sol5);
}