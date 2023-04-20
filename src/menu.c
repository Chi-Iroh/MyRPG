/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** menu.c
*/

#include <my_rpg.h>
#include <my_graphics.h>
#include <audio.h>
#include <my_macros.h>

menu_t* init_menu(window_t* wd, list_button_t** all_btn)
{
    menu_t* m = malloc(sizeof(menu_t));
    sfVector2f size = set_2vector(300, 75);
    m->show = true;
    m->menu_l = create_layer(set_2vector(1920, 1080), NULL);
    m->b_start = set_button(all_btn, "MANIFESTER",
        set_3vector(100, 900, 0), size);
    m->b_settings = set_button(all_btn, "PLANIFICATION",
        set_3vector(750, 900, 0), size);
    m->b_quit = set_button(all_btn, "   ABANDONNER LA\n\t\t\tLUTTE",
        set_3vector(1400, 900, 0), size);
    m->b_start = append_button_layer(m->menu_l, m->b_start);
    m->b_settings = append_button_layer(m->menu_l, m->b_settings);
    m->b_quit = append_button_layer(m->menu_l, m->b_quit);
    m->bg = NULL;
    append_layer(wd->splash, m->menu_l);
    m->settings = init_settings(all_btn, wd->splash);
    return m;
}

void menu_core(window_t* wd, game_src_t* g_src)
{
    if (IS_RELEASED(g_src->menu->b_start)) {
        g_src->menu->show = false;
        g_src->menu->b_start->state = NONE;
    }
    if (IS_RELEASED(g_src->menu->b_settings) ||
        IS_RELEASED(g_src->menu->settings->btn[0])) {
        switch_layer_show(g_src->menu->settings->menu_cat_l);
        switch_layer_show(g_src->menu->menu_l);
        g_src->menu->b_settings->state = NONE;
        g_src->menu->settings->btn[0]->state = NONE;
    }
    if (IS_RELEASED(g_src->menu->b_quit))
        sfRenderWindow_close(wd->window);
    settings_core(wd, g_src);
    return;
}

void menu(window_t* wd, game_src_t* g_src)
{
    g_src->menu->menu_l->show = true;
    audio_control_all(&g_src->audio, AUDIO_PLAY);
    for (sfEvent menu_evt; sfRenderWindow_isOpen(wd->window) &&
        g_src->menu->show;) {
        wd->splash->draw->data->position.x -= 0.40;
        wd->splash->draw->data->position.y -= 0.3377193;
        if (wd->splash->draw->data->position.x < -684) {
            wd->splash->draw->data->position.x = 0;
            wd->splash->draw->data->position.y = 0;
        }
        while (sfRenderWindow_pollEvent(wd->window, &menu_evt))
            analyse_events(wd, menu_evt, g_src);
        menu_core(wd, g_src);
        draw_layers(wd->window, wd->splash);
        sfRenderWindow_display(wd->window);
    }
    g_src->menu->menu_l->show = false;
    wd->splash->show = false;
}
