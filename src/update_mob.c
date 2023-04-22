/*
** EPITECH PROJECT, 2022
** My_rpg_tmp
** File description:
** update_mob.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

void place_in_mob(mob_t *mob, draw_t *player)
{
    float angle = (float)(rand() % 360);
    float r = (float)rand() / RAND_MAX * 180;
    sfVector3f newPosition = {
        get_position_draw(player).x + cos(angle) * (r + 60),
        get_position_draw(player).y + sin(angle) * (r + 60),
        0
    };
    mob->in_mob = IN;
    set_pos_draw(mob->draw, newPosition);
}

void not_in_mob(mob_t *mob, draw_t *player)
{
    sfVector3f pos = get_position_draw(mob->draw);
    sfVector2f move = set_2vector(0, 0);
    if ((rand() % 10) == 0)
        move = set_2vector((0.3 * mob->dir), rand_move());
    sfVector3f pos_p = get_position_draw(player);
    float dx = pos_p.x - pos.x;
    float dy = pos_p.y - pos.y;
    float distance = sqrt(dx * dx + dy * dy);
    move_draw(mob->draw, move);
    if (distance < 50.0 && mob->in_mob != DEAD)
        place_in_mob(mob, player);
}

void update_mob(mob_t *mob, crowd_t *crowd, sfVector2f move)
{

    if (mob->in_mob == OUT || mob->in_mob == DEAD)
        not_in_mob(mob, crowd->player->draw);
    if (mob->in_mob == IN)
        move_draw(mob->draw, move);
}
