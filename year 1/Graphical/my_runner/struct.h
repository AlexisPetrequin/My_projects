#include <SFML/Graphics.h>

typedef struct creationsprite
{
    sfSprite *sprite;
    sfTexture *texture;
}create;

typedef struct creationrect
{
    sfIntRect sol;
    sfIntRect perso;
}rect;

typedef struct createclock
{
    sfClock *clock;
    sfTime time;
    sfClock *clock2;
    sfTime time2;

}createclock;

typedef struct vector
{
    sfVector2f mid_scale;
    sfVector2f fond_scale;
    sfVector2f perso_scale;
    sfVector2f pos_sol1;
    sfVector2f pos_sol2;
    sfVector2f pos_sol3;
    sfVector2f pos_sol4;
    sfVector2f pos_sol5;
    sfVector2f pos_mid;
    sfVector2f pos_mid2;
    sfVector2f pos_fond2;
    sfVector2f pos_perso;
    sfVector2f move_sol;
    sfVector2f move_mid;
    sfVector2f move_fond;
    sfVector2f jump;
}createvector;