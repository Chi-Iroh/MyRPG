/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-pushswap-adrien.audiard
** File description:
** main.c
*/

#include "include/pushswap.h"

int go_right(linked_list_t *l_a, int nb_nbr)
{
    int r = 0;
    for (r; l_a->next->nbr >= l_a->nbr && l_a->previous->nbr <= l_a->nbr; r++) {
        l_a = l_a->next;
        if (r > nb_nbr)
            return -1;
    }
    return r;
}

linked_list_t *algo(operations *op, linked_list_t *l_a, int nb_nbr)
{
    int right = go_right(l_a, nb_nbr) + 1;
    if (right == 0)
        return l_a;
    if (right <= nb_nbr / 2 && right != 0)
        while (l_a->nbr >= l_a->previous->nbr)
            rotate(op, &l_a, 1);
    if (right > nb_nbr / 2 && right != nb_nbr)
        while (l_a->previous->nbr <= l_a->nbr)
            rotate_right(op, &l_a, 1);
    l_a = partition(op, l_a, l_a->previous);
    right = go_right(l_a, nb_nbr) + 1;
    if (right <= nb_nbr / 2 && right != 0)
        while (l_a->nbr >= l_a->previous->nbr)
            rotate(op, &l_a, 1);
    if (right > nb_nbr / 2 && right != nb_nbr)
        while (l_a->previous->nbr <= l_a->nbr)
            rotate_right(op, &l_a, 1);
    return l_a;
}

void free_list(linked_list_t *l_a)
{
    linked_list_t *start = l_a->previous;
    while (l_a != start) {
        l_a = l_a->next;
        free(l_a->previous);
    }
    free(start);
}

int main(int ac, char **av)
{
    if (ac == 1)
        return 84;
    linked_list_t *l_a = get_list_from_av(av, ac);
    operations *op = malloc(sizeof(operations));
    linked_list_t *first_op;
    op->len = 0;
    op->list_op = malloc(sizeof(linked_list_t));
    op->list_op->nbr = 0;
    op->list_op->next = NULL;
    first_op = op->list_op;
    if (l_a == NULL)
        return 84;
    if (l_a->next != l_a)
        l_a = algo(op, l_a, ac - 1);
    first_op->next = op->list_op;
    op->list_op->previous = first_op;
    op->list_op = first_op->previous;
    op_to_str(op);
    free_list(l_a);
}
