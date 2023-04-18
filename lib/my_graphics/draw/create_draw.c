/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that create a draw struct from parameters
*/
#include "../include/draw.h"

draw_t * create_draw(void * drawable, draw_type_t type, data_t * data)
{
    draw_t * draw = malloc(sizeof(draw_t));
    draw->drawable = drawable;
    draw->type = type;
    draw->id = -1;
    draw->show = true;
    draw->data = data;
    draw->next = NULL;
    draw->previous = NULL;
    return draw;
}
