/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** init_character.c
*/

#include <my_rpg.h>
#include <my_graphics.h>
#include <audio.h>
#include <my_macros.h>
#include <character_menu.h>

character_t* init_character(window_t* wd)
{
    character_t* charac = malloc(sizeof(character_t));
    charac->type = select_character();
    if (charac->type == CHARACTER_ERROR || charac->type == CHARACTER_NONE) {
        free(charac);
        return NULL;
    }
    charac->inv = init_inventory(wd, 3);
    return charac;
}
