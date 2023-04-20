/*
** EPITECH PROJECT, 2023
** init_free.c
** File description:
** -> Initialization and free
*/

#include <stdbool.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <my_macros.h>
#include <button.h>
#include <character_menu.h>

static float character_menu_button_width(button_t *button)
{
    const float area_width = button->area.width;
    const float title_width = sfText_getGlobalBounds(button->text).width;

    return MAX(area_width, title_width);
}

static void character_menu_init_button_title
(character_menu_t *menu, unsigned i)
{
    float previous_button_width = 0;
    float previous_button_pos = 0;

    menu->buttons[i].title.utf8 = (sfUint32*)CHARACTER_NAMES_UTF8[i];
    menu->buttons[i].use_utf8_title = true;
    menu->buttons[i].text_size = 16;
    menu->buttons[i].font = menu->font;
    update_button_title(&menu->buttons[i]);
    menu->buttons[i].title_pos = BUTTON_TITLE_BENEATH;
    if (i == 0) {
        menu->buttons[i].area.left = 0;
        return;
    }
    previous_button_width = character_menu_button_width(&menu->buttons[i - 1]);
    previous_button_pos = menu->buttons[i - 1].area.left;
    previous_button_pos += previous_button_width;
    menu->buttons[i].area.left = 25 + previous_button_pos;
}

static bool character_menu_allocate_buttons(character_menu_t *menu)
{
    bool status = menu != NULL;
    const char *filename = NULL;

    for (unsigned i = 0; status && i < N_CHARACTERS; i++) {
        filename = SPRITES_FILENAMES[i][0];
        status &= init_button_base(&menu->buttons[i]);
        status &= button_fill_sprite(&menu->buttons[i], filename);
        if (!status) {
            character_menu_free(menu);
            return false;
        }
        menu->allocated_buttons++;
        character_menu_init_button_title(menu, i);
    }
    return true;
}

bool character_menu_init(character_menu_t *menu)
{
    const sfVideoMode resolution = sfVideoMode_getDesktopMode();
    const sfWindowStyle style = sfTitlebar | sfClose;
    const char *const title = "Choose a Character";
    bool status = menu != NULL;

    RETURN_VALUE_IF(!status, false);
    *menu = (character_menu_t) {
        .clock = sfClock_create(),
        .font = sfFont_createFromFile("fonts/Arial.ttf"),
        .window = sfRenderWindow_create(resolution, title, style, NULL),
        .allocated_buttons = 0
    };
    status &= menu->clock && menu->font && menu->window;
    status &= character_menu_allocate_buttons(menu);
    if (!status) {
        character_menu_free(menu);
    }
    return status;
}

void character_menu_free(character_menu_t *menu)
{
    RETURN_IF(!menu);
    FREE_IF_ALLOCATED(menu->clock, sfClock_destroy);
    FREE_IF_ALLOCATED(menu->font, sfFont_destroy);
    FREE_IF_ALLOCATED(menu->window, sfRenderWindow_destroy);
    for (unsigned i = 0; i < menu->allocated_buttons; i++) {
        free_button(&menu->buttons[i]);
    }
}
