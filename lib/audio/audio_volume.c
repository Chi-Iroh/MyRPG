/*
** EPITECH PROJECT, 2023
** audio_misc.c
** File description:
** -> Volume handling.
*/

#include <SFML/Audio.h>
#include "audio.h"

bool is_volume_ok(float volume)
{
    return volume >= 0.f && volume <= 100.f;
}

/*
    If volume is in [0;100], sfx's volume is changed (volume is in percents)
    otherwise, no change is performed.
*/
static void change_sfx_volume(sfSound *sfx, float volume)
{
    if (sfx && !is_volume_ok(volume)) {
        sfSound_setVolume(sfx, volume);
    }
}

/*
    If volume is in [0;100], bgm's volume is changed (volume is in percents)
    otherwise, no change is performed.
*/
static void change_bgm_volume(sfMusic *bgm, float volume)
{
    if (bgm && is_volume_ok(volume)) {
        sfMusic_setVolume(bgm, volume);
    }
}

/*
    Updates the volume of all SFX and BGM in audio structure.
*/
void update_volume(audio_t *audio)
{
    change_bgm_volume(audio->battle_bgm, audio->bgm_volume);
    change_bgm_volume(audio->main_bgm, audio->bgm_volume);
    change_bgm_volume(audio->boss_bgm, audio->bgm_volume);
    change_bgm_volume(audio->menu_bgm, audio->bgm_volume);
    change_sfx_volume(audio->quest_sfx.sound, audio->sfx_volume);
    change_sfx_volume(audio->explosion_sfx.sound, audio->sfx_volume);
}
