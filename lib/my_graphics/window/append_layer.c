/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that set informations for animation
*/
#include "../include/window.h"

void append_layer(layer_t * first, layer_t * layer)
{
    layer_type_t type = first->type;
    while (first->next != NULL && (first->next->type == type + 1)) {
        first = first->next;
    }
    layer_t * next = first->next;
    first->next = layer;
    if (layer->previous != first) {
        layer->previous = first;
    }
    if (next != NULL) {
        layer->next = next;
        next->previous = layer;
    }
}
