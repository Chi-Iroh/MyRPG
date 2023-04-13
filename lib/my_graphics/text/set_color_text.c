/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that initialize a text struct
*/
#include "../include/text.h"

void set_color_text(text_t * text, sfColor color)
{
    text->color = color;
    sfText_setColor(text->text, color);
}
