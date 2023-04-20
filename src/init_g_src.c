/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** init_g_src.c
*/

#include <my_rpg.h>
#include <my_graphics.h>
#include <audio.h>
#include <my_macros.h>

character_t* init_char_test(window_t* wd)
{
    character_t* charac = malloc(sizeof(character_t));
    charac->inv = init_inventory(wd, 3);
    return charac;
}

game_t* init_game(window_t* wd, list_button_t** btns, game_src_t* g_src)
{
    game_t* game = malloc(sizeof(game_t));
    game->character = init_char_test(wd);
    game->pause_menu = init_pause_menu(wd, btns, g_src);
    init_crowd(&game->crowd, wd);
    return game;
}

game_src_t* init_game_sources(window_t* wd)
{
    game_src_t* g_src = malloc(sizeof(game_src_t));
    list_button_t* btns = NULL;
    g_src->menu = init_menu(wd, &btns);
    g_src->game = init_game(wd, &btns, g_src);
    g_src->game->pause_menu->pause_l->show = false;
    g_src->all_btn = btns;
    init_audio(&g_src->audio, AUDIO_DEFAULT_VOLUME);
    return g_src;
}
