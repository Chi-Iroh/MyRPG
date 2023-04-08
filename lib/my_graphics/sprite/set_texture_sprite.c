/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that set the part of texture to display
*/
#include "../include/sprite.h"

void set_texture_sprite(sprite_t * sprite, sfTexture * texture, sfIntRect rect)
{
    sprite->texture = texture;
    sprite->rect = rect;
    sfSprite_setTextureRect(sprite->sprite, rect);
}