/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that initialize a text struct
*/
#include "../include/text.h"

void set_angle_text(text_t * text, float angle)
{
    sfText_setRotation(text->text, angle);
}
