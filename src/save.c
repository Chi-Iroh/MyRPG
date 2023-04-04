/*
** EPITECH PROJECT, 2023
** save.c
** File description:
** -> Save game into a file.
*/

#include <stdio.h>
#include "my_macros.h"
#include "my_rpg.h"

bool save_to_file(char *filename, character_t *character)
{
    FILE *file = fopen(filename, "wb");
    bool status = true;

    if (!file) {
        return false;
    }
    status = fwrite(character, sizeof(*character), 1, file) == 1;
    fclose(file);
    return status;
}

bool read_from_file(char *filename, character_t *character)
{
    FILE *file = fopen(filename, "rb");
    bool status = true;

    if (!file) {
        return false;
    }
    status = fread(character, sizeof(*character), 1, file) == 1;
    fclose(file);
    return status;
}
