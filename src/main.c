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
    audio_t audio;

    if (window == NULL || g_src == NULL ||
        !init_audio(&audio, DEFAULT_VOLUME)) {
        write(2, "terminating process\n", 20);
        free_main(window, g_src, &audio);
        return 84;
    }

    audio_control(&audio, AUDIO_PLAY);
    usleep(5'000'000); // waits 5 seconds
    audio.bgm_volume = 25.f;
    update_volume(&audio);
    usleep(5'000'000); // waits another 5 seconds
    if (!set_active_bgm(&audio, BOSS_BGM, false)) {
        write(STDERR_FILENO, "Failed to change BGM to boss !\n", 31);
    }
    window->splash->draw->next->next->show = false;
    window->splash->draw->next->show = false;
    core(window, g_src);
    free_main(window, g_src, &audio);
    return 0;
}
