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

/*void game(window_t* window, game_src_t* g_src)
{
sfEvent event;
sfVector3f null_pos = set_3vector(0, 0, 0);
sfVector2f wind = set_2vector(1920, 1080);
data_t * data2 = create_data(null_pos, set_2vector(920, 80), 0.f);
shape_t * shape2 = create_shape(RECT, sfBlue, sfGreen, 4);
draw_t * draw2 = create_draw(shape2, SHAPE, data2);
append_draw_layer(window->ui, draw2);
data_t * data3 = create_data(set_3vector(1920, 1080, 0), wind, 0.f);
sprite_t * sprite3 = init_sprite();
set_data_sprite(sprite3, data3);
sfTexture * bonhomme = sfTexture_createFromFile("./images/casseur.png", NULL);
set_texture_sprite(sprite3, bonhomme, set_rectangle(0, 0, 48, 72));
draw_t * draw3 = create_draw(sprite3, SPRITE, data3);
append_draw_layer(window->fx, draw3);
window->splash->show = false;
sfClock * clock = sfClock_create();
while (sfRenderWindow_isOpen(window->window) && g_src->menu->show) {
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 0.01) {
        view_center(window, set_2vector(data3->position.x, data3->position.y));
        actualize_window(window);
        sfClock_restart(clock);
    } while (sfRenderWindow_pollEvent(window->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window->window);
        } if (event.type == sfEvtKeyPressed) {
            if (event.key.code == sfKeyQ) {
                data3->position.x -= 50;
            } if (event.key.code == sfKeyD) {
                data3->position.x += 50;
            } if (event.key.code == sfKeyS) {
                data3->position.y += 50;
            } if (event.key.code == sfKeyZ) {
                data3->position.y -= 50;
            } if (event.key.code == sfKeyEscape) {
                g_src->menu->show = true;
            } } }}
}*/

void game(window_t* wd, game_src_t* g_src)
{
    for (sfEvent evt;
        sfRenderWindow_isOpen(wd->window) && !g_src->menu->show;) {
        while (sfRenderWindow_pollEvent(wd->window, &evt))
            analyse_events(wd, evt, g_src);
        if (g_src->game->pause_menu->show)
            pause_menu(wd, g_src);
        actualize_window(wd);
    }
}

void core(window_t* wd, game_src_t* g_src)
{
    while (sfRenderWindow_isOpen(wd->window)) {
        if (g_src->menu->show) {
            wd->splash->show = true;
            menu(wd, g_src);
            continue;
        }
        game(wd, g_src);
    }
}
