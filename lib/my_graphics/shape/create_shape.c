/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that create a shape struct from parameters
*/
#include "../include/shape.h"

shape_t * create_shape(shape_type_t type, sfColor color_in,
                            sfColor color_out, int thick)
{
    shape_t * shape = malloc(sizeof(shape_t));
    shape->type = type;
    shape->shape = NULL;
    if (type == SQUARE) {
        shape->shape = sfRectangleShape_create();
    }
    if (type == CIRCLE) {
        shape->shape = sfCircleShape_create();
    }
    shape->color_in = color_in;
    shape->color_out = color_out;
    shape->thick = thick;
    return shape;
}
