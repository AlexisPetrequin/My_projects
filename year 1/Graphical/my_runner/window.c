/*
** EPITECH PROJECT, 2019
**
** File description:
**
*/

#include <SFML/Graphics.h>

sfRenderWindow *create_window(int height, int width, char* name)
{
    sfRenderWindow *window;
    sfVideoMode vid_mode;
    vid_mode.width = width;
    vid_mode.height = height;
    vid_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(vid_mode, name, sfDefaultStyle, NULL);

    return (window);
}
