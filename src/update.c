/*
** EPITECH PROJECT, 2022
** My_rpg_tmp
** File description:
** update.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

sfVector2f move_player(player_t *player)
{
    sfVector2f move = {0.f, 0.f};
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        move.x -= player->stat.speed / 100;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        move.x += player->stat.speed / 100;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        move.y -= player->stat.speed / 100;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        move.y += player->stat.speed / 100;
    move.y != 0 && move.x != 0 ? move.x /= 1.33, move.y /= 1.33 : 0;
    move_draw(player->draw, set_2vector(move.x, move.y));
    return move;
}

void update(crowd_t *crowd)
{
    sfVector2f move = move_player(crowd->player);
    sfVector3f spritePosition = get_position_draw(crowd->player->draw);
    if (move.x != 0 || move.y != 0)
        move_range(crowd->player->range, move, spritePosition, 50);
    for (int i = 0; i < CROWD_SIZE; i++) {
        update_cop(crowd->cop[i], crowd, spritePosition);
        update_mob(crowd->mob[i], crowd, move);
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace) &&
        sfTime_asSeconds
        (sfClock_getElapsedTime(crowd->player->clock)) > 0.8f) {
    sfClock_restart(crowd->player->clock);
        for (int i = 0; i < CROWD_SIZE; i++)
            check_hitbox(crowd, i, spritePosition);
    }
}
