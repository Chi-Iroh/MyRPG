/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that draw a specific draw to layer
*/
#include "../include/draw.h"

void draw_single_draw(sfRenderTexture * texture, draw_t * draw)
{
    switch (draw->type) {
        case SHAPE:
            //draw_shape(texture, (shape_t)(draw->drawable));
        break;
        case SPRITE:
            //draw_sprite(texture, (sprite_t)(draw->drawable));
        break;
        case ENTITY:
            //draw_entity(texture, (entity_t)(draw->drawable));
        break;
        case TEXT:
            //draw_text(texture, (text_t)(draw->drawable));
        break;
    }
}
