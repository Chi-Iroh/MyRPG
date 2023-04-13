/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that initialize a text struct
*/
#include "../include/text.h"

text_t * init_text(void)
{
    text_t * text = malloc(sizeof(text_t));
    text->text = sfText_create();
    text->string = NULL;
    text->font = NULL;
    text->color = (sfColor){0.0, 0.0, 0.0, 0.0};
    return text;
}
