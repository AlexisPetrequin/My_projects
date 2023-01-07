/*
** EPITECH PROJECT, 2019
**
** File description:
**
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

void main(void)
{
    sfRenderWindow *window;
    sfEvent event;
    sfIntRect rect;
    sfSprite *sprite;
    sfSprite *nature;
    sfSprite *tombe;
    sfTexture *texture;
    sfTexture *fond;
    sfClock *clock;
    sfTime time;
    float seconds;
    int left = 0;
    int y1;
    int i = 0;

    rect.top = 0;
    rect.left = left;
    rect.width = 110;
    rect.height = 110;

    sfVector2f move = {0.5, 0};
    sfVector2f position = {-300, y1};
    sfVector2f posverif = {800, y1};
    sfVector2f naturescale = {0.555, 0.555};
    sfVector2i posmouse;
    sfVector2f posduck;

    clock = sfClock_create();
    window = create_window(600, 800, "duck hunt");
    sprite = sfSprite_create();
    nature = sfSprite_create();
    texture = sfTexture_createFromFile("cannard.png", NULL);
    fond = sfTexture_createFromFile("fond.png", NULL);
    sfSprite_setPosition(sprite, position);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        sfSprite_setTexture(nature, fond, sfTrue);
        sfSprite_setScale(nature, naturescale);
        sfRenderWindow_drawSprite(window, nature, NULL);
        sfSprite_setTexture(sprite, texture, sfTrue);
//mouvement du sprite
            time = sfClock_getElapsedTime(clock);
            seconds = time.microseconds / 1000000.0;
            if(seconds > 0.15) {
                rect.left = left;
                    left += 110;
                if (left > 220) {
                    left = 0;
                }
                sfClock_restart(clock);
            }
            sfSprite_setTextureRect(sprite, rect);
            sfRenderWindow_drawSprite(window, sprite, NULL);
            sfSprite_move(sprite, move);
            if (sfSprite_getPosition(sprite).x == posverif.x) {
                y1 = rand() % 490;
                sfVector2f position = {-300, y1};
                sfSprite_setPosition(sprite, position);
            }
            posduck.x = sfSprite_getPosition(sprite).x;
            posduck.y = sfSprite_getPosition(sprite).y;
            while (sfRenderWindow_pollEvent(window, &event)) {
                if (sfMouse_isButtonPressed(sfMouseLeft)) {
                    posmouse = sfMouse_getPosition(window);
                }
                if (sfMouse_isButtonPressed(sfMouseLeft) && posmouse.x >= posduck.x && posmouse.y >= posduck.y
                    && posmouse.x <= (posduck.x + 110)
                    && posmouse.y <= (posduck.y + 110)) {
                        sfSprite_setPosition(sprite, position);
                    }
                if (event.type == sfEvtClosed)
                    sfRenderWindow_close(window);
        }
    }
}
