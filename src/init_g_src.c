/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** init_g_src.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

game_t* init_game(window_t* wd, list_button_t** btns, game_src_t* g_src)
{
    game_t* game = malloc(sizeof(game_t));
    game->character = NULL;
    game->pause_menu = init_pause_menu(wd, btns, g_src);
    game->crowd = NULL;
    return game;
}

static bool init_speech_bubble(speech_bubble_t *bubble, layer_t *layer)
{
    *bubble = (speech_bubble_t) {
        .layer = layer,
        .texture = sfTexture_createFromFile("images/bulle_de_texte.png", NULL),
        .bubble_data = NULL,
        .bubble_draw = NULL,
        .bubble_sprite = NULL,
        .pos = { 0, 0, 0 },
        .rect = { 0, 0, 96, 24 },
        .size = { 0, 0 },
        .str = "Hello World !",
        .text = NULL,
        .text_data = NULL,
        .text_draw = NULL,
    };
    return bubble->texture != NULL;
}

game_src_t* init_game_sources(window_t* wd)
{
    game_src_t* g_src = malloc(sizeof(game_src_t));
    list_button_t* btns = NULL;
    g_src->menu = init_menu(wd, &btns);
    g_src->game = init_game(wd, &btns, g_src);
    init_speech_bubble(&g_src->speech_bubble, wd->fx);
    g_src->game->pause_menu->pause_l->show = false;
    g_src->all_btn = btns;
    audio_init(&g_src->audio, AUDIO_DEFAULT_VOLUME);
    wd->splash->draw->next->show = false;
    wd->splash->draw->next->next->show = false;
    return g_src;
}
