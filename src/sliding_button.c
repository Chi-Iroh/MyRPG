/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mypaint-adrien.audiard
** File description:
** sliding_button.c
*/

#include "../include/my_rpg.h"

float get_value_sliding_button(sliding_button_t* s_btn)
{
    float x_btn = sfRectangleShape_getPosition(s_btn->btn->rect).x;
    float x_line = sfRectangleShape_getPosition(s_btn->line).x;
    return (x_btn - x_line) / 300 * s_btn->max_value + s_btn->min_value;
}

void move_sliding_button_btn(sfMouseMoveEvent evt, sliding_button_t* s_btn)
{
    sfVector2f old_pos = sfRectangleShape_getPosition(s_btn->btn->rect);
    sfVector2f line_pos = sfRectangleShape_getPosition(s_btn->line);
    float x = evt.x >= line_pos.x && evt.x <= line_pos.x + 300 ?
        evt.x : evt.x < line_pos.x ? line_pos.x : line_pos.x + 300;
    //sfRectangleShape_setPosition(s_btn->btn->rect, vectf(x, old_pos.y));
}

void sliding_button_pressed(window_t* wd, sliding_button_t* s_btn)
{
    sfEvent rel = {.type = 0};
    for (; rel.type != sfEvtMouseButtonReleased;) {
        while (sfRenderWindow_pollEvent(wd, &rel)
            && rel.type != sfEvtMouseButtonReleased) {
            move_sliding_button_btn(rel.mouseMove, s_btn);
        }
        actualize_window(wd);
    }
    //sfRectangleShape_setOutlineColor(s_btn->btn->rect, sfBlack);
}

sliding_button_t** set_sliding_button(int nb_sl, sfVector3f pos,
    float min_value, float max_value)
{
    sliding_button_t** s_btn = malloc(sizeof(sliding_button_t*) * (nb_sl + 1));
    for (int i = 0; i < nb_sl; i++) {
        s_btn[i] = malloc(sizeof(sliding_button_t));
        s_btn[i]->line = create_draw(create_shape(SQUARE, sfBlack, sfBlack, 0),
            SHAPE, create_data(pos, set_2vector(300, 10), 0), NULL);
        s_btn[i]->btn = set_button(NULL, set_3vector(pos.x, pos.y + i * 70, 0),
            set_2vector(50, 40), sfWhite);
        //draw_set_origin(s_btn[i]->btn->rect, set_2vector(25, 20))
        s_btn[i]->min_value = min_value;
        s_btn[i]->max_value = max_value;
        s_btn[i]->value = &get_value_sliding_button;
    }
    s_btn[nb_sl] = NULL;
    return s_btn;
}
