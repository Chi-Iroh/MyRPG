/*
** EPITECH PROJECT, 2023
** audio_free.c
** File description:
** -> Frees audio and sound structures.
*/

#include <my_macros.h>
#include "audio.h"

/*
    Properly frees a sound_t structure.
*/
void free_sfx(sound_t *sound)
{
    if (sound) {
        FREE_IF_ALLOCATED(sound->buffer, sfSoundBuffer_destroy);
        FREE_IF_ALLOCATED(sound->sound, sfSound_destroy);
    }
}

/*
    Properly frees an audio_t structure.
*/
void free_audio(audio_t *audio)
{
    RETURN_IF(!audio);
    FREE_IF_ALLOCATED(audio->battle_bgm, sfMusic_destroy);
    FREE_IF_ALLOCATED(audio->bgm, sfMusic_destroy);
    FREE_IF_ALLOCATED(audio->boss_bgm, sfMusic_destroy);
    FREE_IF_ALLOCATED(audio->menu_bgm, sfMusic_destroy);
    free_sfx(&audio->explosion_sfx);
    free_sfx(&audio->quest_sfx);
}
