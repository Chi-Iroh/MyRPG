/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that initialize a sprite struct
*/
#include "../include/sprite.h"

void move_sprite(sprite_t * sprite, sfVector2f offset)
{
    sfSprite_move((sfSprite *)(sprite->sprite), offset);
}

void set_scale_sprite(sprite_t * sprite, sfVector2f scale)
{
    sfSprite_scale(sprite->sprite, scale);
}

void rotate_sprite(sprite_t * sprite, float angle)
{
    sfSprite_rotate((sfSprite *)(sprite->sprite), angle);
}

void modify_sprite(sprite_t * sprite, sfVector2f offset,
                    sfVector2f scale, float angle)
{
    move_sprite(sprite, offset);
    scale_sprite(sprite, scale);
    rotate_sprite(sprite, angle);
}
