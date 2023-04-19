/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** event.c
*/

#include "../include/my_rpg.h"
#include "../lib/my_graphics/my_graphics.h"

void key_pressed(sfRenderWindow* wd, sfKeyEvent evt, game_src_t* g_src)
{
    switch (evt.code) {
    case sfKeyEscape:
        if (g_src->menu->show) {
            sfRenderWindow_close(wd);
            break;
        }
        g_src->menu->show = true;
        break;
    default:
        break;
    }
}

void analyse_events(window_t* wd, sfEvent event, game_src_t *g_src)
{
    switch (event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(wd->window); break;
        case sfEvtKeyPressed:
            key_pressed(wd->window, event.key, g_src); break;
        case sfEvtMouseButtonPressed:
            mouse_button_pressed(wd, event.mouseButton, g_src); break;
        case sfEvtMouseButtonReleased:
            mouse_button_released(wd->window, event.mouseButton,
                g_src->all_btn); break;
        case sfEvtMouseMoved:
            mouse_moved(event.mouseMove, g_src); break;
        case sfEvtMouseWheelScrolled:
            change_slot_selected(g_src->game->character,
                event.mouseWheelScroll, g_src); break;
        default: break;
    }
}
