/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that draw a list of draws to layer
*/
#include "../include/draw.h"

void draw_draws(sfRenderTexture * texture, draw_t * draw)
{
    draw_t * current = draw;
    while (current != NULL) {
        draw_single_draw(texture, current);
        current = current->next;
    }
}
