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

/*
    Structure for BGM and SFX.
    Beware, members order matters !
        -> At the top come the BGM
        -> Then the SFX
        -> And the current pointers (BGM firstly, followed by SFX)
        -> States at next (BGM then SFX)
        -> And volumes come at the end (BGM then SFX)
    Breaking these rules may break some functionnalities and may cause crash.
*/
typedef struct {
    sfMusic *main_bgm;
    sfMusic *boss_bgm;
    sfMusic *battle_bgm;
    sfMusic *menu_bgm;
    sfMusic *end_bgm;
    sound_t quest_sfx;
    sound_t explosion_sfx;
    sfMusic *current_bgm;
    sound_t *current_sfx;
    audio_state_t bgm_state;
    audio_state_t sfx_state;
    float sfx_volume;
    float bgm_volume;
} audio_t;

/*
    MAX_BGM is the number of BGM
*/
typedef enum {
    MAIN_BGM,
    BOSS_BGM,
    BATTLE_BGM,
    MENU_BGM,
    END_BGM,
    MAX_BGM
} bgm_t;

typedef enum {
    QUEST_SFX,
    EXPLOSION_SFX,
    MAX_SFX
} sfx_t;

typedef enum {
    AUDIO_CHANGED_NOTHING = 0,
    AUDIO_CHANGED_BGM_ONLY = 1 << 0,
    AUDIO_CHANGED_SFX_ONLY = 1 << 1,
    AUDIO_CHANGED_BGM_AND_SFX = AUDIO_CHANGED_BGM_ONLY | AUDIO_CHANGED_SFX_ONLY
} audio_play_t;

void init_base(audio_t *audio, float bgm_volume, float sfx_volume);
bool init_bgm(sfMusic **bgm, const char *path, float bgm_volume);
bool init_sfx(sound_t *sound, const char *path, float volume);
bool init_audio(audio_t *audio, float bgm_volume, float sfx_volume);
void free_audio(audio_t *audio);
void free_sfx(sound_t *sound);

bool set_bgm_active(audio_t *audio, bgm_t *bgm);

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
