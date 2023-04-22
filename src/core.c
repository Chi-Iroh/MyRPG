/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** core.c
*/

#include <my_graphics.h>
#include <my_rpg.h>

void stat_interaction(stat_t* stat)
{
    if (!stat->exp_point)
        return;
    for (int i = 0; i < NB_STAT - 2; i++) {
        stat->ui->stat_btns[i]->rect->show = true;
        stat->ui->stat_btns[i]->name->show = true;
        if (IS_RELEASED(stat->ui->stat_btns[i])) {
            stat->ui->stat_btns[i]->state = NONE;
            update_stat(stat, i);
            return;
        }
    }
}

void refresh(window_t *wd, game_src_t *g_src, sfClock *clock)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 0.01) {
        actualize_window(wd);
        sfClock_restart(clock);
    }
    sfVector3f pos = get_position_draw(g_src->game->crowd->player->draw);
    view_center(wd, set_2vector(pos.x, pos.y));
}

int game_core(window_t* wd, game_src_t* g_src, sfClock *clock)
{
    if (g_src->game->crowd->player->hp.fill->data->size.x <= 0) {
        refresh(wd, g_src, clock);
        g_src->menu->show = true;
        free_crowd(g_src->game->crowd);
        g_src->game->crowd = NULL;
        countryball_49_3();
        return 1;
    }
    crowd(wd, g_src->game->crowd);
    stat_interaction(&g_src->game->crowd->player->stat);
    return 0;
}

void game(window_t* wd, game_src_t* g_src)
{
    wd->splash->show = false;
    sfClock * clock = sfClock_create();
    speech_bubble_draw_text((sfVector3f){1000,1000,0}, &g_src->speech_bubble);
    for (sfEvent evt;
        sfRenderWindow_isOpen(wd->window) && !g_src->menu->show;) {
        while (sfRenderWindow_pollEvent(wd->window, &evt))
            analyse_events(wd, evt, g_src);
        if (g_src->game->pause_menu->show) {
            pause_menu(wd, g_src);
            continue;
        }
        if (game_core(wd, g_src, clock)) {
            continue;
        }
        refresh(wd, g_src, clock);
    }
    sfClock_destroy(clock);
}

void core(window_t* wd, game_src_t* g_src)
{
    while (sfRenderWindow_isOpen(wd->window)) {
        if (g_src->menu->show) {
            wd->splash->show = true;
            audio_set_active_bgm(&g_src->audio, BGM_MENU, 1);
            menu(wd, g_src);
            continue;
        }
        audio_set_active_bgm(&g_src->audio, BGM_MAIN, 1);
        game(wd, g_src);
    }
}
