/*
** EPITECH PROJECT, 2023
** button_draw.c
** File description:
** -> Drawing button
*/

#include "button.h"

// button->title_pos MUSTN'T be BUTTON_TITLE_HIDDEN
static void draw_button_title(sfRenderWindow *window, button_t *button)
{
    const unsigned char_size = sfText_getCharacterSize(button->text);
    const sfVector2f above_pos = {
        .x = button->area.left,

        // casted to int to prevent underflow when button->area.top is 0
        .y = (int)(button->area.top - char_size)
    };
    const sfVector2f beneath_pos = {
        .x = button->area.left,
        .y = button->area.top + button->area.height
    };
    const sfVector2f *const pos = button->title_pos == BUTTON_TITLE_ABOVE ?
        &above_pos : &beneath_pos;

    if (button->title_pos == BUTTON_TITLE_MIDDLE) {
        resize_and_center_text(&button->area, button->text);
    } else {
        sfText_setPosition(button->text, *pos);
    }
    sfText_setCharacterSize(button->text, button->text_size);
    sfText_setFont(button->text, button->font);
    if (button->use_utf8_title) {
        sfText_setUnicodeString(button->text, button->title.utf8);
    } else {
        sfText_setString(button->text, button->title.ansi);
    }
    sfText_setFillColor(button->text, button->text_color);
    sfRenderWindow_drawText(window, button->text, NULL);
}

void draw_button(sfRenderWindow *window, button_t *button)
{
    sfVector2u texture_size = { 0, 0 };

    convert_float_rect_to_rectangle_shape(&button->area, button->shape);
    if (button->fill_mode == BUTTON_FILL_WITH_SPRITE) {
        if (button->keep_texture_size) {
            texture_size = sfTexture_getSize(button->fill.texture);
            button->area.width = texture_size.x;
            button->area.height = texture_size.y;
        }
        sfRectangleShape_setFillColor(button->shape, sfWhite);
        sfRectangleShape_setTexture(button->shape, button->fill.texture, true);
    } else {
        sfRectangleShape_setFillColor(button->shape, button->fill.color);
    }
    convert_rectangle_shape_to_float_rect(button->shape, &button->area);
    sfRenderWindow_drawRectangleShape(window, button->shape, NULL);
    if (button->fill_mode == BUTTON_FILL_UNINITIALIZED) {
        return;
    } else if (button->title_pos != BUTTON_TITLE_HIDDEN) {
        draw_button_title(window, button);
    }
}
