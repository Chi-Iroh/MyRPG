/*
** EPITECH PROJECT, 2023
** audio_set.c
** File description:
** -> Sets or unsets BGM and SFX.
*/

#include "audio.h"

bool set_active_bgm(audio_t *audio, bgm_t bgm, bool start)
{
    if (bgm < 0 || bgm >= MAX_BGM) {
        return false;
    }
    if (audio->current_bgm) {
        sfMusic_stop(audio->current_bgm);
    }
    audio->current_bgm = *(bgm + (sfMusic**)(audio));
    update_volume(audio);
    if (start) {
        sfMusic_play(audio->current_bgm);
    }
    return true;
}
