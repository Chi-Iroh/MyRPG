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
        if (g_src->menu->show == true)
            return sfRenderWindow_close(wd);
        g_src->menu->show = true;
        break;
    default:
        break;
    }
}

void analyse_events(sfRenderWindow *window, sfEvent event, game_src_t *g_src)
{
    switch (event.type) {
        case sfEvtClosed: return sfRenderWindow_close(window);
        case sfEvtKeyPressed: return key_pressed(window, event.key, g_src);
        case sfEvtMouseButtonPressed:
            return mouse_button_pressed(window, event.mouseButton, g_src);
        case sfEvtMouseButtonReleased:
            return mouse_button_released(window, event.mouseButton,
                g_src->all_btn);
        case sfEvtMouseMoved: return mouse_moved(event.mouseMove, g_src);
        case sfEvtMouseWheelScrolled:
            return change_slot_selected(g_src, event.mouseWheelScroll);
        default: return;
    }
}
