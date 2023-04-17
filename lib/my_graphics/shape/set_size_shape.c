/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that set the dimensions of the shape
*/
#include "../include/shape.h"

void set_size_shape(shape_t * shape, sfVector2f size)
{
    if (shape->type == RECT) {
        sfRectangleShape_setSize((sfRectangleShape *)(shape->shape), size);
    }
    if (shape->type == CIRCLE) {
        sfCircleShape_setRadius((sfCircleShape *)(shape->shape), size.x / 2.f);
    }
}
