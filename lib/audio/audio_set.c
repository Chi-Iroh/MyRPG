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
        bgm_functions[AUDIO_STOP](audio->current_bgm);
    }
    audio->current_bgm = *(bgm + (sfMusic**)(audio));
    update_volume(audio);
    if (start) {
        bgm_functions[AUDIO_PLAY](audio->current_bgm);
    }
    return true;
}

bool set_active_sfx(audio_t *audio, sfx_t sfx, bool start)
{
    if (sfx < 0 || sfx >= MAX_SFX) {
        return false;
    }
    if (audio->current_sfx) {
        sfx_functions[AUDIO_STOP](audio->current_sfx->sound);
    }
    audio->current_sfx = (sound_t*)((sfMusic**)audio + MAX_BGM) + sfx;
    update_volume(audio);
    if (start) {
        sfx_functions[AUDIO_PLAY](audio->current_sfx->sound);
    }
    return true;
}
