/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** pause_menu.c
*/

#include <my_rpg.h>
#include <my_graphics.h>
#include <audio.h>
#include <my_macros.h>

void append_pause_button_layer(pause_t* pause)
{
    append_button_layer(pause->pause_l, pause->b_resume);
    append_button_layer(pause->pause_l, pause->b_save);
    append_button_layer(pause->pause_l, pause->b_load);
    append_button_layer(pause->pause_l, pause->b_settings);
    append_button_layer(pause->pause_l, pause->b_menu);
}

pause_t* init_pause_menu(window_t* wd, list_button_t** btns, game_src_t* g_src)
{
    pause_t* pause = malloc(sizeof(pause_t));
    sfVector2f size = set_2vector(300, 75);
    pause->show = false;
    pause->pause_l = create_layer(set_2vector(WD_WIDTH, WD_HEIGHT), NULL);
    pause->b_resume = set_button(btns, "REPRENDRE LA\nLUTTE",
        set_3vector(800, 150, 0), size);
    pause->b_save = set_button(btns, "SAUVEGARDER\nVOS EXPLOITS",
        set_3vector(800, 400, 0), size);
    pause->b_load = set_button(btns, "CHARGER\nVOS EXPLOITS",
        set_3vector(800, 500, 0), size);
    pause->b_settings = set_button(btns, "PLANIFICATION\n(tardive)",
        set_3vector(800, 750, 0), size);
    pause->b_menu = set_button(btns, "RETOUR A LA CASE\nDEPART",
        set_3vector(800, 900, 0), size);
    pause->bg = NULL;
    append_pause_button_layer(pause);
    append_layer(wd->splash, pause->pause_l);
    pause->settings = g_src->menu->settings;
    return pause;
}

void pause_core(window_t* wd, game_src_t* g_src)
{
    if (IS_RELEASED(g_src->game->pause_menu->b_resume)) {
        g_src->game->pause_menu->show = false;
        g_src->game->pause_menu->b_resume->state = NONE;
    }
    if (IS_RELEASED(g_src->game->pause_menu->b_menu)) {
        g_src->game->pause_menu->show = false;
        g_src->menu->show = true;
    }
    if (IS_RELEASED(g_src->game->pause_menu->b_settings) ||
        IS_RELEASED(g_src->game->pause_menu->settings->btn[0])) {
        switch_layer_show(g_src->game->pause_menu->settings->menu_cat_l);
        switch_layer_show(g_src->game->pause_menu->pause_l);
        g_src->game->pause_menu->b_settings->state = NONE;
        g_src->game->pause_menu->settings->btn[0]->state = NONE;
    }
    settings_core(wd, g_src, g_src->game->pause_menu->settings);
}

void pause_menu(window_t* wd, game_src_t* g_src)
{
    g_src->game->pause_menu->pause_l->show = true;
    wd->splash->show = true;
    audio_set_active_bgm(&g_src->audio, BGM_MENU, 1);
    sfMusic_setPitch(g_src->audio.menu_bgm, 1.5);
    for (sfEvent pause_evt; sfRenderWindow_isOpen(wd->window) &&
        g_src->game->pause_menu->show;) {
        move_splash(wd, 0);
        while (sfRenderWindow_pollEvent(wd->window, &pause_evt))
            analyse_events(wd, pause_evt, g_src);
        pause_core(wd, g_src);
        draw_layers(wd->window, wd->splash, wd->view);
        sfRenderWindow_display(wd->window);
    }
    g_src->game->pause_menu->pause_l->show = false;
    wd->splash->show = false;
    sfMusic_setPitch(g_src->audio.menu_bgm, 1);
    audio_set_active_bgm(&g_src->audio, BGM_BOSS, 1);
}
