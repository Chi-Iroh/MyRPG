/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that set the rotation of the sprite
*/
#include "../include/sprite.h"

void set_angle_sprite(sprite_t * sprite, float angle)
{
    sfSprite_setRotation(sprite->sprite, angle);
}
