/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that set the position of the sprite
*/
#include "../include/sprite.h"

void set_pos_sprite(sprite_t * sprite, sfVector3f position)
{
    sfVector2f pos = set_2vector(position.x, position.y);
    sfSprite_setPosition(sprite->sprite, pos);
}
