/*
** EPITECH PROJECT, 2022
** library MY_GRAPHICS
** File description:
** function that sort a list of draw by depth
*/

#include "../include/sort.h"

static int go_right(draw_t *l_a, int nb_nbr)
{
    int r = 0;
    while (l_a->next->data->depth >= l_a->data->depth &&
            l_a->previous->data->depth <= l_a->data->depth) {
        l_a = l_a->next;
        if (r > nb_nbr)
            return -1;
        r++;
    }
    return r;
}

static draw_t *algo(draw_t *l_a, int nb_nbr)
{
    int right = go_right(l_a, nb_nbr) + 1;
    if (right == 0)
        return l_a;
    if (right <= nb_nbr / 2 && right != 0)
        while (l_a->data->depth >= l_a->previous->data->depth)
            rotate(&l_a);
    if (right > nb_nbr / 2 && right != nb_nbr)
        while (l_a->previous->data->depth <= l_a->data->depth)
            rotate_right(&l_a);
    l_a = partition(l_a, l_a->previous);
    right = go_right(l_a, nb_nbr) + 1;
    if (right <= nb_nbr / 2 && right != 0)
        while (l_a->data->depth >= l_a->previous->data->depth)
            rotate(&l_a);
    if (right > nb_nbr / 2 && right != nb_nbr)
        while (l_a->previous->data->depth <= l_a->data->depth)
            rotate_right(&l_a);
    return l_a;
}

draw_t * sort_draws(draw_t * draw)
{
    draw_t * first = draw;
    draw_t * last = draw;
    int len = 1;
    while (last->next != NULL) {
        last = last->next;
        len++;
    }
    first->previous = last;
    last->next = first;
    draw = algo(draw, len);
    first = draw;
    last = draw;
    for (int i = 1; i < len; i++) {
        last = last->next;
    }
    first->previous = NULL;
    last->next = NULL;
    return draw;
}
