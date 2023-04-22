/*
** EPITECH PROJECT, 2022
** My_rpg_tmp
** File description:
** update.c
*/

#include <my_rpg.h>
#include <my_graphics.h>
#include <stdio.h>

bool check_pos(draw_t *draw, window_t *wd)
{
    if (intersect_with_map(draw, wd->core->draw)) {
        return true;
    }
    return false;
}

sfVector2f move_player(player_t *player, window_t *wd)
{
    sfVector2f move = {0.f, 0.f}; sfVector2f dir;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        {move.x -= player->stat.speed / 100;}
    if (sfKeyboard_isKeyPressed(sfKeyD))
        {move.x += player->stat.speed / 100;}
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        {move.y -= player->stat.speed / 100;}
    if (sfKeyboard_isKeyPressed(sfKeyS))
        {move.y += player->stat.speed / 100;}
    move.y != 0 && move.x != 0 ? move.x /= 1.33, move.y /= 1.33 : 0;
    move_draw(player->draw, set_2vector(move.x, move.y));
    if ((move.x != 0 || move.y != 0) && check_pos(player->draw, wd)) {
        dir.x = move.x > 0 ? 1 : move.x < 0 ? -1 : 0;
        dir.y = move.y > 0 ? 1 : move.y < 0 ? -1 : 0;
        move.x = 0; move.y = 0;
        move.x += dir.x == -1 ? player->stat.speed / 100 : 0;
        move.x -= dir.x == 1 ? player->stat.speed / 100 : 0;
        move.y += dir.y == -1 ? player->stat.speed / 100 : 0;
        move.y -= dir.y == 1 ? player->stat.speed / 100 : 0;
        move.y != 0 && move.x != 0 ? move.x /= 1.33, move.y /= 1.33 : 0;
        move_draw(player->draw, set_2vector(move.x, move.y));
    }
    return move;
}

void update_attack_cl(player_t *player)
{
    float time = sfTime_asSeconds
    (sfClock_getElapsedTime(player->clock));
    if (time <= 0.8)
    set_size_draw(player->cooldown,
    set_2vector(player->cooldown->data->size.x, time * -200));
    if (time > 0.8)
    set_size_draw(player->cooldown,
    set_2vector(player->cooldown->data->size.x , -160));
}

void update(crowd_t *crowd, window_t *wd)
{
    sfVector2f move = move_player(crowd->player, wd);
    sfVector3f spritePosition = get_position_draw(crowd->player->draw);
    if (move.x != 0 || move.y != 0)
        move_range(crowd->player, move);
    for (int i = 0; i < CROWD_SIZE; i++) {
        update_cop(crowd->cop[i], crowd, spritePosition);
        update_mob(crowd->mob[i], crowd, move);
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace) && sfTime_asSeconds
    (sfClock_getElapsedTime(crowd->player->clock)) > 0.8f) {
        sfClock_restart(crowd->player->clock);
        for (int i = 0; i < CROWD_SIZE; i++)
            check_hitbox(crowd, i, spritePosition);
    }
    update_attack_cl(crowd->player);
}
