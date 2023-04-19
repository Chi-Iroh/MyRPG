/*
** EPITECH PROJECT, 2023
** audio.h
** File description:
** -> Audio library to handle sounds and musics.
*/

#pragma once

#include <stdbool.h>
#include <SFML/Audio.h>

#ifdef DEFAULT_VOLUME
    #undef DEFAULT_VOLUME
#endif
// To be used with init_audio as init_audio(audio_ptr, DEFAULT_VOLUME)
#define DEFAULT_VOLUME DONT_CHANGE_VOLUME, DONT_CHANGE_VOLUME

typedef enum {
    AUDIO_NOT_YET_STARTED,
    AUDIO_PLAYING,
    AUDIO_PAUSED,
    AUDIO_STOPPED
} audio_state_t;

typedef struct {
    sfSound *sound;
    sfSoundBuffer *buffer;
} sound_t;

typedef struct {
    sfMusic *bgm;
    sfMusic *boss_bgm;
    sfMusic *battle_bgm;
    sfMusic *menu_bgm;
    sound_t quest_sfx;
    sound_t explosion_sfx;
    sfMusic *current_bgm;
    sound_t *current_sfx;
    audio_state_t bgm_state;
    audio_state_t sfx_state;
    float sfx_volume;
    float bgm_volume;
} audio_t;

typedef enum {
    AUDIO_CHANGED_NOTHING = 0,
    AUDIO_CHANGED_BGM_ONLY = 1 << 0,
    AUDIO_CHANGED_SFX_ONLY = 1 << 1,
    AUDIO_CHANGED_BGM_AND_SFX = AUDIO_CHANGED_BGM_ONLY | AUDIO_CHANGED_SFX_ONLY
} audio_play_t;

bool init_audio(audio_t *audio, float bgm_volume, float sfx_volume);
void free_audio(audio_t *audio);
void free_sfx(sound_t *sound);

bool is_volume_ok(float volume);
void update_volume(audio_t *audio);

audio_play_t pause_all_audio(audio_t *audio);
audio_play_t resume_all_audio(audio_t *audio);
audio_play_t stop_all_audio(audio_t *audio);

extern const char *const MENU_BGM_PATH;

extern const char *const QUEST_SFX_PATH;

extern const float DONT_CHANGE_VOLUME;
extern const float DEFAULT_BGM_VOLUME;
extern const float DEFAULT_SFX_VOLUME;
