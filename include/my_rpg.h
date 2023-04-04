/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** header for MY_RPG project
*/

#ifndef MY_RPG_H
    #define MY_RPG_H

    #include <stdbool.h>
    #include "characters.h"

    bool save_to_file(char *filename, character_t *character);
    bool read_from_file(char *filename, character_t *character);

#endif
