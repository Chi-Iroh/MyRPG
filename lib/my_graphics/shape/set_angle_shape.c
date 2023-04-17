/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that set the rotation of the shape
*/
#include "../include/shape.h"

void set_angle_shape(shape_t * shape, float angle)
{
    if (shape->type == RECT) {
        sfRectangleShape_setRotation((sfRectangleShape *)(shape->shape),
                                                                        angle);
    }
    if (shape->type == CIRCLE) {
        sfCircleShape_setRotation((sfCircleShape *)(shape->shape), angle);
    }
}
