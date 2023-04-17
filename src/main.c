/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main for my_rgpg
*/
#include "../include/my_rpg.h"
#include "../lib/my_graphics/my_graphics.h"
#include "../lib/button/button.h"

int main(int argc, char **argv)
{
    sfVideoMode mode = {1920, 1080, 32};
    window_t * window = create_window("49:3", mode, NULL, "./images/splash.png");
    sfVector3f null_pos = set_3vector(0, 0, 0);
    sfVector2f wind = set_2vector(1920, 1080);

    data_t * data1 = create_data(null_pos, wind, 0.f);
    sprite_t * sprite1 = init_sprite();
    set_data_sprite(sprite1, data1);
    set_texture_sprite(sprite1, window->spritesheet, set_rectangle(0, 0, 16384, 3200));
    draw_t * draw1 = create_draw(sprite1, SPRITE, data1, NULL);
    append_draw_layer(window->core, draw1);

    data_t * data2 = create_data(null_pos, set_2vector(920, 80), 0.f);
    shape_t * shape2 = create_shape(SQUARE, sfBlue, sfGreen, 4);
    draw_t * draw2 = create_draw(shape2, SHAPE, data2, NULL);
    append_draw_layer(window->ui, draw2);

    data_t * data3 = create_data(null_pos, wind, 0.f);
    sprite_t * sprite3 = init_sprite();
    set_data_sprite(sprite3, data3);
    sfTexture * bonhomme = sfTexture_createFromFile("./images/étudiant_sciences_po.png", NULL);
    set_texture_sprite(sprite3, bonhomme, set_rectangle(0, 0, 48, 72));
    draw_t * draw3 = create_draw(sprite3, SPRITE, data3, NULL);
    append_draw_layer(window->core, draw3);

    button_t button;
    sfFont *font = sfFont_createFromFile("./fonts/Arial.ttf");

    init_button_base(&button);
    button_fill_color(&button, sfRed);
    button_set_ansi_title(&button, "hello world", false);
    button.font = font;
    button.text_color = sfWhite;
    sfEvent event;
    while (sfRenderWindow_isOpen(window->window)) {
        sfRenderWindow_clear(window->window, sfBlack);
        sfRenderTexture_setView(window->core->texture, window->view);
        draw_layers(window->window, window->core);
        draw_button(window->window, &button);
        sfRenderWindow_display(window->window);
        while (sfRenderWindow_pollEvent(window->window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window->window);
            } if (event.type == sfEvtKeyPressed) {
                if (event.key.code == sfKeyQ) {
                    data3->position.x -= 100;
                } if (event.key.code == sfKeyD) {
                    data3->position.x += 100;
                } if (event.key.code == sfKeyS) {
                    data3->position.z += 100;
                } if (event.key.code == sfKeyZ) {
                    data3->position.z -= 100;
                }
                view_center(window, set_2vector(data3->position.x, data3->position.z));
            }
            update_button_state(&button, window->window, event);
        }
        puts("----------");
        if ((button.state & BUTTON_RELEASED)) {
            puts("released");
        }
        if ((button.state & BUTTON_PRESSED)) {
            puts("pressed");
        }
        if ((button.state & BUTTON_HOVERED)) {
            puts("hovered");
        }
    }

    sfTexture_destroy(bonhomme);
    free_window(window);
    return 0;
}
