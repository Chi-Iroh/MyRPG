/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that create a layer struct from parameters
*/
#include "../include/layer.h"

void append_draw_layer(layer_t * layer, draw_t * draw)
{
    draw_t * current = layer->draw;
    layer->draw = draw;
    if (current != NULL) {
        current->previous = draw;
        draw->next = current;
    }
}
