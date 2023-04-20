/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** crowd.c
*/

#include "../include/my_rpg.h"

sfBool check_collision(draw_t *player, draw_t *crowd)
{
    sfFloatRect spriteBounds = get_global_bounds_draw(player);
    sfFloatRect crowdBounds = get_global_bounds_draw(crowd);
    return sfFloatRect_intersects(&spriteBounds, &crowdBounds, NULL);
}

void free_crowd(crowd_t *crowd)
{
    for (int i = 0; i < CROWD_SIZE; i++) {
        sfClock_destroy(crowd->cop[i]->clock);
        free(crowd->cop[i]);
        free(crowd->mob[i]);
    }
    free(crowd->mob);
    free(crowd->cop);
    free(crowd->player);
}

void crowd(window_t* wd, crowd_t crowd)
{
    update(&crowd);
}