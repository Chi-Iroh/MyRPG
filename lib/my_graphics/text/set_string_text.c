/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that initialize a text struct
*/
#include "../include/text.h"

void set_string_text(text_t * text, const char * string)
{
    text->string = (sfUint32 *)string;
    if (text->string != NULL) {
        sfText_setUnicodeString(text->text, text->string);
    }
}
