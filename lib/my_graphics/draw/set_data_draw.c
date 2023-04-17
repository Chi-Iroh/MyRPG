/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that change the data struct
*/
#include "../include/draw.h"

void set_data_draw(draw_t * draw, data_t * data)
{
    draw->data = data;
    switch (draw->type) {
        case SHAPE:
            set_data_shape((shape_t *)(draw->drawable), draw->data);
        break;
        case SPRITE:
            set_data_sprite((sprite_t *)(draw->drawable), draw->data);
        break;
        case TEXT:
            set_data_text((text_t *)(draw->drawable), draw->data);
        break;
        default: break;
    }
}
