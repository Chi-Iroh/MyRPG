/*
** EPITECH PROJECT, 2022
** My_rpg_tmp
** File description:
** update.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

sfVector2f move_player(draw_t *draw)
{
    sfVector2f move = {0.f, 0.f};
    //sfVector2f spritePosition = get_position_draw(draw);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        move.x -= MAX_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        move.x += MAX_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        move.y -= MAX_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        move.y += MAX_SPEED;
    move.y != 0 && move.x != 0 ? move.x /= 1.33, move.y /= 1.33 : 0;
    move_draw(draw, (sfVector2f){move.x, move.y});
    return (sfVector2f){move.x, move.y};
}

void update(crowd_t *crowd)
{
    sfVector2f move = move_player(crowd->player->draw);
    sfVector3f spritePosition = get_position_draw(crowd->player->draw);
    for (int i = 0; i < CROWD_SIZE; i++) {
        update_cop(crowd->cop[i], crowd->player->draw, spritePosition);
        update_mob(crowd->mob[i], crowd->player->draw, move);
    }
    /*update_spritesheet(&crowd->player->spsht, crowd->player->sprite);
    for (int i = 0; i < CROWD_SIZE; i++) {
        crowd->mob[i]->spsht.dir = (crowd->mob[i]->dir == 1) ? DOWN : UP;
        crowd->mob[i]->spsht.dir = (crowd->mob[i]->in_mob == IN &&
        (move.y >= 0)) ? DOWN : crowd->mob[i]->spsht.dir;
        crowd->mob[i]->spsht.dir = (crowd->mob[i]->in_mob == IN &&
        (move.y < 0)) ? UP : crowd->mob[i]->spsht.dir;
        update_spritesheet(&crowd->cop[i]->spsht, crowd->cop[i]->sprite);
        update_spritesheet(&crowd->mob[i]->spsht, crowd->mob[i]->sprite);
    }*/
}
