#include <stdbool.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include "../..//include/my.h"
#include "../..//include/my_macros.h"

typedef struct {
    long double min;
    long double max;
    long double current;
    long double step;
    sfColor background_color;
    sfColor fill_color;
    sfFloatRect area;
    sfFloatRect fill_area;
    sfRectangleShape *shape;
    sfRectangleShape *fill;
} progress_bar_t;

void destroy_progress_bar(progress_bar_t *bar)
{
    FREE_IF_ALLOCATED(bar->shape, sfRectangleShape_destroy);
    FREE_IF_ALLOCATED(bar->fill, sfRectangleShape_destroy);
}

/*
    Properly frees memories in case of error during allocation.
*/
bool init_progress_bar(progress_bar_t *bar)
{
    *bar = (progress_bar_t) {
        .min = 0,
        .max = 100,
        .current = 50,
        .step = 1,
        .background_color = sfBlack,
        .fill_color = sfGreen,
        .area = { .top = 0, .left = 0, .height = 100, .width = 250 },
        .shape = sfRectangleShape_create(),
        .fill = sfRectangleShape_create()
    };
    if (!bar->shape || !bar->fill) {
        destroy_progress_bar(bar);
        return false;
    }
    return true;
}

void set_position_and_size_with_float_rect
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
}

int main(void)
{
    progress_bar_t bar;
    const sfVideoMode resolution = {
        .height = 1'000,
        .width = 1'000,
        .bitsPerPixel = 32
    };
    sfRenderWindow *window = sfRenderWindow_create(resolution, "Progress bar test", sfDefaultStyle, NULL);
    sfEvent event;

    if (!window || !init_progress_bar(&bar)) {
        FREE_IF_ALLOCATED(window, sfRenderWindow_destroy);
        return 1;
    }
    my_puts("Scroll using your mouse to change the progress bar value.");
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            switch (event.type) {
            case sfEvtClosed:
                sfRenderWindow_close(window);
                break;

            case sfEvtMouseWheelScrolled:
                if (bar.current + bar.step <= bar.max && event.mouseWheelScroll.delta > 0) {
                    bar.current += bar.step;
                } else if (bar.current - bar.step >= bar.min && event.mouseWheelScroll.delta < 0) {
                    bar.current -= bar.step;
                }
                break;

            default:
                break;
            }
        }
        sfRenderWindow_clear(window, sfCyan);
        draw_progress_bar(window, &bar);
        sfRenderWindow_display(window);
    }
    destroy_progress_bar(&bar);
    sfRenderWindow_destroy(window);
    return 0;
}
