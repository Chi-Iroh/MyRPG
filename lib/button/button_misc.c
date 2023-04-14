/*
** EPITECH PROJECT, 2023
** button_misc.c
** File description:
** -> Miscelleanous functions
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include <my.h>
#include <my_macros.h>

void convert_float_rect_to_rectangle_shape
(sfFloatRect *rect, sfRectangleShape *shape)
{
    const sfVector2f pos = { .x = rect->left, .y = rect->top };
    const sfVector2f size = { .x = rect->width, .y = rect->height };

    sfRectangleShape_setPosition(shape, pos);
    sfRectangleShape_setSize(shape, size);
}

void convert_rectangle_shape_to_float_rect
(sfRectangleShape *shape, sfFloatRect *rect)
{
    const sfVector2f pos = sfRectangleShape_getPosition(shape);
    const sfVector2f size = sfRectangleShape_getSize(shape);

    *rect = (sfFloatRect) {
        .left = pos.x,
        .width = size.x,
        .top = pos.y,
        .height = size.y
    };
}

bool is_mouse_in_rect(sfRenderWindow *window, sfFloatRect *rect)
{
    const sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x < rect->left || mouse.x > rect->left + rect->width) {
        return false;
    }
    if (mouse.y < rect->top || mouse.y > rect->top + rect->height) {
        return false;
    }
    return true;
}

void resize_and_center_text(sfFloatRect *rect, sfText *text)
{
    const size_t text_length = my_strlen(sfText_getString(text));
    const int char_size = MIN(rect->height, rect->width / text_length);
    sfVector2f pos = { 0, 0 };
    sfFloatRect text_area;

    sfText_setCharacterSize(text, char_size);
    text_area = sfText_getGlobalBounds(text);
    pos = (sfVector2f) {
        .x = rect->left + (rect->width - text_area.width) / 2,
        .y = rect->top + (rect->height - text_area.height) / 2
    };
    sfText_setPosition(text, pos);
}
