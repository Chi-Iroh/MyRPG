/*
** EPITECH PROJECT, 2023
** audio_control.c
** File description:
** -> Function for audio pause/play/stop.
*/

#include "audio.h"
#include "audio_play.h"

void (*bgm_functions[3])(sfMusic*) = {
    [AUDIO_PLAY] = sfMusic_play,
    [AUDIO_STOP] = sfMusic_stop,
    [AUDIO_PAUSE] = sfMusic_pause
};

void (*sfx_functions[3])(sfSound*) = {
    [AUDIO_PLAY] = sfSound_play,
    [AUDIO_STOP] = sfSound_stop,
    [AUDIO_PAUSE] = sfSound_pause
};

/*
    Controls (pause/play/stop) the current BGM.
*/
bool audio_control_bgm(audio_t *audio, audio_control_t action)
{
    if (action < 0 || action >= AUDIO_CONTROL_MAX || !audio) {
        return false;
    }
    if (audio->current_bgm) {
        bgm_functions[action](audio->current_bgm);
        audio->bgm_state = (audio_state_t)action;
        return true;
    }
    return false;
}

/*
    Controls (pause/play/stop) the current SFX.
*/
bool audio_control_sfx(audio_t *audio, audio_control_t action)
{
    if (action < 0 || action >= AUDIO_CONTROL_MAX || !audio) {
        return false;
    }
    if (audio->current_sfx) {
        sfx_functions[action](audio->current_sfx->sound);
        audio->sfx_state = (audio_state_t)action;
        return true;
    }
    return false;
}

/*
    Controls (pause/play/stop) both the current BGM anf SFX.
*/
audio_play_t audio_control_all(audio_t *audio, audio_control_t action)
{
    audio_play_t changes = AUDIO_CHANGED_NOTHING;

    if (audio_control_bgm(audio, action)) {
        changes |= AUDIO_CHANGED_BGM_ONLY;
    }
    if (audio_control_sfx(audio, action)) {
        changes |= AUDIO_CHANGED_SFX_ONLY;
    }
    return changes;
}
