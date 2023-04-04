/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-pushswap-adrien.audiard
** File description:
** str_to_nbr.c
*/

#include "../include/pushswap.h"

int str_to_nbr(const char* str, linked_list_t *list)
{
    int neg = 1;
    int i = 0;
    int res = 0;
    if (str[0] == '-' && str[1] == '\0')
        return 84;
    if (str[0] == '-') {
        i++;
        neg = -1;
    }
    for (i; str[i] != '\0'; i++) {
        res *= 10;
        res += str[i] - '0';
        if (str[i] < '0' || str[i] > '9')
            return 84;
    }
    list->nbr = neg * res;
}
