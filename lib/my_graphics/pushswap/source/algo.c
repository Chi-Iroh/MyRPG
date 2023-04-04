/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-pushswap-adrien.audiard
** File description:
** algo.c
*/

#include "../include/pushswap.h"

int push_or_swap(operations *op, linked_list_t **l_a, linked_list_t **l_b,
    linked_list_t *pivot)
{
    if ((*l_a)->next == pivot) {
        if ((*l_b) != NULL && (*l_b)->next->nbr > (*l_b)->nbr) {
            swap_all(op, l_a, l_b);
            return 1;
        }
        swap(op, l_a, 1);
        return 1;
    }
    push(op, l_b, l_a, 2);
    return 0;
}

int pos_nb_greater(linked_list_t *l_a, linked_list_t *pivot)
{
    int i = 0;
    for (; l_a->nbr <= pivot->nbr && l_a != pivot; i++) {
        l_a = l_a->next;
    }
    if (l_a == pivot)
        return -1;
    return i;
}

linked_list_t *partition_reset(operations *op, linked_list_t *l_a,
    int not_greater)
{
    for (int j = 0; j <= not_greater; j++)
        rotate_right(op, &l_a, 1);
    return l_a;
}

linked_list_t *partition_bis(operations *op, linked_list_t *l_a,
    linked_list_t *pivot, int *type_nbr)
{
    int is_swap = 0;
    int pos_greater = pos_nb_greater(l_a, pivot);
    linked_list_t *l_b = NULL;
    for (int i; pos_greater != -1; type_nbr[1]++) {
        for (int j = 0; j < pos_greater; j++, type_nbr[0]++)
            rotate(op, &l_a, 1);
        is_swap = push_or_swap(op, &l_a, &l_b, pivot);
        pos_greater = pos_nb_greater(l_a, pivot);
    }
    if (l_b != NULL) {
        for (int i = 0; l_a != pivot->next; i++, type_nbr[0]++)
            rotate(op, &l_a, 1);
        pivot = is_swap ? pivot->next : l_b;
        while (l_b != NULL)
            push(op, &l_a, &l_b, 1);
        l_a = partition(op, l_a, pivot);
    }
    return partition_reset(op, l_a, type_nbr[0] - 1);
}

linked_list_t *partition(operations *op, linked_list_t *l_a,
    linked_list_t *pivot)
{
    int type_nbr[2] = {0, 0};
    if (l_a == pivot)
        return l_a;
    l_a = partition_bis(op, l_a, pivot, type_nbr);
    if (l_a != pivot)
        l_a = partition(op, l_a, pivot->previous);
    if (type_nbr[1] <= 1)
        return l_a;
    return partition(op, l_a, pivot);
}
