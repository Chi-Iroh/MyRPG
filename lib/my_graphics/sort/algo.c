/*
** EPITECH PROJECT, 2022
** library MY_GRAPHICS
** File description:
** algo.c
*/

#include "../include/sort.h"

static int push_or_swap(draw_t **l_a, draw_t **l_b, draw_t *pivot)
{
    if ((*l_a)->next == pivot) {
        if ((*l_b) != NULL && (*l_b)->next->id > (*l_b)->id) {
            swap_all(l_a, l_b);
            return 1;
        }
        swap(l_a);
        return 1;
    }
    push(l_b, l_a);
    return 0;
}

static int pos_nb_greater(draw_t *l_a, draw_t *pivot)
{
    int i = 0;
    for (; l_a->id <= pivot->id && l_a != pivot; i++) {
        l_a = l_a->next;
    }
    if (l_a == pivot)
        return -1;
    return i;
}

static draw_t *partition_reset(draw_t *l_a, int not_greater)
{
    for (int j = 0; j <= not_greater; j++)
        rotate_right(&l_a);
    return l_a;
}

draw_t *partition_bis(draw_t *l_a, draw_t *pivot, int *type_nbr)
{
    int is_swap = 0;
    int pos_greater = pos_nb_greater(l_a, pivot);
    draw_t *l_b = NULL;
    for (; pos_greater != -1; type_nbr[1]++) {
        for (int j = 0; j < pos_greater; j++, type_nbr[0]++)
            rotate(&l_a);
        is_swap = push_or_swap(&l_a, &l_b, pivot);
        pos_greater = pos_nb_greater(l_a, pivot);
    }
    if (l_b != NULL) {
        for (int i = 0; l_a != pivot->next; i++, type_nbr[0]++)
            rotate(&l_a);
        pivot = is_swap ? pivot->next : l_b;
        while (l_b != NULL)
            push(&l_a, &l_b);
        l_a = partition(l_a, pivot);
    }
    return partition_reset(l_a, type_nbr[0] - 1);
}

draw_t *partition(draw_t *l_a, draw_t *pivot)
{
    int type_nbr[2] = {0, 0};
    if (l_a == pivot)
        return l_a;
    l_a = partition_bis(l_a, pivot, type_nbr);
    if (l_a != pivot)
        l_a = partition(l_a, pivot->previous);
    if (type_nbr[1] <= 1)
        return l_a;
    return partition(l_a, pivot);
}
