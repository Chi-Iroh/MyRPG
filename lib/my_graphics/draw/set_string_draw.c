/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that change the data struct
*/
#include "../include/draw.h"

void set_string_draw(draw_t * draw, const char * string)
{
    if (draw->type != TEXT) {
        return;
    }
    set_string_text((text_t *)(draw->drawable), string);
}
