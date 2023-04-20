/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** core.c
*/

#include <my_rpg.h>
#include <my_graphics.h>
#include <audio.h>
#include <my_macros.h>

void game(window_t* wd, game_src_t* g_src)
{
    wd->splash->show = false;
    sfClock * clock = sfClock_create();
    for (sfEvent evt;
        sfRenderWindow_isOpen(wd->window) && !g_src->menu->show;) {
        while (sfRenderWindow_pollEvent(wd->window, &evt))
            analyse_events(wd, evt, g_src);
        if (g_src->game->pause_menu->show) {
            pause_menu(wd, g_src);
            continue;
        }
        crowd(wd, g_src->game->crowd);
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 0.01) {
            actualize_window(wd);
            sfClock_restart(clock);
        }
        sfVector3f pos = get_position_draw(g_src->game->crowd.player->draw);
        view_center(wd, set_2vector(pos.x, pos.y));
    }
    sfClock_destroy(clock);
}

void core(window_t* wd, game_src_t* g_src)
{
    while (sfRenderWindow_isOpen(wd->window)) {
        if (g_src->menu->show) {
            wd->splash->show = true;
            set_active_bgm(&g_src->audio, MENU_BGM, 1);
            menu(wd, g_src);
            continue;
        }
        set_active_bgm(&g_src->audio, BOSS_BGM, 1);
        game(wd, g_src);
    }
}
