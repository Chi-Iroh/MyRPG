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
    sfSprite_setTexture(sprite->sprite, texture, sfTrue);
    sprite->rect = rect;
    sfSprite_setTextureRect(sprite->sprite, rect);
    if (rect.width != 0 && rect.height != 0) {
        sfSprite_setTextureRect(sprite->sprite, rect);
    }
}
