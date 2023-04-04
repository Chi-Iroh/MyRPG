/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that actualize the displaying of a window
*/
#include "../include/window.h"

// reset screen -> apply view to core -> display core & ui -> actualize window
void actualize_window(window_t * window)
{
    sfRenderWindow_clear(window->window, sfBlack);
    sfRenderTexture_setView(window->core->texture, window->view);
    draw_layers(window->window, window->core);
    sfRenderWindow_display(window->window);
}
