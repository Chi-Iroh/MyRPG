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
    shape->color_in = color_in;
    shape->color_out = color_out;
    shape->thick = thick;
    if (type == SQUARE) {
        shape->shape = sfRectangleShape_create();
        sfRectangleShape_setFillColor(
                (sfRectangleShape *)(shape->shape),color_in);
        sfRectangleShape_setOutlineColor(
                (sfRectangleShape *)(shape->shape), color_out);
        sfRectangleShape_setOutlineThickness(
                (sfRectangleShape *)(shape->shape), thick);
    }
    if (type == CIRCLE) {
        shape->shape = sfCircleShape_create();
        sfCircleShape_setFillColor(
                (sfCircleShape *)(shape->shape), color_in);
        sfCircleShape_setOutlineColor(
                (sfCircleShape *)(shape->shape), color_out);
        sfCircleShape_setOutlineThickness(
                (sfCircleShape *)(shape->shape), thick);
    }
    return shape;
}
