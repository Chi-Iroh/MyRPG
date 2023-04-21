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

void is_hit(cop_t *cop, player_t *player)
{
    cop->stat.hp -= player->stat.damage;
}

void move_range
(draw_t *draw, sfVector2f move, sfVector3f spritePosition, float dist)
{
    sfVector2f offset;
    move.x = move.x > 0 ? 1 : move.x < 0 ? -1 : 0;
    move.y = move.y > 0 ? 1 : move.y < 0 ? -1 : 0;
    offset.x = move.x * dist;
    offset.y = move.y * dist;
    sfVector3f hitboxPos;
    hitboxPos.x = spritePosition.x + offset.x;
    hitboxPos.y = spritePosition.y + offset.y;
    set_pos_draw(draw, hitboxPos);
}

void check_hitbox(crowd_t *crowd, int i, sfVector3f spritePosition)
{
    if (check_collision(crowd->cop[i]->draw, crowd->player->range)) {
        is_hit(crowd->cop[i], crowd->player);
        move_range (crowd->cop[i]->draw,
        set_2vector
        (get_position_draw(crowd->player->range).x - spritePosition.x,
        get_position_draw(crowd->player->range).y - spritePosition.y),
        spritePosition, 75);
    }
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
