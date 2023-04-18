/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that create a text struct from parameters
*/
#include "../include/text.h"

sfVector2f get_position_text(text_t * text)
{
    sfVector2f vect = set_2vector(0.f, 0.f);
    vect = sfText_getPosition((sfText *)(text->text));
    return vect;
}

float get_rotation_sprite(text_t * text)
{
    float angle = 0.f;
    angle = sfText_getRotation((sfText *)(text->text));
    return angle;
}

sfVector2f get_scale_sprite(text_t * text)
{
    sfVector2f vect = set_2vector(0.f, 0.f);
    vect = sfText_getScale((sfText *)(text->text));
    return vect;
}

sfVector2f get_origin_sprite(text_t * text)
{
    sfVector2f vect = set_2vector(0.f, 0.f);
    vect = sfText_getOrigin((sfText *)(text->text));
    return vect;
}
