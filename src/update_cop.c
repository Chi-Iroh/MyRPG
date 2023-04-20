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
        case 1: move = 0.03f; break;
        case 0: move = 0.00f; break;
        case -1: move = -0.03f; break;
    }
    //printf("%.2f\n", move);
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


void update_circle_cop
(cop_t *cop, draw_t *player, sfVector3f cop_pos, sfVector2f dir)
{
    float distance = sqrtf(dir.x * dir.x +
        dir.y * dir.y);
    if (distance > 1.0f) {
        dir.x /= distance;
        dir.y /= distance;
    }
    sfVector3f newPosition;
    if (distance < 800.f) {
        if (draw_within_thr(player, cop->draw, 70) &&
        sfTime_asSeconds(sfClock_getElapsedTime(cop->clock)) > 5) {
            //printf("is_hit\n");
            sfClock_restart(cop->clock);
        }
        newPosition.x = cop_pos.x + dir.x * 0.03f + rand_move();
        newPosition.y = cop_pos.y + dir.y * 0.03f + rand_move();
        newPosition.z = 0;
    }
    set_pos_draw(cop->draw, newPosition);
}

void update_cop(cop_t *cop, draw_t *player, sfVector3f spritePosition)
{
    sfVector3f cop_pos = get_position_draw(cop->draw);
    sfVector2f direction;
    direction.x = spritePosition.x - cop_pos.x;
    direction.y = spritePosition.y - cop_pos.y;
    update_circle_cop(cop, player, cop_pos, direction);
    
    //cop->spsht.dir = (direction.y >= 0) ? DOWN : UP;
}
