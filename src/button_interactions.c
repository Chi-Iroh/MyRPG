/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** button_interactions.c
*/

#include "../include/my_rpg.h"
#include "../lib/my_graphics/my_graphics.h"

void button_pressed(window_t* wd, list_button_t* all_btn,
    sfMouseButtonEvent evt)
{
    for (; all_btn; all_btn = all_btn->next) {
        if (all_btn->btn->layer_on->show && all_btn->btn->rect->show)
            all_btn->btn->is_clicked(all_btn->btn, &evt) ?
            set_color_in_draw(all_btn->btn->rect,
            sfColor_fromRGB(220, 220, 200)) : 0;
        else
            all_btn->btn->state = NONE;
    }
}

void sliding_button_moved(list_button_t* all_btn, sfMouseMoveEvent evt)
{
    for (; all_btn; all_btn = all_btn->next) {
        if (all_btn->btn->s_btn && IS_PRESSED(all_btn->btn))
            move_sliding_button_btn(evt, all_btn->btn->s_btn);
    }
}
