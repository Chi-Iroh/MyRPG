/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** inventory.c
*/

#include "../include/my_rpg.h"
#include "../lib/my_graphics/my_graphics.h"

void change_slot_selected(character_t* charac, sfMouseWheelScrollEvent evt,
    game_src_t* g_src)
{
    if (g_src->menu->show)
        return;
    charac->inv->is_selected = 0;
    set_color_out_draw(charac->inv->slot, sfBlack);
    set_thick_draw(charac->inv->slot, 3);
    charac->inv = evt.delta == 1 ? charac->inv->prev : charac->inv->next;
    charac->inv->is_selected = 1;
    set_color_out_draw(charac->inv->slot, sfRed);
    set_thick_draw(charac->inv->slot, 10);
}

inv_slot_t* init_inventory(window_t *wd, int nb_slots)
{
    shape_t* shape;
    data_t* datas;
    inv_slot_t* curr = NULL, *next = NULL, *tmp = NULL;
    for (int i = 0, len = 960 - (nb_slots) * 62;
        i < nb_slots; i++, len += 114) {
        curr = malloc(sizeof(inv_slot_t));
        curr->prev = NULL;
        curr->next = next;
        curr->object = NULL;
        curr->is_selected = i ? 0 : 1;
        shape = create_shape(RECT, sfWhite, i ? sfBlack : sfRed, i ? 3 : 10);
        datas = create_data(set_3vector(len, 900, 0), set_2vector(98, 98), 0);
        curr->slot = create_draw(shape, SHAPE, datas);
        append_draw_layer(wd->ui, curr->slot);
        next = curr;
    } for (tmp = curr; curr->next; curr = curr->next)
        curr->next->prev = curr;
    curr->next = tmp;
    tmp->prev = curr;
    return curr;
}
