/*
** EPITECH PROJECT, 2019
**
** File description:
**
*/

#include <SFML/Graphics.h>
#include "struct.h"
#include <stdlib.h>

void checktest(create **background, createvector vectors);
void move(create **background, createvector vectors, int left, createclock *clock);
void settextures(create **background, rect rectangles);
void set_everything(create **background, createvector vectors);
createvector fillvectorsx(createvector vectors);
createvector fillvectorsy(createvector vectors);
rect createrect(rect rectangles);
void puttin(create **background, createclock *clock);
void full(create **background);
void drawsprites(sfRenderWindow *window, create **background);

void draw_it(sfRenderWindow *window, create **background, rect rectangles)
{
    settextures(background, rectangles);
    drawsprites(window, background);
}

void fill_it(create **background, createclock *clock)
{
    puttin(background, clock);
    full(background);
}

createvector test(createvector vectors)
{
    vectors = fillvectorsx(vectors);
    vectors = fillvectorsy(vectors);
    return (vectors);
}

void jumpgestion(create **background, createvector vectors, createclock *clock)
{
    clock->time2 = sfClock_getElapsedTime(clock->clock2);
    while((clock->time2.microseconds / 1000000.0) < 2) {
        sfSprite_move(background[9]->sprite, vectors.jump);
        clock->time2 = sfClock_getElapsedTime(clock->clock2);
    }
    sfClock_restart(clock->clock2);
}

int main()
{
    sfRenderWindow *window;
    sfEvent event;
    int left = 0;

    window = create_window(600, 800,"test");
    create **background = malloc(sizeof(create*) * 13);
    rect rectangles;
    createvector vectors;
    createclock *clock = malloc(sizeof(*clock));
    rectangles = createrect(rectangles);
    fill_it(background, clock);
    vectors = test(vectors);
    set_everything(background, vectors);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfWhite);
        draw_it(window, background, rectangles);
        move(background, vectors, left, clock);
        clock->time = sfClock_getElapsedTime(clock->clock);
        if((clock->time.microseconds / 1000000.0) > 0.10) {
            rectangles.perso.left = left;
            left += 256;
            if (left > 1280) {
                left = 0;
            }
        sfClock_restart(clock->clock);
    }
        checktest(background, vectors);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue)
                jumpgestion(background, vectors, clock);
        }
    }
}