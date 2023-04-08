/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that free a window struct
*/
#include "../include/window.h"

void free_window(window_t * window)
{
    sfRenderWindow_destroy(window->window);
    sfTexture_destroy(window->spritesheet);
    sfView_destroy(window->view);
    free_single_layer(window->core);
    free_single_layer(window->ui);
    free(window);
}
