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

pause_t* init_pause_menu(window_t* wd, list_button_t** btns)
{
    pause_t* pause = malloc(sizeof(pause_t));
    pause->show = false;
    pause->b_load = NULL;
    pause->b_save_and_menu = NULL;
    pause->b_save_and_quit = NULL;
    pause->b_settings = NULL;
    pause->b_menu = NULL;
    pause->b_resume = NULL;
    pause->settings = NULL;
    pause->bg = NULL;
    pause->pause_l = NULL;
    return pause;
}

void pause_menu(window_t* wd, game_src_t* g_src)
{
    //g_src->game->pause_menu->pause_l->show = true;
    wd->splash->show = true;
    for (sfEvent pause_evt; sfRenderWindow_isOpen(wd->window) &&
        g_src->game->pause_menu->show;) {
        wd->splash->draw->data->position.x += 0.40 * 4;
        wd->splash->draw->data->position.y += 0.3377193 * 4;
        if (wd->splash->draw->data->position.x >= 0) {
            wd->splash->draw->data->position.x = -684;
            wd->splash->draw->data->position.y = -577.5;
        }
        while (sfRenderWindow_pollEvent(wd->window, &pause_evt))
            analyse_events(wd, pause_evt, g_src);
        //pause_core(wd, g_src);
        draw_layers(wd->window, wd->splash);
        sfRenderWindow_display(wd->window);
    }
    //g_src->game->pause_menu->pause_l->show = false;
    wd->splash->show = false;
}
