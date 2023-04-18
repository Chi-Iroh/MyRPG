/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that create a shape struct from parameters
*/
#include "../include/text.h"

void move_text(text_t * text, sfVector2f offset)
{
    sfText_move((sfText *)(text->text), offset);
}

void scale_text(text_t * text, sfVector2f scale)
{
    sfText_scale((sfText *)(text->text), scale);
}

void rotate_text(text_t * text, float angle)
{
    sfText_rotate((sfText *)(text->text), angle);
}

void modify_text(text_t * text, sfVector2f offset,
                    sfVector2f scale, float angle)
{
    move_text(text, offset);
    scale_text(text, scale);
    rotate_text(text, angle);
}
