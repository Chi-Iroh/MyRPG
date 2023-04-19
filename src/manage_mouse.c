/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mypaint-adrien.audiard
** File description:
** manage_mouse.c
*/

#include "../include/my_rpg.h"
#include "../lib/my_graphics/my_graphics.h"

void button_pressed(list_button_t* all_btn, sfMouseButtonEvent evt)
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

void mouse_button_released(sfRenderWindow* wd, sfMouseButtonEvent evt,
    list_button_t* all_btn)
{
    for (; all_btn; all_btn = all_btn->next) {
        if (all_btn->btn->layer_on->show && all_btn->btn->rect->show)
            all_btn->btn->is_released(all_btn->btn, &evt) ?
            set_color_in_draw(all_btn->btn->rect, sfWhite) : 0;
        else
            all_btn->btn->state = NONE;
    }
}

void mouse_button_pressed(sfRenderWindow* wd, sfMouseButtonEvent evt,
    game_src_t* g_src)
{
    button_pressed(g_src->all_btn, evt);
}

void button_hovered(list_button_t* all_btn, sfMouseMoveEvent evt)
{
    for (; all_btn; all_btn = all_btn->next) {
        if (all_btn->btn->layer_on->show && all_btn->btn->rect->show &&
            all_btn->btn->is_hover(all_btn->btn, &evt))
            set_color_out_draw(all_btn->btn->rect, sfRed);
        else
            set_color_out_draw(all_btn->btn->rect, sfBlack);
    }
}

void mouse_moved(sfMouseMoveEvent evt, game_src_t* g_src)
{
    button_hovered(g_src->all_btn, evt);
}
