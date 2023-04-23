/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** button_append.c
*/

#include <my_graphics.h>
#include <my_rpg.h>

void edit_hitbox(window_t * wd)
{
    draw_t * core = wd->core->draw;
    change_hitbox_by_id(core, 60, set_rectangle(20, 140, 300, 40));
}
