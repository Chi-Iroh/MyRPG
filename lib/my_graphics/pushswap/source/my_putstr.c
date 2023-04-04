/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** my_putstr.c
*/

#include "../include/pushswap.h"

int ps_putstr(char const *str, int len)
{
    write(1, str, len);
}
