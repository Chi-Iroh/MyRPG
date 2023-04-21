/*
** EPITECH PROJECT, 2023
** speech_bubble.c
** File description:
** -> Displays text in a speech bubble
*/

#include <my_graphics.h>
#include <my_macros.h>
#include <speech_bubble.h>
#include <my_rpg.h>

const unsigned SPEECH_BUBBLE_HEIGHT = 24;
const unsigned SPEECH_BUBBLE_WIDTH = 96;

void speech_bubble_free(speech_bubble_t *speech_bubble)
{
    RETURN_IF(!speech_bubble);
    FREE_IF_ALLOCATED(speech_bubble->bubble_data, free);
    FREE_IF_ALLOCATED(speech_bubble->bubble_sprite, free_sprite);
    FREE_IF_ALLOCATED(speech_bubble->bubble_draw, free_single_draw);
    FREE_IF_ALLOCATED(speech_bubble->text_data, free);
    FREE_IF_ALLOCATED(speech_bubble->text, free_text);
    FREE_IF_ALLOCATED(speech_bubble->text_draw, free_single_draw);
}

static bool speech_bubble_text_alloc(speech_bubble_t *bubble)
{
    const sfVector3f pos = {
        .x = bubble->pos.x + 10,
        .y = bubble->pos.y - SPEECH_BUBBLE_HEIGHT + 15,
        .z = bubble->pos.z
    };
    const sfColor black = sfBlack;
    data_t *data = create_data(pos, bubble->size, 0);
    text_t *text = data ? create_text(bubble->str, NULL, black) : NULL;
    draw_t *draw = text ? create_draw(text, SPRITE, data) : NULL;

    bubble->text_data = data;
    bubble->text = text;
    bubble->text_draw = draw;
    if (!draw) {
        speech_bubble_free(bubble);
        return false;
    }
    return true;
}

static bool speech_bubble_alloc(speech_bubble_t *bubble)
{
    const sfVector3f pos = {
        .x = bubble->pos.x,
        .y = bubble->pos.y - SPEECH_BUBBLE_HEIGHT,
        .z = bubble->pos.z
    };
    data_t *data = create_data(pos, bubble->size, 0);
    sprite_t *sprite = data ? create_sprite(bubble->texture, bubble->rect) : NULL;
    draw_t *draw = sprite ? create_draw(sprite, SPRITE, data) : NULL;

    bubble->bubble_data = data;
    bubble->bubble_sprite = sprite;
    bubble->bubble_draw = draw;
    if (!draw) {
        speech_bubble_free(bubble);
        return false;
    }
    return true;
}

static void speech_bubble_init
(sfVector3f bottom_left_pos, speech_bubble_t *bubble)
{
    bubble->size = (sfVector2f) {
        .x = SPEECH_BUBBLE_WIDTH,
        .y = SPEECH_BUBBLE_HEIGHT
    };
    bubble->rect = (sfIntRect) {
        .height = SPEECH_BUBBLE_HEIGHT,
        .width = SPEECH_BUBBLE_WIDTH,
        .top = bottom_left_pos.y - SPEECH_BUBBLE_HEIGHT,
        .left = bottom_left_pos.x
    };
    bubble->pos = bottom_left_pos;
    bubble->bubble_data = NULL;
    bubble->bubble_draw = NULL;
    bubble->bubble_sprite = NULL;
    bubble->text = NULL;
    bubble->text_data = NULL;
    bubble->text_draw = NULL;
}


bool speech_bubble_draw_text
(sfVector3f bottom_left_pos, speech_bubble_t *bubble)
{
    bool status = bubble && bubble->layer && bubble->texture && bubble->str;

    RETURN_VALUE_IF(!status, false);
    speech_bubble_init(bottom_left_pos, bubble);
    status = status && speech_bubble_alloc(bubble);
    status = status && speech_bubble_text_alloc(bubble);
    if (!status) {
        speech_bubble_free(bubble);
        return false;
    }
    append_draw_layer(bubble->layer, bubble->bubble_draw);
    append_draw_layer(bubble->layer, bubble->text_draw);
    return true;
}