/*
** EPITECH PROJECT, 2022
** library MY_GRAPHICS
** File description:
** function that sort a list of draw by depth
*/

#include "../include/sort.h"

static bool algo_impl
(draw_t **current_address, draw_t **first_address, int *nb_swap)
{
    if ((*current_address)->next == NULL) {
        *current_address = (*current_address)->next;
        return false;
    }
    long double current_d = set_depth((*current_address)->data->position);
    draw_t * next = (*current_address)->next;
    long double next_d = set_depth(next->data->position);
    if (next_d < current_d) {
        swap_draw_next(*current_address);
        (*nb_swap)++;
        if (*current_address == *first_address) {
            *first_address = next;
        }
        return false;
    }
    return true;
}

static draw_t * algo(draw_t * list)
{
    int nb_swap = 1;
    draw_t * first = list;
    bool status = true;

    while (nb_swap > 0) {
        draw_t * current = first;
        nb_swap = 0;
        while (status && current != NULL) {
            status &= algo_impl(&current, &first, &nb_swap);
            current = status ? current->next : current;
        }
    }
    return first;
}

draw_t * sort_draws(draw_t * draw)
{
    if (draw == NULL)
        return NULL;
    draw = algo(draw);
    return draw;
}
