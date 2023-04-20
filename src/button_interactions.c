/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** button_interactions.c
*/

#include <my_rpg.h>
#include <my_graphics.h>
#include <audio.h>
#include <my_macros.h>

static void handle_button_click
(list_button_t* all_btn, sfMouseButtonEvent *event, game_src_t* g_src)
{
    static const sfColor color = {
        .r = 220,
        .g = 220,
        .b = 220,
        .a = 255
    };

    if (all_btn->btn->is_clicked(all_btn->btn, event)) {
        set_color_in_draw(all_btn->btn->rect, color);
        sfSound_play(g_src->audio.explosion_sfx.sound);
    }
}

void button_pressed(window_t* wd, list_button_t* all_btn,
    sfMouseButtonEvent evt, game_src_t* g_src)
{
    while (all_btn != NULL) {
        if (all_btn->btn->layer_on->show && all_btn->btn->rect->show) {
            handle_button_click(all_btn, &evt, g_src);
        } else {
            all_btn->btn->state = NONE;
        }
        all_btn = all_btn->next;
    }
}

void sliding_button_moved(list_button_t* all_btn, sfMouseMoveEvent evt)
{
    while (all_btn != NULL) {
        if (all_btn->btn->s_btn && IS_PRESSED(all_btn->btn)) {
            move_sliding_button_btn(evt, all_btn->btn->s_btn);
        }
        all_btn = all_btn->next;
    }
}
