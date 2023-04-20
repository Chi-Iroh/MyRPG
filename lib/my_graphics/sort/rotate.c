/*
** EPITECH PROJECT, 2022
** library MY_GRAPHICS
** File description:
** rotate.c
*/

#include "../include/sort.h"

void rotate(draw_t **list)
{
    if (*list == NULL)
        return;
    *list = (*list)->next;
}

void rotate_all(draw_t **l_a, draw_t **l_b)
{
    rotate(l_a);
    rotate(l_b);
}

void rotate_right(draw_t **list)
{
    if (*list == NULL)
        return;
    *list = (*list)->previous;
}

void rotate_right_all(draw_t **l_a, draw_t **l_b)
{
    rotate_right(l_a);
    rotate_right(l_b);
}
