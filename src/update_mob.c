/*
** EPITECH PROJECT, 2022
** My_rpg_tmp
** File description:
** update_mob.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

sfVector3f place_in_mob(mob_t *mob, draw_t *player)
{
    float angle = (float)(rand() % 360);
    float r = (float)rand() / RAND_MAX * 180;
    sfVector3f newPosition = {
        get_position_draw(player).x + cos(angle) * (r + 60),
        get_position_draw(player).y + sin(angle) * (r + 60),
        0
    };
    mob->in_mob = IN;
    return newPosition;
}

sfVector3f not_in_mob(mob_t *mob, draw_t *player)
{
    sfVector3f newPosition = (sfVector3f) {
        get_position_draw(mob->draw).x,
        get_position_draw(mob->draw).y,
        0
    };
    if ((rand() % 5) == 0)
    newPosition = (sfVector3f) {
        newPosition.x +  rand_move(),
        newPosition.y + (0.03 * mob->dir), 0
    };
    float dx = get_position_draw(player).x - newPosition.x;
    float dy = get_position_draw(player).y - newPosition.y;
    float distance = sqrt(dx * dx + dy * dy);
    if (distance < 50.0)
        newPosition = place_in_mob(mob, player);
    return newPosition;
}

void update_mob(mob_t *mob, crowd_t *crowd, sfVector2f move)
{

    if (mob->in_mob == OUT) {
        sfVector3f newPosition = not_in_mob(mob, crowd->player->draw);
        set_pos_draw(mob->draw, newPosition);
        if (newPosition.x <= 0 || (newPosition.x) >= WD_WIDTH) {
            newPosition.x *= -1;
        }
        if (newPosition.y <= 0 || (newPosition.y) >= WD_HEIGHT) {
            mob->dir *= -1;
        }
    }
    if (mob->in_mob == IN)
        move_draw(mob->draw, move);
}
