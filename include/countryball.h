/*
** EPITECH PROJECT, 2023
** countryball.h
** File description:
** -> Declarations for countryball animation.
*/

#pragma once

#include <stdbool.h>
#include <SFML/Graphics.h>

typedef struct countryball_s {
    sfRenderWindow *window;
    sfTexture *spritesheet;
    sfSprite *sprite;
    sfClock *clock;
} countryball_t;

bool countryball_49_3(void);

extern const char *const SPRITESHEET_PATH;
extern const unsigned N_COLUMNS;
extern const unsigned N_LINES;
extern const unsigned N_FRAMES;
extern const unsigned FRAME_DELAY_MICROSECONDS;
extern const sfVector2f FRAME_SIZE;
