/*
** EPITECH PROJECT, 2022
** My_rpg_tmp
** File description:
** update_mob.c
*/

#include "../include/my_rpg.h"
#include "../lib/my_graphics/my_graphics.h"

/*sfVector2f place_in_mob(mob_t *mob, sfSprite *sprite)
{
    float angle = (float)(rand() % 360);
    float r = (float)rand() / RAND_MAX * 180;
    sfVector2f newPosition = {
        sfSprite_getPosition(sprite).x + cos(angle) * (r + 60),
        sfSprite_getPosition(sprite).y + sin(angle) * (r + 60)
    };
    mob->in_mob = IN;
    return newPosition;
}

sfVector2f not_in_mob(mob_t *mob, sfSprite *sprite)
{
    sfVector2f newPosition = (sfVector2f) {
        sfSprite_getPosition(mob->sprite).x,
        sfSprite_getPosition(mob->sprite).y
    };
    if ((rand() % 5) == 0)
    newPosition = (sfVector2f) {
        sfSprite_getPosition(mob->sprite).x + (float)(rand() % 3 - 1) * 5,
        sfSprite_getPosition(mob->sprite).y + (5 * mob->dir)
    };
    float dx =
    sfSprite_getPosition(sprite).x - sfSprite_getPosition(mob->sprite).x;
    float dy =
    sfSprite_getPosition(sprite).y - sfSprite_getPosition(mob->sprite).y;
    float distance = sqrt(dx * dx + dy * dy);
    if (distance < 50.0)
        newPosition = place_in_mob(mob, sprite);
    return newPosition;
}

void update_mob(mob_t *mob, sfSprite *sprite, sfVector2f move)
{

    if (mob->in_mob == OUT) {
        sfVector2f newPosition = not_in_mob(mob, sprite);
        sfSprite_setPosition(mob->sprite, newPosition);
        if (newPosition.x <= 0 || (newPosition.x) >= WD_WIDTH) {
        newPosition.x *= -1;
        }
        if (newPosition.y <= 0 || (newPosition.y) >= WD_HEIGHT) {
            mob->dir *= -1;
        }
    }
    if (mob->in_mob == IN)
        sfSprite_move(mob->sprite, (sfVector2f){move.x, move.y});
}*/
