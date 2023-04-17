/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that create a draw struct from parameters
*/
#include "../include/draw.h"
#include "../include/global.h"

draw_t * create_draw(void * drawable, draw_type_t type,
                    data_t * data, draw_t * previous)
{
    draw_t * draw = malloc(sizeof(draw_t));
    draw->drawable = drawable;
    draw->type = type;
    draw->id = current_id;
    current_id++;
    draw->show = true;
    draw->data = data;
    draw->next = NULL;
    draw->previous = previous;
    return draw;
}
