/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** player_management.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

draw_t** init_p_man_titles(layer_t* layer)
{
    draw_t** titles = malloc(sizeof(draw_t*) * 4);
    char *name[4] = {"STATS", "INVENTAIRE", "QUETE EN COURS", "Reunir 30 manife"
    "stant pour invoquer le mechant Macrongue et lui faire retirer sa reforme"};
    sfVector3f pos[4] = {set_3vector(100, 100, 0), set_3vector(1400, 100, 0),
        set_3vector(100, 800, 0), set_3vector(150, 900, 0)};
    text_t* txt = NULL;
    data_t* data = NULL;
    for (int i = 0; i < 4; i++) {
        txt = create_text(name[i], NULL, i == 3 ? sfYellow : sfBlack);
        data = create_data(pos[i], set_2vector(0, i == 3 ? 30 : 50), 0);
        titles[i] = create_draw(txt, TEXT, data);
        set_thick_draw(titles[i], 2);
        append_draw_layer(layer, titles[i]);
        set_color_out_draw(titles[i], i == 3 ? sfBlack : sfWhite);
    }
    return titles;
}

menu_cat_t* init_management(window_t* wd, list_button_t** a_btns)
{
    menu_cat_t* p_man = malloc(sizeof(menu_cat_t));
    sfVector2f s[2] = {set_2vector(300, 75), set_2vector(200, 75)};
    char* name[1] = {"    MANIFESTANT\n    PLANIFIEE"};
    p_man->menu_cat_l = create_layer(set_2vector(WD_WIDTH, WD_HEIGHT), NULL);
    p_man->title = init_p_man_titles(p_man->menu_cat_l);
    p_man->btn = malloc(sizeof(button_s_t*) * 1);
    for (int i = 0; i < 1; i++) {
        p_man->btn[i] = set_button(a_btns, name[i],
        set_3vector(1500, 900, 0), s[i]);
        p_man->btn[i] = append_button_layer(p_man->menu_cat_l, p_man->btn[i]);
    }
    append_layer(wd->splash->next, p_man->menu_cat_l);
    swap_layer_up(p_man->menu_cat_l);
    p_man->menu_cat_l->show = false;
    return p_man;
}

void player_management_core(window_t* wd, game_src_t* g_src, menu_cat_t* p_man)
{
    if (IS_RELEASED(g_src->game->pause_menu->b_player) ||
        IS_RELEASED(p_man->btn[0])) {
        switch_layer_show(p_man->menu_cat_l);
        switch_layer_show(g_src->menu->bg_l);
        switch_layer_show(g_src->game->pause_menu->pause_l);
        g_src->game->pause_menu->b_player->state = NONE;
        p_man->btn[0]->state = NONE;
    }
}
