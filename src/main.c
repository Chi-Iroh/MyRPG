/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main for my_rgpg
*/
#include "../include/my_rpg.h"
#include "../lib/my_graphics/my_graphics.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    sfVideoMode mode = {1920, 1080, 32}; float factor = 1.f; sfEvent event;
    window_t * window = create_window("49:3", mode, NULL, NULL);
    if (window == NULL) {
        write(2, "terminating process\n", 20); return 84;
    } sfVector3f null_pos = set_3vector(0, 0, 0);
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
    while (sfRenderWindow_isOpen(window->window)) {
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
                } if (event.key.code == sfKeyW) {
                    factor += 0.1;
                } if (event.key.code == sfKeyX) {
                    factor -= 0.1;
                } } } }
    sfClock_destroy(clock); sfTexture_destroy(bonhomme); free_window(window);
    return 0;
}
