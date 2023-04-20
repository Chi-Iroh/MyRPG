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

draw_t** init_setting_titles(layer_t* layer)
{
    draw_t** titles = malloc(sizeof(draw_t*) * 3);
    char *name[3] = {"VOLUME", "Musique\n\nSons", "RESOLUTION"};
    sfVector3f pos[3] = {set_3vector(250, 250, 0), set_3vector(100, 390, 0),
        set_3vector(1400, 250, 0)};
    text_t* txt = NULL;
    data_t* data = NULL;
    for (int i = 0; i < 3; i++) {
        txt = create_text(name[i], NULL, sfBlack);
        data = create_data(pos[i], set_2vector(0, i == 1 ? 30 : 50), 0);
        titles[i] = create_draw(txt, TEXT, data);
        set_thick_draw(titles[i], 2);
        append_draw_layer(layer, titles[i]);
    }
    return titles;
}

menu_cat_t* init_settings(list_button_t** all_btn, layer_t* spl)
{
    menu_cat_t* set = malloc(sizeof(menu_cat_t));
    sfVector2f size[3] = {set_2vector(300, 75), set_2vector(200, 75),
        set_2vector(200, 75)};
    float val[3] = {0, 100, 75};
    char* name[3] = {"  MANIF PLANIFIEE", "1920x1080", "960x540"};
    sfVector3f pos[3] = {{.x = 100, .y = 900, .z = 0},
        {.x = 1500, .y = 400, .z = 0}, {.x = 1500, .y = 500, 0}};
    set->menu_cat_l = create_layer(set_2vector(1920, 1080), NULL);
    set->title = init_setting_titles(set->menu_cat_l);
    set->btn = malloc(sizeof(button_s_t*) * 3);
    for (int i = 0; i < 3; i++) {
        set->btn[i] = set_button(all_btn, name[i], pos[i], size[i]);
        set->btn[i] = append_button_layer(set->menu_cat_l, set->btn[i]);
    }
    set->s_btn = set_sliding_button(all_btn, 2, set_3vector(300, 400, 0), val);
    set->s_btn = append_s_button_layer(set->menu_cat_l, set->s_btn, 2);
    append_layer(spl, set->menu_cat_l);
    switch_layer_show(set->menu_cat_l);
    return set;
}

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

void settings_core(window_t* wd, game_src_t* g_src)
{
    if (IS_PRESSED(g_src->menu->settings->s_btn[0]->btn)) {
        g_src->audio.bgm_volume = g_src->menu->settings->s_btn[0]->value
            (g_src->menu->settings->s_btn[0]);
        update_volume(&g_src->audio);
    }
    if (IS_RELEASED(g_src->menu->settings->s_btn[1]->btn)) {
        g_src->audio.sfx_volume = g_src->menu->settings->s_btn[1]->value
            (g_src->menu->settings->s_btn[0]);
        update_volume(&g_src->audio);
        g_src->menu->settings->s_btn[1]->btn->state = NONE;
    }
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
    audio_control(&g_src->audio, AUDIO_PLAY);
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
