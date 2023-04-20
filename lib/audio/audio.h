/*
** EPITECH PROJECT, 2023
** audio.h
** File description:
** -> Audio library to handle sounds and musics.
*/

#pragma once

#include <stdbool.h>
#include <SFML/Audio.h>
#include "../lib/audio/audio_play.h"
#include "../lib/audio/audio_play.h"

#ifdef AUDIO_DEFAULT_VOLUME
    #undef AUDIO_DEFAULT_VOLUME
#endif
// To be used with init_audio as init_audio(audio_ptr, DEFAULT_VOLUME)
#define AUDIO_DEFAULT_VOLUME AUDIO_DONT_CHANGE_VOLUME, AUDIO_DONT_CHANGE_VOLUME

/*
    Enum to get the current state of a BGM / SFX, used in audio_t structure:
        audio.[bgm/sfx]_state.
    Beware, members order matters ! Must be the same as audio_control_t with
        AUDIO_NOT_YET_STARTED at the end !
*/
typedef enum {
    AUDIO_PLAYING = 0,
    AUDIO_PAUSED = 1,
    AUDIO_STOPPED = 2,
    AUDIO_NOT_YET_STARTED = 3
} audio_state_t;

/*
    Structure to represent a SFX.
    Is not meant to be directly used, as it's properly handled in audio_t.
*/
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
    Enum to list BGM, meant to be used as:
        audio_control_bgm(audio_ptr, MAIN_BGM) for instance.
    MAX_BGM isn't meant to be directly used, as it's a sentinel to highlight
        the max value.
*/
typedef enum {
    MAIN_BGM = 0,
    BOSS_BGM = 1,
    BATTLE_BGM = 2,
    MENU_BGM = 3,
    END_BGM = 4,
    MAX_BGM = 5
} bgm_t;

/*
    Enum to list SFX, meant to be used as:
        audio_control_sfx(audio_ptr, QUEST_SFX) for instance.
    MAX_SFX isn't meant to be directly used, as it's a sentinel to highlight
        the max value.
*/
typedef enum {
    QUEST_SFX = 0,
    EXPLOSION_SFX = 1,
    MAX_SFX = 2
} sfx_t;

/*
    Enum to represent what changes were effectively done when calling
        audio_control_all(audio_ptr, action)
*/
typedef enum {
    AUDIO_CHANGED_NOTHING = 0,
    AUDIO_CHANGED_BGM_ONLY = 1 << 0,
    AUDIO_CHANGED_SFX_ONLY = 1 << 1,
    AUDIO_CHANGED_BGM_AND_SFX = AUDIO_CHANGED_BGM_ONLY | AUDIO_CHANGED_SFX_ONLY
} audio_play_t;

/*
    Enum to represent the actions when calling audio_control_* functions.
    Beware, members order matters !
    Must be the same as audio_state_t !
    AUDIO_CONTROL_MAX is not meant to be used directly, as it is a sentinel
        to highliht the max value.
*/
typedef enum {
    AUDIO_PLAY = 0,
    AUDIO_PAUSE = 1,
    AUDIO_STOP = 2,
    AUDIO_CONTROL_MAX = 3
} audio_control_t;

void init_base(audio_t *audio, float bgm_volume, float sfx_volume);
bool init_bgm(sfMusic **bgm, const char *path, float bgm_volume);
bool init_sfx(sound_t *sound, const char *path, float volume);
bool init_audio(audio_t *audio, float bgm_volume, float sfx_volume);
void free_audio(audio_t *audio);
void free_sfx(sound_t *sound);

bool set_active_bgm(audio_t *audio, bgm_t bgm, bool start);
bool set_active_sfx(audio_t *audio, sfx_t sfx, bool start);

bool audio_control_bgm(audio_t *audio, audio_control_t action);
bool audio_control_sfx(audio_t *audio, audio_control_t action);
audio_play_t audio_control_all(audio_t *audio, audio_control_t action);

bool is_volume_ok(float volume);
void update_volume(audio_t *audio);

extern const char *const MENU_BGM_PATH;
extern const char *const BOSS_BGM_PATH;
extern const char *const BOSS_BGM_PATH;

extern const char *const QUEST_SFX_PATH;
extern const char *const EXPLOSION_SFX_PATH;

extern const float AUDIO_DONT_CHANGE_VOLUME;
extern const float AUDIO_DEFAULT_BGM_VOLUME;
extern const float AUDIO_DEFAULT_SFX_VOLUME;
