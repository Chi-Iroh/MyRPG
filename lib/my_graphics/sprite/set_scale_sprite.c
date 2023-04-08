/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that scale of the sprite
*/
#include "../include/sprite.h"

void set_scale_sprite(sprite_t * sprite, sfVector2f scale)
{
    sfSprite_setScale(sprite->sprite, scale);
}
