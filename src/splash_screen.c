/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** splash_screen.c
*/

#include "../include/my_rpg.h"
#include "../lib/my_graphics/my_graphics.h"

typedef struct {
    sprite_t* sprite;
    data_t* bg_data;
    draw_t* bg_draw;
} splash_screen_t;

void init_splash_screen(window_t* wd, splash_screen_t* spl)
{
    sfVector3f null_pos = set_3vector(0, 0, 0);
    sfVector2f wind = set_2vector(1920, 1080);
    spl->sprite = init_sprite();
    spl->bg_data = create_data(null_pos, wind, 0.f);
    set_texture_sprite(spl->sprite,
        sfTexture_createFromFile("./images/splash.png", NULL),
        set_rectangle(0, 0, 2736, 2310));
    set_data_sprite(spl->sprite, spl->bg_data);
    set_texture_sprite(spl->sprite, spl->sprite->texture, set_rectangle(0, 0, 2736 ,2310));
    spl->bg_draw = create_draw(spl->sprite, SPRITE, spl->bg_data, NULL);
    append_draw_layer(wd->core, spl->bg_draw);
    //switch_layer_show()
}

void splash_screen(window_t* wd)
{
    //append_draw_layer()
    sfVideoMode mode = {1920, 1080, 32};
    splash_screen_t spl;
    game_src_t g_src = {.first = NULL, .all_btn = NULL};
    g_src.menu = init_menu(wd, &g_src.all_btn);
    init_splash_screen(wd, &spl);
    for (sfEvent event; sfRenderWindow_isOpen(wd->window);) {
        spl.bg_data->position.x -= 0.40;
        spl.bg_data->position.y -= 0.3377193;
        if (spl.bg_data->position.x < -684) {
            spl.bg_data->position.x = 0;
            spl.bg_data->position.y = 0;
        }
        while (sfRenderWindow_pollEvent(wd->window, &event)) {
            analyse_events(wd->window, event, &g_src);
        }
        if (g_src.menu->start->state == HOVER)
            set_color_out_draw(g_src.menu->start->rect, sfRed);
        set_data_sprite(spl.sprite, spl.bg_data);
        actualize_window(wd);
    }
    //free_layers(wd->core);
}
