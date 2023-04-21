/*
** EPITECH PROJECT, 2023
** countryball.c
** File description:
** -> Countryball animation of 49.3
*/

#include <stdbool.h>
#include <my_macros.h>
#include <countryball.h>

const char *const SPRITESHEET_PATH =
    "images/spritesheets/49_3_spritesheet.png";

const unsigned N_COLUMNS = 6;
const unsigned N_LINES = 8;
const unsigned N_FRAMES = N_COLUMNS * N_LINES;
const unsigned FRAME_DELAY_MICROSECONDS = 100'000;

const sfVector2f FRAME_SIZE = {
    .x = 579,
    .y = 454
};

static void countryball_free(countryball_t *countryball)
{
    RETURN_IF(!countryball);
    FREE_IF_ALLOCATED(countryball->window, sfRenderWindow_destroy);
    FREE_IF_ALLOCATED(countryball->spritesheet, sfTexture_destroy);
    FREE_IF_ALLOCATED(countryball->sprite, sfSprite_destroy);
    FREE_IF_ALLOCATED(countryball->clock, sfClock_destroy);
}

static bool countryball_init(countryball_t *countryball)
{
    const sfWindowStyle style = sfTitlebar | sfClose;
    const sfVideoMode mode = {
        .width = FRAME_SIZE.x,
        .height = FRAME_SIZE.y,
        .bitsPerPixel = 32
    };

    RETURN_VALUE_IF(!countryball, false);
    countryball->window = sfRenderWindow_create(mode, "49.3", style, NULL);
    countryball->spritesheet =
        sfTexture_createFromFile(SPRITESHEET_PATH, NULL);
    countryball->sprite = sfSprite_create();
    countryball->clock = sfClock_create();
    if (!countryball->window || !countryball->spritesheet
        || !countryball->sprite || !countryball->clock) {
            countryball_free(countryball);
            return false;
    }
    sfSprite_setTexture(countryball->sprite, countryball->spritesheet, false);
    return true;
}

static void countryball_draw(countryball_t *countryball, bool draw_next)
{
    static unsigned n_line = 0;
    static unsigned n_column = 0;
    const sfIntRect frame = {
        .width = FRAME_SIZE.x,
        .height = FRAME_SIZE.y,
        .left = n_column * FRAME_SIZE.x,
        .top = n_line * FRAME_SIZE.y,
    };

    sfSprite_setTextureRect(countryball->sprite, frame);
    sfRenderWindow_drawSprite
        (countryball->window, countryball->sprite, NULL);
    if (draw_next) {
        n_line += n_column == N_COLUMNS;
        n_line *= n_line != N_LINES;
        n_column = n_column == N_COLUMNS ? 0 : n_column + 1;
    }
}

static void countryball_handle_events(countryball_t *countryball)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(countryball->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(countryball->window);
            return;
        }
        if (!sfRenderWindow_hasFocus(countryball->window)) {
            sfRenderWindow_requestFocus(countryball->window);
        }
    }
}

bool countryball_49_3(void)
{
    countryball_t countryball;
    bool is_wait_time_ok = false;

    RETURN_VALUE_IF(!countryball_init(&countryball), false);
    while (sfRenderWindow_isOpen(countryball.window)) {
        is_wait_time_ok = sfClock_getElapsedTime
            (countryball.clock).microseconds >= FRAME_DELAY_MICROSECONDS;
        countryball_handle_events(&countryball);
        sfRenderWindow_clear(countryball.window, sfWhite);
        countryball_draw(&countryball, is_wait_time_ok);
        sfRenderWindow_display(countryball.window);
        if (is_wait_time_ok) {
            sfClock_restart(countryball.clock);
        }
    }
    countryball_free(&countryball);
    return true;
}