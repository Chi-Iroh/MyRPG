/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that set informations for animation
*/
#include "../include/sprite.h"

void set_animation_sprite(sprite_t * sprite, int nb_frame)
{
    if (sprite->rect.width == 0 || sprite->rect.height == 0) {
        return;
    }
    sprite->animated = true;
    sprite->nb_frame = nb_frame;
    sprite->current = 0;
}
