/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** init_g_src.c
*/

#include "../include/my_rpg.h"
#include "../lib/my_graphics/my_graphics.h"

game_src_t* init_game_sources(window_t* wd)
{
    game_src_t* g_src = malloc(sizeof(game_src_t));
    list_button_t* btns = NULL;
    g_src->menu = init_menu(wd, &btns);
    g_src->all_btn = btns;
    return g_src;
}
