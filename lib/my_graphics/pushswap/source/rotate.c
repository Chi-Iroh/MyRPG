/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-pushswap-adrien.audiard
** File description:
** rotate.c
*/

#include "../include/pushswap.h"

void rotate(operations *op, linked_list_t **list, int type)
{
    if (*list == NULL)
        return;
    *list = (*list)->next;
    if (type != 3)
        op->len += 3;
    if (type == 1)
        op->list_op = new_op(6, op->list_op);
    if (type == 2)
        op->list_op = new_op(7, op->list_op);
}

void rotate_all(operations *op, linked_list_t **l_a, linked_list_t **l_b)
{
    rotate(op,l_a, 3);
    rotate(op, l_b, 3);
    op->len += 3;
    op->list_op = new_op(8, op->list_op);
}

void rotate_right(operations *op, linked_list_t **list, int type)
{
    if (*list == NULL)
        return;
    *list = (*list)->previous;
    if (type != 3)
        op->len += 4;
    if (type == 1)
        op->list_op = new_op(9, op->list_op);
    if (type == 2)
        op->list_op = new_op(10, op->list_op);


}

void rotate_right_all(operations *op, linked_list_t **l_a, linked_list_t **l_b)
{
    rotate_right(op, l_a, 3);
    rotate_right(op, l_b, 3);
    op->len += 4;
    op->list_op = new_op(11, op->list_op);
}
