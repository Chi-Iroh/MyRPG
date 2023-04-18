/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that change the data struct
*/
#include "../include/draw.h"

void move_draw(draw_t * draw, sfVector2f offset)
{
    switch (draw->type) {
        case SHAPE:
            move_shape((shape_t *)(draw->drawable), offset);
        break;
        case SPRITE:
            move_sprite((sprite_t *)(draw->drawable), offset);
        break;
        case TEXT:
            move_text((text_t *)(draw->drawable), offset);
        break;
        default: break;
    }
}

void scale_draw(draw_t * draw, sfVector2f scale)
{
    switch (draw->type) {
        case SHAPE:
            scale_shape((shape_t *)(draw->drawable), scale);
        break;
        case SPRITE:
            scale_sprite((sprite_t *)(draw->drawable), scale);
        break;
        case TEXT:
            scale_text((text_t *)(draw->drawable), scale);
        break;
        default: break;
    }
}

void rotate_draw(draw_t * draw, float angle)
{
    switch (draw->type) {
        case SHAPE:
            rotate_shape((shape_t *)(draw->drawable), angle);
        break;
        case SPRITE:
            rotate_sprite((sprite_t *)(draw->drawable), angle);
        break;
        case TEXT:
            rotate_text((text_t *)(draw->drawable), angle);
        break;
        default: break;
    }
}

void modify_draw(draw_t * draw, sfVector2f offset,
                    sfVector2f scale, float angle)
{
    switch (draw->type) {
        case SHAPE:
            modify_shape((shape_t *)(draw->drawable), offset, scale, angle);
        break;
        case SPRITE:
            modify_sprite((sprite_t *)(draw->drawable), offset, scale, angle);
        break;
        case TEXT:
            modify_text((text_t *)(draw->drawable), offset, scale, angle);
        break;
        default: break;
    }
}
