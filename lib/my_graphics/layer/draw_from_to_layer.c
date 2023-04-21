/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that draw layers that are between two given (the two are included)
*/
#include "../include/layer.h"

void draw_from_to_layer(sfRenderWindow * window, layer_t * from, layer_t * to,
                        sfView * view)
{
    layer_t * current = from;
    while (current != to->next) {
        draw_single_layer(window, current, (current->type == BACKGROUND
            || current->type == CORE || current->type == FX) ? view : NULL);
        current = current->next;
    }
}
