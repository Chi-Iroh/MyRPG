/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that free a text struct
*/
#include "../include/text.h"

void free_text(text_t * text)
{
    sfText_destroy(text->text);
    sfFont_destroy(text->font);
    free(text);
}
