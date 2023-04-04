/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-pushswap-adrien.audiard
** File description:
** swap.c
*/

#include "../include/pushswap.h"

void swap(operations *op, linked_list_t **list, int type)
{
    if ((*list) == NULL || (*list)->next == (*list))
        return;
    if ((*list)->next->next != (*list)) {
        (*list)->next = (*list)->next->next;
        (*list)->next->previous->next = *list;
        (*list)->next->previous->previous = (*list)->previous;
        (*list)->previous->next = (*list)->next->previous;
        (*list)->previous = (*list)->next->previous;
        (*list)->next->previous = *list;
    }
    (*list) = (*list)->previous;
    if (type != 3)
        op->len += 3;
    if (type == 1)
        op->list_op = new_op(1, op->list_op);
    if (type == 2)
        op->list_op = new_op(2, op->list_op);
}

void swap_all(operations *op, linked_list_t **l_a, linked_list_t **l_b)
{
    swap(op, l_a, 3);
    swap(op, l_b, 3);
    op->len += 3;
    op->list_op = new_op(3, op->list_op);
}

void push_bis(linked_list_t **dest, linked_list_t **inter)
{
    (*inter)->previous = (*dest)->previous;
    (*inter)->previous->next = (*inter);
    (*dest)->previous = (*inter);
    (*inter)->next = *dest;
    (*dest) = (*inter);
}

void push(operations *op, linked_list_t **dest, linked_list_t **src, int type)
{
    if (*src == NULL)
        return;
    linked_list_t *inter = *src;
    if ((*src)->next != *src) {
        (*src)->next->previous = (*src)->previous;
        (*src)->previous->next = (*src)->next;
        *src = (*src)->next;
    } else
        *src = NULL;
    if (*dest == NULL) {
        *dest = inter;
        (*dest)->next = *dest;
        (*dest)->previous = *dest;
    } else
        push_bis(dest, &inter);
    op->len += 3;
    if (type == 1)
        op->list_op = new_op(4, op->list_op);
    if (type == 2)
        op->list_op = new_op(5, op->list_op);
}
