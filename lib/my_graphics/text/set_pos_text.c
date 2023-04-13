/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that initialize a text struct
*/
#include "../include/text.h"

void set_pos_text(text_t * text, sfVector3f position)
{
    sfVector2f pos = set_2vector(position.x, position.z);
    sfText_setPosition(text->text, pos);
}
