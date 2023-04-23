/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** free.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

void free_button_list(list_button_t* l_btn)
{
    if (l_btn) {
        if (l_btn->btn->s_btn)
            free(l_btn->btn->s_btn);
        free(l_btn->btn);
        free(l_btn);
    }
}

void free_menu(menu_t *menu)
{
    RETURN_IF(!menu);
    FREE_IF_ALLOCATED(menu->settings->btn, free);
    FREE_IF_ALLOCATED(menu->settings->s_btn, free);
    FREE_IF_ALLOCATED(menu->settings->title, free);
    FREE_IF_ALLOCATED(menu->settings, free);
    FREE_IF_ALLOCATED(menu, free);
}

void free_g_src(game_src_t* g_src)
{
    list_button_t* tmp = NULL;
    for (; g_src->all_btn;
        tmp = g_src->all_btn, g_src->all_btn = g_src->all_btn->next)
            free_button_list(tmp);
    free_button_list(tmp);
    speech_bubble_remove_all(&g_src->game->list_bubbles);
    free_crowd(g_src->game->crowd);
    free_menu(g_src->menu);
    free(g_src);
}

void free_main(window_t *window, game_src_t *g_src)
{
    FREE_IF_ALLOCATED(window, free_window);
    audio_free(&g_src->audio);
    FREE_IF_ALLOCATED(g_src, free_g_src);
}
