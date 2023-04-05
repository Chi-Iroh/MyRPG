/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that set the position of the shape
*/
#include "../include/shape.h"

void set_pos_shape(shape_t * shape, sfVector3f position)
{
    sfVector2f pos = set_2vector(position.x, position.y);
    if (shape->type == SQUARE) {
        sfRectangleShape_setPosition((sfRectangleShape *)(shape->shape), pos);
    }
    if (shape->type == CIRCLE) {
        sfCircleShape_setPosition((sfCircleShape *)(shape->shape), pos);
    }
}
