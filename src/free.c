/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** free.c
*/

#include "../include/my_rpg.h"
#include "../lib/my_graphics/my_graphics.h"

void free_button(list_button_t* l_btn)
{
    if (l_btn) {
        free(l_btn->btn);
        free(l_btn);
    }
}

void free_g_src(game_src_t* g_src)
{
    list_button_t* tmp = NULL;
    for (; g_src->all_btn;
        tmp = g_src->all_btn, g_src->all_btn = g_src->all_btn->next)
            free_button(tmp);
    free_button(tmp);
    free(g_src->menu->settings);
    free(g_src->menu);
    free(g_src);
}
