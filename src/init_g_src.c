/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** init_g_src.c
*/

#include "../include/my_rpg.h"
#include "../lib/my_graphics/my_graphics.h"

character_t* init_char_test(window_t* wd)
{
    character_t* charac = malloc(sizeof(character_t));
    charac->inv = init_inventory(wd, 3);
    return charac;
}

game_t* init_game(window_t* wd)
{
    game_t* game = malloc(sizeof(game_t));
    game->character = init_char_test(wd);
    game->pause_menu = NULL;//init_pause_menu();
    init_crowd(&game->crowd, wd);
    return game;
}

game_src_t* init_game_sources(window_t* wd)
{
    game_src_t* g_src = malloc(sizeof(game_src_t));
    list_button_t* btns = NULL;
    g_src->menu = init_menu(wd, &btns);
    g_src->game = init_game(wd);
    g_src->all_btn = btns;
    return g_src;
}
