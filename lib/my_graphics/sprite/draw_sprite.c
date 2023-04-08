/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that draw sprite to layer
*/
#include "../include/sprite.h"

void draw_sprite(sfRenderTexture * texture, sprite_t * sprite)
{
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfRenderTexture_drawSprite(texture, sprite, NULL);
    if (!sprite->animated) {
        return;
    }
    if (sprite->current < sprite->nb_frame - 1) {
        sprite->current++;
        sprite->rect = next_rectangle(sprite->rect);
    } else {
        sprite->current = 0;
        sprite->rect.top -= sprite->rect.width * (sprite->nb_frame - 1);
    }
}
