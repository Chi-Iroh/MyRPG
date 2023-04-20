/*
** EPITECH PROJECT, 2022
** library MY_GRAPHICS
** File description:
** swap.c
*/

#include "../include/sort.h"

void swap(draw_t **list)
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
}

void swap_all(draw_t **l_a, draw_t **l_b)
{
    swap(l_a);
    swap(l_b);
}

void push_bis(draw_t **dest, draw_t **inter)
{
    (*inter)->previous = (*dest)->previous;
    (*inter)->previous->next = (*inter);
    (*dest)->previous = (*inter);
    (*inter)->next = *dest;
    (*dest) = (*inter);
}

void push(draw_t **dest, draw_t **src)
{
    if (*src == NULL)
        return;
    draw_t *inter = *src;
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
}
