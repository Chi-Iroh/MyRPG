/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** crowd.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

float calculate_sprite_distance(draw_t *player, draw_t *crowd)
{
    sfFloatRect rect1 = get_global_bounds_draw(player);
    sfFloatRect rect2 = get_global_bounds_draw(crowd);
    float dx = rect2.left - rect1.left;
    float dy = rect2.top - rect1.top;
    return sqrt(dx * dx + dy * dy);
}

sfBool draw_within_thr(draw_t *player, draw_t *crowd, float thr)
{
    float distance = calculate_sprite_distance(player, crowd);
    return distance <= thr;
}

sfBool check_collision(draw_t *player, draw_t *crowd)
{
    sfFloatRect spriteBounds = get_global_bounds_draw(player);
    sfFloatRect crowdBounds = get_global_bounds_draw(crowd);
    return sfFloatRect_intersects(&spriteBounds, &crowdBounds, NULL);
}

void free_crowd(crowd_t *crowd)
{
    if (crowd->cop == NULL || crowd->mob == NULL || crowd->player == NULL)
    return;
    sfClock_destroy(crowd->player->clock);
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
    if (crowd.player->exp.fill->data->size.x >= 250) {
        float tmp = crowd.player->exp.fill->data->size.x - 250;
        set_size_draw(crowd.player->exp.fill,
        set_2vector(tmp, crowd.player->exp.fill->data->size.y));
        crowd.player->stat.exp_point += 1;
        crowd.player->stat.level += crowd.player->stat.level < 20 ?
        1 : crowd.player->stat.level;
    }
}
