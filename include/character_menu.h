/*
** EPITECH PROJECT, 2023
** character_menu.h
** File description:
** -> A menu to select a character.
*/

#pragma once

#include <SFML/System.h>

#define N_CHARACTERS (7)
#define SPRITE_FILENAMES(sprite) \
{ "images/" sprite ".png", "images/" sprite "_de_dos.png" }

typedef struct {
    sfRenderWindow *window;
    sfMusic *music;
} character_menu_t;

extern const char *FILENAMES[N_CHARACTERS][2];
extern const sfUint32 *CHARACTER_NAMES_UTF8[N_CHARACTERS];
extern const char *CHARACTER_NAMES_ANSI[N_CHARACTERS];
extern const float DESCRIPTION_Y_OFFSET;

character_type_t select_character(void);
