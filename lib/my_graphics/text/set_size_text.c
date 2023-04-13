/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that initialize a text struct
*/
#include "../include/text.h"

void set_size_text(text_t * text, sfVector2f size)
{
    sfText_setCharacterSize(text->text, size.x);
}
