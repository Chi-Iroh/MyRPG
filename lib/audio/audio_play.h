/*
** EPITECH PROJECT, 2023
** audio_play.h
** File description:
** -> Macro for audio playing.
*/

#pragma once

#ifdef AUDIO_CHANGE
    #undef AUDIO_CHANGE
#endif
#define AUDIO_CHANGE(audio, action) {                   \
    audio_play_t changes = AUDIO_CHANGED_NOTHING;       \
                                                        \
    if ((audio)->current_bgm) {                         \
        sfMusic_##action((audio)->current_bgm);         \
        (audio)->bgm_state = AUDIO_PAUSED;              \
        changes |= AUDIO_CHANGED_BGM_ONLY;              \
    }                                                   \
    if ((audio)->current_sfx) {                         \
        sfSound_##action((audio)->current_sfx->sound);  \
        (audio)->sfx_state = AUDIO_PAUSED;              \
        changes |= AUDIO_CHANGED_SFX_ONLY;              \
    }                                                   \
    return changes;                                     \
}
