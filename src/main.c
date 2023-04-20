/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main for my_rgpg
*/
#include <my_rpg.h>
#include <my_graphics.h>
#include <audio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    sfVideoMode mode = {1920, 1080, 32};
    window_t * window = create_window("49:3", mode, NULL);
    game_src_t* g_src = init_game_sources(window);

    if (window == NULL || g_src == NULL) {
        write(2, "terminating process\n", 20);
        free_main(window, g_src);
        return 84;
    }
    core(window, g_src);
    free_main(window, g_src);
    return 0;
}
