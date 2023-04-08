/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that set position and rotation of the sprite
*/
#include "../include/sprite.h"

void set_data_sprite(sprite_t * sprite, data_t * data)
{
    set_pos_sprite(sprite, data->position);
    set_angle_sprite(sprite, data->angle);
}
