/*
** EPITECH PROJECT, 2022
** My_rpg_tmp
** File description:
** progress_bar.c
*/

#include "../include/my_rpg.h"
#include "../lib/my_graphics/my_graphics.h"

void init_progress_bar(window_t *wd, progress_bar_t *bar, data_t *data, shape_t *shape)
{
    data_t *data_fill = create_data(set_3vector
    (data->position.x, data->position.y, 0),
    set_2vector(250, 35), 0.f);
    shape_t *shape_box = create_shape(RECT, sfWhite, sfBlack, 3);
    *bar = (progress_bar_t) {
        .min = 0,
        .max = 100,
        .current = 50,
        .area = { .top = 0, .left = 0, .height = 100, .width = 250 },
        .draw = create_draw(shape_box, SHAPE, data),
        .fill = create_draw(shape, SHAPE, data_fill)
    };
    append_draw_layer(wd->ui, bar->fill);
    append_draw_layer(wd->ui, bar->draw);
}

/*void set_position_and_size_with_float_rect
(sfRectangleShape *shape, sfFloatRect *rect)
{
    const sfVector2f pos = { .x = rect->left, .y = rect->top };
    const sfVector2f size = { .x = rect->width, .y = rect->height };
    sfRectangleShape_setPosition(shape, pos);
    sfRectangleShape_setSize(shape, size);
}

void compute_fill_area(progress_bar_t *bar)
{
    bar->fill_area = (sfFloatRect) {
        .top = bar->area.top,
        .left = bar->area.left,
        .height = bar->area.height,
        .width = bar->area.width * (bar->current / (bar->max - bar->min))
    };
}

void draw_progress_bar(sfRenderWindow *window, progress_bar_t *bar)
{
    set_position_and_size_with_float_rect(bar->shape, &bar->area);
    sfRectangleShape_setFillColor(bar->shape, bar->background_color);
    sfRenderWindow_drawRectangleShape(window, bar->shape, NULL);
    compute_fill_area(bar);
    set_position_and_size_with_float_rect(bar->fill, &bar->fill_area);
    sfRectangleShape_setFillColor(bar->fill, bar->fill_color);
    sfRenderWindow_drawRectangleShape(window, bar->fill, NULL);
}*/
