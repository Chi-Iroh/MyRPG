/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that create a sprite struct from parameters
*/
#include "../include/sprite.h"

sfVector2f get_position_sprite(sprite_t * sprite)
{
    sfVector2f vect = set_2vector(0.f, 0.f);
    vect = sfSprite_getPosition((sfSprite *)(sprite->sprite));
    return vect;
}

float get_rotation_sprite(sprite_t * sprite)
{
    float angle = 0.f;
    angle = sfSprite_getRotation((sfSprite *)(sprite->sprite));
    return angle;
}

sfVector2f get_scale_sprite(sprite_t * sprite)
{
    sfVector2f vect = set_2vector(0.f, 0.f);
    vect = sfSprite_getScale((sfSprite *)(sprite->sprite));
    return vect;
}

sfVector2f get_origin_sprite(sprite_t * sprite)
{
    sfVector2f vect = set_2vector(0.f, 0.f);
    vect = sfSprite_getOrigin((sfSprite *)(sprite->sprite));
    return vect;
}
