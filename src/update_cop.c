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

sfVector3f calc_dist(draw_t *draw1, draw_t *draw2)
{
    sfVector3f pos1 = get_position_draw(draw1);
    sfVector3f pos2 = get_position_draw(draw2);
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

sfVector3f get_closer_mob(cop_t *cop, crowd_t *crowd)
{
    sfVector3f cord;
    sfVector3f new_pos;
    float dist_min = 10000;
    int tmp = 0;
    for (int i = 0; i < CROWD_SIZE; i++) {
        if (crowd->mob[i]->in_mob == IN)
        continue;
        cord = calc_dist(crowd->mob[i]->draw, cop->draw);
        tmp = dist_min > cord.z ? i: tmp;
        dist_min = dist_min > cord.z ? cord.z: dist_min;
        if (cord.z < 50) {
            crowd->mob[i]->in_mob = DEAD;
            crowd->mob[i]->dir = -1;
        }
    }
    cord = calc_dist(crowd->mob[tmp]->draw, cop->draw);
    new_pos.x = cop->draw->data->position.x +
    cord.x * (cop->stat.speed / 100) + rand_move();
    new_pos.y = cop->draw->data->position.y +
    cord.y * (cop->stat.speed / 100) + rand_move();
    new_pos.z = 0;
    return new_pos;
}

void update_circle_cop
(cop_t *cop, crowd_t *crowd, sfVector3f cop_pos, sfVector3f pos_pl)
{
    sfVector3f cord = calc_dist(crowd->player->draw, cop->draw);
    sfVector3f new_pos;
    if (draw_within_thr(crowd->player->draw, cop->draw, 60) &&
    sfTime_asSeconds(sfClock_getElapsedTime(cop->clock)) > 3
    && get_size_draw(crowd->player->hp.fill).x > 0) {
        sfVector2f size = get_size_draw(crowd->player->hp.fill);
        set_size_draw(crowd->player->hp.fill, set_2vector
        (size.x -(cop->stat.damage - (crowd->player->stat.defense / 50)),
        size.y));
        sfClock_restart(cop->clock);
    }
    new_pos = get_closer_mob(cop, crowd);
    if (cord.z < 500) {
        new_pos.x = cop_pos.x + cord.x * (cop->stat.speed / 100) + rand_move();
        new_pos.y = cop_pos.y + cord.y * (cop->stat.speed / 100) + rand_move();
        new_pos.z = 0;
    }
    set_pos_draw
    (cop->hp.fill, set_3vector(new_pos.x, new_pos.y - 40, 0));
    set_pos_draw(cop->draw, new_pos);
}

void update_cop(cop_t *cop, crowd_t *crowd, sfVector3f spritePosition)
{
    if (cop->stat.hp <= 0) {
        knock_back(cop, crowd->player, (cop->stat.speed / 100));
        cop->dead = TRUE;
    } else {
        sfVector3f cop_pos = get_position_draw(cop->draw);
        update_circle_cop(cop, crowd, cop_pos, spritePosition);
    }
}
