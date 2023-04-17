/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that free a shape struct
*/
#include "../include/shape.h"

void free_shape(shape_t * shape)
{
    if (shape->type == RECT) {
        sfRectangleShape_destroy((sfRectangleShape *)(shape->shape));
    }
    if (shape->type == CIRCLE) {
        sfCircleShape_destroy((sfCircleShape *)(shape->shape));
    }
    free(shape);
}
