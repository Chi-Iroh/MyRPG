/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-pushswap-adrien.audiard
** File description:
** display_list.c
*/

#include "../include/pushswap.h"

void display_list(linked_list_t *list)
{
    linked_list_t *begin = list;
    printf("\n");
    if (list == NULL)
        return;
    printf("%d ", list->nbr);
    list = list->next;
    while (list != begin) {
        printf("%d ", list->nbr);
        list = list->next;
    }
    printf("\n");
}
