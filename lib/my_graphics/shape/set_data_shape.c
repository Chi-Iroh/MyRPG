/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that set the caracteristics of the shape
*/
#include "../include/shape.h"

void set_data_shape(shape_t * shape, data_t * data)
{
    set_pos_shape(shape, data->position);
    set_size_shape(shape, data->size);
    set_angle_shape(shape, data->angle);
}
