/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that initialize a text struct
*/
#include "../include/text.h"

void draw_text(sfRenderTexture * texture, text_t * text)
{
    set_color_text(text, text->color);
    set_font_text(text, text->font);
    sfRenderTexture_drawText(texture, text->text, NULL);
}
