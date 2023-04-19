/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that create a text struct from parameters
*/
#include "../include/text.h"

text_t * create_text(const char * string, sfFont * font, sfColor color)
{
    text_t * text = malloc(sizeof(text_t));
    text->text = sfText_create();
    text->string = (sfUint32 *)string;
    text->font = font;
    text->color_in = color;
    text->color_out = color;
    text->thick = 0;
    sfText_setString(text->text, text->string);
    sfText_setCharacterSize(text->text, 100);
    return text;
}//sfText_setUnicodeString(text->text, text->string);
