/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that draw a list of draws to layer
*/
#include "../include/shape.h"

void set_color_in_shape(shape_t * shape, sfColor color)
{
    shape->color_in = color;
    if (shape->type == SQUARE) {
        sfRectangleShape_setFillColor(
                (sfRectangleShape *)(shape->shape),color_in);
    } if (shape->type == CIRCLE) {
        sfCircleShape_setFillColor(
                (sfCircleShape *)(shape->shape), color_in);
    }
}

void set_color_out_shape(shape_t * shape, sfColor color)
{
    shape->color_out = color;
    if (shape->type == SQUARE) {
        sfRectangleShape_setOutlineColor(
                (sfRectangleShape *)(shape->shape), color_out);
    } if (shape->type == CIRCLE) {
        sfCircleShape_setOutlineColor(
                (sfCircleShape *)(shape->shape), color_out);
    }
}

void set_thick_shape(shape_t * shape, int thick)
{
    shape->thick = thick;
    if (shape->type == SQUARE) {
        sfRectangleShape_setOutlineThickness(
                (sfRectangleShape *)(shape->shape), thick);
    } if (shape->type == CIRCLE) {
        sfCircleShape_setOutlineThickness(
                (sfCircleShape *)(shape->shape), thick);
    }
}

void set_attributes_shape(shape_t * shape, sfColor color_in,
                        sfColor color_out, int thick)
{
    set_color_in_shape(shape, color_in);
    set_color_out_shape(shape, color_out);
    set_thick_shape(shape, thick);
}
