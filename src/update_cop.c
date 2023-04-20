/*
** EPITECH PROJECT, 2022
** My_rpg_tmp
** File description:
** update_cop.c
*/

#include "../include/my_rpg.h"
#include "../lib/my_graphics/my_graphics.h"

void update_circle_mob
(cop_t *cop, draw_t *player, sfVector3f cop_pos, sfVector2f dir)
{
    float distance = sqrtf(dir.x * dir.x +
        dir.y * dir.y);
    if (distance > 1.0f) {
        dir.x /= distance;
        dir.y /= distance;
    }
    sfVector3f newPosition;
    if (distance < 400.f) {
        if (check_collision(player, cop->draw) &&
        sfTime_asSeconds(sfClock_getElapsedTime(cop->clock)) > 5)
            sfClock_restart(cop->clock);
        newPosition.x = cop_pos.x + dir.x * 2.0f +(float)(rand() % 3 - 1);
        newPosition.y = cop_pos.y + dir.y * 2.0f + (float)(rand() % 3 - 1);
        newPosition.z = 0;
    } else {
        newPosition.x = cop_pos.x + dir.x * 3.0f + (float)(rand() % 3 - 1);
        newPosition.y = cop_pos.y + dir.y * 3.0f + (float)(rand() % 3 - 1);
        newPosition.z = 0;
    }
    set_pos_draw(cop->draw, newPosition);
}

void update_cop(cop_t *cop, draw_t *player, sfVector2f spritePosition)
{
    sfVector3f cop_pos = get_position_draw(cop->draw);
    sfVector2f direction;
    direction.x = spritePosition.x - cop_pos.x;
    direction.y = spritePosition.y - cop_pos.y;
    update_circle_mob(cop, player, cop_pos, direction);

    //cop->spsht.dir = (direction.y >= 0) ? DOWN : UP;
}
