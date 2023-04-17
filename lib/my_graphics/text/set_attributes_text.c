/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that initialize a text struct
*/
#include "../include/text.h"

void set_color_in_text(text_t * text, sfColor color)
{
    text->color_in = color;
    sfText_setFillColor(text->text, color);
}

void set_color_out_text(text_t * text, sfColor color)
{
    text->color_in = color;
    sfText_setOutlineColor(text->text, color);
}

void set_thick_text(text_t * text, int thick)
{
    text->thick = thick;
    sfText_setOutlineThickness(text->text, thick);
}

void set_attributes_text(text_t * text, sfColor color_in,
                    sfColor color_out, int thick)
{
    set_color_in_text(text, color_in);
    set_color_out_text(text, color_out);
    set_thick_text(text, thick);
}
