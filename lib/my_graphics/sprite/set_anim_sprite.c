/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that set informations for animation
*/
#include "../include/sprite.h"

void set_animation_sprite(sprite_t * sprite, int nb_frame)
{
    sprite->animated = true;
    sprite->nb_frame = nb_frame;
    sprite->current = 0;
}
