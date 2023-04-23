/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** init_crowd.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

bool init_crowd(window_t* wd, list_button_t** a_btn,
    game_src_t* g_src, bool resume)
{
    g_src->game->crowd = malloc(sizeof(crowd_t));
    g_src->game->crowd->player = init_player(wd, g_src->game, resume);
    if (g_src->game->crowd->player == NULL) {
        g_src->game->crowd = NULL;
        free(g_src->game->crowd);
        return false;
    }
    g_src->game->crowd->player->weapon = g_src->game->all_weapons[0];
    update_weapon_ui(g_src->game->all_weapons, g_src->game->crowd->player,
        g_src->game->pause_menu->player->other[1]);
    update_stat_ui(g_src->game->crowd->player->stat, g_src->game->stat_ui);
    append_draw_layer(wd->ui, create_draw(create_shape(RECT,
    sfColor_fromRGBA(220, 220, 220, 100), sfBlack, 3), SHAPE,
    create_data(set_3vector(10, 60, 0), set_2vector(340, 280), 0)));
    g_src->game->crowd->mob = init_crowd_mob(wd);
    g_src->game->crowd->cop = init_crowd_cop(wd);
    return true;
}
