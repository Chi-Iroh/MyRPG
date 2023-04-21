/*
** EPITECH PROJECT, 2023
** speech_bubble.h
** File description:
** -> Speech bubble display.
*/

#pragma once

#include <my_graphics.h>

typedef struct {
    char *str;
    layer_t *layer;
    sfTexture *texture;
    sfVector2f size;
    sfIntRect rect;
    sfVector3f pos;
    data_t *bubble_data;
    sprite_t *bubble_sprite;
    draw_t *bubble_draw;
    data_t *text_data;
    text_t *text;
    draw_t *text_draw;
} speech_bubble_t;

bool speech_bubble_draw_text
(sfVector3f bottom_left_pos, speech_bubble_t *bubble);
void speech_bubble_free(speech_bubble_t *speech_bubble);

extern const unsigned SPEECH_BUBBLE_HEIGHT;
extern const unsigned SPEECH_BUBBLE_WIDTH;
