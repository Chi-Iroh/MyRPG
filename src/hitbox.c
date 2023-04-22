/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** hitbox.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

void is_hit(cop_t *cop, player_t *player)
{
    cop->stat.hp -= (player->stat.damage * 4);
    set_size_draw(cop->hp.fill, set_2vector
    (cop->hp.fill->data->size.x - (player->stat.damage * 4),
    cop->hp.fill->data->size.y));
    if (cop->stat.hp <= 0) {
        set_size_draw(cop->hp.fill, set_2vector
        (0, cop->hp.fill->data->size.y));
    }
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

void knock_back(cop_t *cop, sfVector3f spritePosition, float pw)
{
    sfVector3f cop_pos = get_position_draw(cop->draw);
    sfVector3f cord = calc_dist(cop_pos, spritePosition);
    sfVector3f new_pos;
    new_pos.x = cop_pos.x + cord.x * pw;
    new_pos.y = cop_pos.y + cord.y * pw;
    set_pos_draw
    (cop->hp.fill, set_3vector(new_pos.x, new_pos.y - 40, 0));
    set_pos_draw(cop->draw, new_pos);
}

void check_hitbox(crowd_t *crowd, int i, sfVector3f spritePosition)
{
    if (crowd->cop[i]->dead != TRUE &&
    check_collision(crowd->cop[i]->draw, crowd->player->range)) {
        is_hit(crowd->cop[i], crowd->player);
        knock_back(crowd->cop[i], spritePosition, 50);
        if (crowd->cop[i]->hp.fill->data->size.x <= 0) {
            set_size_draw(crowd->player->exp.fill,
            set_2vector(
            get_size_draw(crowd->player->exp.fill).x +
            ((20  - crowd->player->stat.level) *
            (rand_move() + 2)),
            get_size_draw(crowd->player->exp.fill).y));
            crowd->cop[i]->dead = TRUE;
        }
    }
}
