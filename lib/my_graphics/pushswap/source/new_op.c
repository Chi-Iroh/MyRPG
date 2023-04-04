/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-pushswap-adrien.audiard
** File description:
** new_op.c
*/

#include "../include/pushswap.h"

int switch_op(char *op_str, int nbr, int i)
{
    switch (nbr) {
        case 1: return my_strcat(op_str, "sa ", i);
        case 2: return my_strcat(op_str, "sb ", i);
        case 3: return my_strcat(op_str, "sc ", i);
        case 4: return my_strcat(op_str, "pa ", i);
        case 5: return my_strcat(op_str, "pb ", i);
        case 6: return my_strcat(op_str, "ra ", i);
        case 7: return my_strcat(op_str, "rb ", i);
        case 8: return my_strcat(op_str, "rr ", i);
        case 9: return my_strcat(op_str, "rra ", i);
        case 10: return my_strcat(op_str, "rrb ", i);
        case 11: return my_strcat(op_str, "rrr ", i);
    }
}

void op_to_str(operations *op)
{
    int i = 0;
    op->str = malloc(sizeof(char) * (op->len + 1));
    op->str[0] = '\0';
    if (op->list_op->nbr != 0) {
        while (op->list_op->nbr != 0) {
            i = switch_op(op->str, op->list_op->nbr, i);
            op->list_op = op->list_op->previous;
            free(op->list_op->next);
        }
        op->str[op->len - 1] = '\n';
        ps_putstr(op->str, op->len);
    } else
        ps_putstr("\n", 1);
    free(op->list_op);
    free(op->str);
    free(op);
}

linked_list_t *new_op(int op_nbr, linked_list_t *next_op)
{
    linked_list_t *new_op = malloc(sizeof(linked_list_t));
    next_op->previous = new_op;
    new_op->nbr = op_nbr;
    new_op->next = next_op;
    return new_op;
}
