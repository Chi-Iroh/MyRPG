/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that initialize a text struct
*/
#include "../include/text.h"

void set_data_text(text_t * text, data_t * data)
{
    set_pos_text(text, data->position);
    set_size_text(text, data->size);
    set_angle_text(text, data->angle);
}
