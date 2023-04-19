/*
** EPITECH PROJECT, 2023
** audio_play.c
** File description:
** -> Plays and switches between BGM and SFX.
*/

#include "audio.h"
#include "audio_play.h"

audio_play_t pause_all_audio(audio_t *audio)
{
    AUDIO_CHANGE(audio, pause);
}

audio_play_t resume_all_audio(audio_t *audio)
{
    AUDIO_CHANGE(audio, play);
}

audio_play_t stop_all_audio(audio_t *audio)
{
    AUDIO_CHANGE(audio, stop);
}
