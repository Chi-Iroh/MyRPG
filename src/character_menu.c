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
    (sfUint32*)L"Le Cheminot",
    (sfUint32*)L"Le Docteur",
    (sfUint32*)L"L'Étudiant en Arts",
    (sfUint32*)L"L'Étudiant de Sciences Po",
    (sfUint32*)L"Le Fils du Préfet",
    (sfUint32*)L"L'Ouvrier",
    (sfUint32*)L"Le Casseur"
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

const float DESCRIPTION_Y_OFFSET = 100.f;

static sfVector2u get_minimal_window(button_t *bottom_right_button)
{
    sfText *const button_text = bottom_right_button->text;
    const sfFloatRect title_size = sfText_getGlobalBounds(button_text);
    const button_title_pos_t title_pos = bottom_right_button->title_pos;
    sfFloatRect *const rect = &bottom_right_button->area;
    sfVector2u minimal_size = {
        .x = rect->left + rect->width,
        .y = rect->top + rect->height
    };

    if (rect->height < title_size.height) {
        minimal_size.y += title_size.height - rect->height;
    }
    if (rect->width < title_size.width) {
        minimal_size.x += title_size.width - rect->width;
    }
    if (title_pos == BUTTON_TITLE_BENEATH || title_pos == BUTTON_TITLE_ABOVE) {
        minimal_size.y += bottom_right_button->text_size;
    }
    return minimal_size;
}

bool shrink_window(sfRenderWindow *window, button_t *bottom_right_button)
{
    const sfVector2u current_size = sfRenderWindow_getSize(window);
    const sfFloatRect window_rect = {
        .left = 0,
        .top = 0,
        .width = current_size.x,
        .height = current_size.y
    };
    sfView *view = sfView_createFromRect(window_rect);

    if (!view) {
        return false;
    }
    sfRenderWindow_setSize(window, get_minimal_window(bottom_right_button));
    sfRenderWindow_setView(window, view);
    sfView_destroy(view);
    return true;
}

character_type_t select_character(void)
{
    bool are_characters_from_back = false;
    bool has_chosen = false;
    const sfVideoMode resolution = sfVideoMode_getDesktopMode();
    sfRenderWindow *window = sfRenderWindow_create(resolution, "Choose a Character", sfTitlebar | sfClose, NULL);
    sfEvent event;
    button_t buttons[N_CHARACTERS];
    sfFont *font = sfFont_createFromFile("fonts/Arial.ttf");
    sfMusic *music = sfMusic_createFromFile("musics/Kevin MacLeod - Happy Bee.ogg");
    sfClock *clock = sfClock_create();

    if (!window || !font || !music || !clock) {
        FREE_IF_ALLOCATED(font, sfFont_destroy);
        FREE_IF_ALLOCATED(music, sfMusic_destroy);
        FREE_IF_ALLOCATED(clock, sfClock_destroy);
        FREE_IF_ALLOCATED(window, sfRenderWindow_destroy);
        return 1;
    }
    sfMusic_play(music);

    for (unsigned i = 0; i < N_CHARACTERS; i++) {
        if (!init_button_base(&buttons[i]) || !button_fill_sprite(&buttons[i], FILENAMES[i][0])) {
            for (unsigned j = 0; j <= i; j++) {
                free_button(&buttons[i]);
            }
            sfFont_destroy(font);
            sfMusic_destroy(music);
            sfClock_destroy(clock);
            sfRenderWindow_destroy(window);
            return 1;
        }
        buttons[i].title.utf8 = (sfUint32*)CHARACTER_NAMES_UTF8[i];
        buttons[i].use_utf8_title = true;
        buttons[i].text_size = 16;
        buttons[i].font = font;
        update_button_title(&buttons[i]);
        const float previous_title_width = i == 0 ? 0.f : sfText_getGlobalBounds(buttons[i - 1].text).width;
        buttons[i].area.left = i == 0 ? 0 : 25 + buttons[i - 1].area.left + MAX(buttons[i - 1].area.width, previous_title_width);
        buttons[i].title_pos = BUTTON_TITLE_BENEATH;
    }

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            switch (event.type) {
            case sfEvtClosed:
                sfRenderWindow_close(window);
                break;

            case sfEvtMouseButtonPressed:
                for (unsigned i = 0; i < N_CHARACTERS; i++) {
                    if (is_mouse_in_rect(window, &buttons[i].area)) {
                        my_printf("Vous avez choisi: %s.\n", CHARACTER_NAMES_ANSI[i]);
                        sfRenderWindow_close(window);
                        has_chosen = true;
                        break;
                    }
                }

            default:
                break;
            }
        }
        sfRenderWindow_clear(window, sfCyan);
        for (unsigned i = 0; i < N_CHARACTERS; i++) {
            draw_button(window, &buttons[i]);
        }
        sfRenderWindow_display(window);
        for (unsigned i = 0; i < N_CHARACTERS; i++) {
            if (!button_fill_sprite(&buttons[i], FILENAMES[i][are_characters_from_back])) {
                for (unsigned j = 0; j < i; j++) {
                    if (j != i) {
                        free_button(&buttons[j]);
                    }
                }
                sfFont_destroy(font);
                sfMusic_destroy(music);
                sfClock_destroy(clock);
                sfRenderWindow_destroy(window);
                return 1;
            }
        }
        if (sfClock_getElapsedTime(clock).microseconds < 500'000) {
            continue;
        }
        if (!shrink_window(window, &buttons[N_CHARACTERS - 1])) {
            for (unsigned i = 0; i < N_CHARACTERS; i++) {
                free_button(&buttons[i]);
            }
            sfFont_destroy(font);
            sfMusic_destroy(music);
            sfClock_destroy(clock);
            sfRenderWindow_destroy(window);
            return 1;
        }
        are_characters_from_back ^= 1;
        sfClock_restart(clock);
    }
    for (unsigned i = 0; i < N_CHARACTERS; i++) {
        free_button(&buttons[i]);
    }
    sfFont_destroy(font);
    sfMusic_stop(music);
    sfMusic_destroy(music);
    sfClock_destroy(clock);
    sfRenderWindow_destroy(window);
    if (!has_chosen) {
        my_puts("Vous allez jouer comment si vous fermez la fenêtre, hein ??");
    }
    return 0;
}
