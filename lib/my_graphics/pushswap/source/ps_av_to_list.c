/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-pushswap-adrien.audiard
** File description:
** ps_av_to_list.c
*/

#include "../include/pushswap.h"

void set_previous(linked_list_t *list)
{
    linked_list_t *start = list;
    while (list->next != NULL) {
        list->next->previous = list;
        list = list->next;
    }
    list->next = start;
    start->previous = list;
}

linked_list_t *get_list_from_av(char **av, int ac)
{
    linked_list_t *list;
    linked_list_t *next_list = NULL;
    for (int i = ac - 1; i >= 1; i--) {
        list = malloc(sizeof(linked_list_t));
        if (str_to_nbr(av[i], list) == 84)
            return NULL;
        list->next = next_list;
        next_list = list;
    }
    set_previous(list);
    return list;
}
