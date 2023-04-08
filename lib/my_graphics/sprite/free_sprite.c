/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that free a sprite struct
*/
#include "../include/sprite.h"

void free_sprite(sprite_t * sprite)
{
    sfSprite_destroy(sprite->sprite);
    free(sprite);
}
