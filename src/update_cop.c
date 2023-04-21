/*
** EPITECH PROJECT, 2022
** My_rpg_tmp
** File description:
** update_cop.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

float rand_move(void)
{
    float move = 0.0f;
    if (rand() % 5 == 0)
        switch (rand() % 3 - 1) {
            case 1: move = 0.05f; break;
            case 0: move = 0.00f; break;
            case -1: move = -0.05f; break;
        }
    return move;
}

sfVector2f calculate_repulsion_force(sfVector2f pos1, sfVector2f pos2, float k)
{
    sfVector2f rep;
    float dx = pos2.x - pos1.x;
    float dy = pos2.y - pos2.y;
    float dist_sq = dx * dx + dy * dy;
    float dist = sqrt(dist_sq);
    float force = k / dist_sq;
    rep.x = force * dx / dist;
    rep.y = force * dy / dist;
    return rep;
}

sfVector3f calc_dist(sfVector3f pos1, sfVector3f pos2)
{
    sfVector2f dir;
        dir.x = pos1.x - pos2.x;
        dir.y = pos1.y - pos2.y;
    float distance = sqrtf(dir.x * dir.x + dir.y * dir.y);
    if (distance > 1.0f) {
        dir.x /= distance;
        dir.y /= distance;
    }
    return set_3vector(dir.x, dir.y, distance);
}

void update_circle_cop
(cop_t *cop, player_t *player, sfVector3f cop_pos, sfVector3f pos_pl)
{
    sfVector3f cord = calc_dist(pos_pl, cop_pos);
    sfVector3f newPosition;
    if (draw_within_thr(player->draw, cop->draw, 70) &&
    sfTime_asSeconds(sfClock_getElapsedTime(cop->clock)) > 5
    && get_size_draw(player->hp.fill).x > 0) {
        sfVector2f size = get_size_draw(player->hp.fill);
        set_size_draw(player->hp.fill, set_2vector(size.x - 25, size.y));
        sfClock_restart(cop->clock);
    }
    newPosition.x = cop_pos.x + cord.x * 0.05f + rand_move();
    newPosition.y = cop_pos.y + cord.y * 0.05f + rand_move();
    set_pos_draw
    (cop->hp.fill, set_3vector(newPosition.x, newPosition.y - 40, 0));
    set_pos_draw(cop->draw, newPosition);
}

void update_cop(cop_t *cop, crowd_t *crowd, sfVector3f spritePosition)
{
    if (cop->stat.hp <= 0) {
        knock_back(cop, spritePosition, 0.05f);
        cop->dead = TRUE;
    } else {
        sfVector3f cop_pos = get_position_draw(cop->draw);
        update_circle_cop(cop, crowd->player, cop_pos, spritePosition);
    }
}
