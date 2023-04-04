/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-pushswap-adrien.audiard
** File description:
** pushswap.h
*/

#ifndef PUSHSWAP_
    #define PUSHSWAP_

    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>

    typedef struct linked_list {
        int nbr;
        struct linked_list *next;
        struct linked_list *previous;
    } linked_list_t;

    typedef struct {
        int len;
        char *str;
        linked_list_t *list_op;
    } operations;

    linked_list_t *get_list_from_av(char **av, int ac);
    int str_to_nbr(const char* str, linked_list_t *list);
    void set_previous(linked_list_t *list);

    void op_to_str(operations *op);
    linked_list_t *new_op(int op_nbr, linked_list_t *next_op);

    linked_list_t *partition(operations *op, linked_list_t *l_a,
        linked_list_t *pivot);

    void swap(operations *op, linked_list_t **list, int type);
    void swap_all(operations *op, linked_list_t **l_a, linked_list_t **l_b);
    void push(operations *op, linked_list_t **dest, linked_list_t **src,
        int type);
    void rotate(operations *op, linked_list_t **list, int type);
    void rotate_all(operations *op, linked_list_t **l_a, linked_list_t **l_b);
    void rotate_right(operations *op, linked_list_t **list, int type);
    void rotate_right_all(operations *op, linked_list_t **l_a,
        linked_list_t **l_b);


    void display_list(linked_list_t *list);

    int ps_putstr(char const *str, int len);

    int my_strcat(char *dest, char const *src, int i);

#endif /* PUSHSWAP_ */
