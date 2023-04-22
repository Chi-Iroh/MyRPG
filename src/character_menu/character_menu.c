/*
** EPITECH PROJECT, 2023
** button.c
** File description:
** -> Button implementation in pure CSFML
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <my_macros.h>
#include <my.h>
#include <button.h>
#include <character_menu.h>
#include <my_rpg.h>

const char *SPRITES_FILENAMES[N_CHARACTERS][2] = {
    SPRITE_FILENAMES("cheminot"),
    SPRITE_FILENAMES("docteur"),
    SPRITE_FILENAMES("étudiant_en_arts"),
    SPRITE_FILENAMES("étudiant_sciences_po"),
    SPRITE_FILENAMES("fils_du_préfet"),
    SPRITE_FILENAMES("ouvrier"),
    SPRITE_FILENAMES("casseur")
};

const sfUint32 *CHARACTER_NAMES_UTF8[N_CHARACTERS] = {
    UTF8("Le Cheminot"),
    UTF8("Le Docteur"),
    UTF8("L'Étudiant en Arts"),
    UTF8("L'Étudiant de Sciences Po"),
    UTF8("Le Fils du Préfet"),
    UTF8("L'Ouvrier"),
    UTF8("Le Casseur")
};

const char *CHARACTER_NAMES_ANSI[N_CHARACTERS] = {
    "Le Cheminot",
    "Le Docteur",
    "L'Étudiant en Arts",
    "L'Étudiant de Sciences Po",
    "Le Fils du Préfet",
    "L'Ouvrier",
    "Le Casseur"
};

static void character_menu_check_sprite_click
(character_menu_t *menu, character_type_t *character)
{
    for (unsigned i = 0; i < N_CHARACTERS; i++) {
        if (is_mouse_in_rect(menu->window, &menu->buttons[i].area)) {
            sfRenderWindow_close(menu->window);
            *character = (character_type_t)i;
            break;
        }
    }
}

static void character_menu_handle_events
(character_menu_t *menu, character_type_t *character)
{
    while (sfRenderWindow_pollEvent(menu->window, &menu->event)) {
        switch (menu->event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(menu->window);
            break;
        case sfEvtMouseButtonPressed:
            character_menu_check_sprite_click(menu, character);
            break;
        default:
            break;
        }
    }
}

static bool character_menu_rotate_sprites(character_menu_t *menu)
{
    static bool are_characters_from_behind = false;
    const char *filename = NULL;

    for (unsigned i = 0; i < N_CHARACTERS; i++) {
        filename = SPRITES_FILENAMES[i][are_characters_from_behind];
        if (!button_fill_sprite(&menu->buttons[i], filename)) {
            character_menu_free(menu);
            return false;
        }
    }
    if (sfClock_getElapsedTime(menu->clock).microseconds < 500'000) {
        return true;
    }
    are_characters_from_behind ^= 1;
    sfClock_restart(menu->clock);
    return true;
}

static void character_menu_draw(character_menu_t *menu)
{
    sfRenderWindow_clear(menu->window, sfCyan);
    for (unsigned i = 0; i < N_CHARACTERS; i++) {
        draw_button(menu->window, &menu->buttons[i]);
    }
    sfRenderWindow_display(menu->window);
}

character_type_t select_character(void)
{
    character_menu_t menu;
    character_type_t character = CHARACTER_NONE;

    if (!character_menu_init(&menu)) {
        return CHARACTER_ERROR;
    }
    while (sfRenderWindow_isOpen(menu.window)) {
        sfRenderWindow_setPosition(menu.window, (sfVector2i){540, 500});
        if (!sfRenderWindow_hasFocus(menu.window))
            sfRenderWindow_requestFocus(menu.window);
        character_menu_handle_events(&menu, &character);
        character_menu_draw(&menu);
        character_menu_rotate_sprites(&menu);
        character_menu_shrink_window(menu.window, &BOTTOM_RIGHT_BUTTON(&menu));
    }
    character_menu_free(&menu);
    return character;
}
