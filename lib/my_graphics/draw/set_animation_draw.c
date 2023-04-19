/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that enable animation for draw type sprite
*/
#include "../include/draw.h"

void set_animation_draw(draw_t * draw, int nb_frame)
{
    if (draw->type != SPRITE) {
        return;
    }
    set_animation_sprite((sprite_t *)(draw->drawable), nb_frame);
}
