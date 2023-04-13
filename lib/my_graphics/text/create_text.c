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
    text->string = (sfUint32 *)L(string);
    text->font = font;
    text->color = color;
    sfText_setUnicodeString(text->text, text->string);
    return text;
}
