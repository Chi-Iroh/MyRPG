/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** menu.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

layer_t* init_background(void)
{
    layer_t* bg_l = create_layer(set_2vector(WD_WIDTH, WD_HEIGHT), NULL);
    draw_t* bg = create_draw(create_shape(RECT, SF_GREY, sfWhite, 5), SHAPE,
    create_data(set_3vector(30, 30, 0), set_2vector(1860, 1020), 0));
    append_draw_layer(bg_l, bg);
    bg_l->show = false;
    return bg_l;
}

menu_t* append_btn_menu(window_t* wd, menu_t* m)
{
    m->b_resume = append_button_layer(m->menu_l, m->b_resume);
    m->b_start = append_button_layer(m->menu_l, m->b_start);
    m->b_settings = append_button_layer(m->menu_l, m->b_settings);
    m->b_quit = append_button_layer(m->menu_l, m->b_quit);
    m->bg_l = init_background();
    append_layer(wd->splash, m->menu_l);
    append_layer(wd->splash, m->bg_l);
    return m;
}

menu_t* init_menu(window_t* wd, list_button_t** all_btn)
{
    menu_t* m = malloc(sizeof(menu_t));
    sfVector2f size = set_2vector(300, 75);
    m->show = true;
    m->menu_l = create_layer(set_2vector(WD_WIDTH, WD_HEIGHT), NULL);
    m->b_resume = set_button(all_btn, "REPRENDRE UNE\nMANIF PRECEDENTE",
        set_3vector(100, 900, 0), size);
    m->b_start = set_button(all_btn, "MANIFESTER",
        set_3vector(550, 900, 0), size);
    m->b_settings = set_button(all_btn, "PLANIFICATION",
        set_3vector(1000, 900, 0), size);
    m->b_quit = set_button(all_btn, "   ABANDONNER LA\n\t\t\tLUTTE",
        set_3vector(1450, 900, 0), size);
    m->settings = init_settings(all_btn, wd->splash);
    m->settings->other = NULL;
    return append_btn_menu(wd, m);
}

void menu_core(window_t* wd, game_src_t* g_src)
{
    if (IS_RELEASED(g_src->menu->b_resume)) {
        if (!does_save_file_exist() &&
            init_crowd(wd, &g_src->all_btn, g_src, true) &&
            load_from_file(g_src->game->crowd->player)) {
            refresh_player(g_src->game->crowd->player,
            g_src->game->crowd->player->draw->drawable, g_src->game);
            audio_play_sfx(&g_src->audio, SFX_QUEST);
            g_src->menu->show = false;
        } else
            audio_play_sfx(&g_src->audio, SFX_ERROR);
        g_src->menu->b_start->state = NONE;
    }
    if (IS_RELEASED(g_src->menu->b_start)) {
        if (init_crowd(wd, &g_src->all_btn, g_src, false))
            g_src->menu->show = false;
        g_src->menu->b_start->state = NONE;
    }
    if (IS_RELEASED(g_src->menu->b_quit))
        sfRenderWindow_close(wd->window);
    settings_core(wd, g_src, g_src->menu->b_settings, g_src->menu->menu_l);
}

void menu(window_t* wd, game_src_t* g_src)
{
    g_src->menu->menu_l->show = true;
    for (sfEvent menu_evt; sfRenderWindow_isOpen(wd->window) &&
        g_src->menu->show;) {
        move_splash(wd, 1);
        while (sfRenderWindow_pollEvent(wd->window, &menu_evt))
            analyse_events(wd, menu_evt, g_src);
        menu_core(wd, g_src);
        draw_layers(wd->window, wd->splash);
        sfRenderWindow_display(wd->window);
    }
    g_src->menu->menu_l->show = false;
    wd->splash->show = false;
}
