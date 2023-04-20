/*
** EPITECH PROJECT, 2023
** audio_path.h
** File description:
** -> Paths for audio assets.
*/

#pragma once

#ifdef BGM
    #undef BGM
#endif
/*
    Macro to ease BGM path handling.
    path must be an HARDCODED literal string which only contains the title,
    then BGM("Bonetrousle") will be "musics/Bonetrousle.ogg"
*/
#define BGM(path) "musics/" path ".ogg"

#ifdef SFX
    #undef SFX
#endif
/*
    Macro to ease SFX path handling.
    path must be an HARDCODED literal string which only contains the title,
    then SFX("explosion") will be "musics/explosion.ogg"
*/
#define SFX(path) "sounds/" path ".ogg"

const char *const MENU_BGM_PATH = BGM("Kevin MacLeod - Happy Bee");
const char *const BOSS_BGM_PATH = BGM("Bonetrousle");

const char *const QUEST_SFX_PATH = SFX("Discord Notification");
const char *const EXPLOSION_SFX_PATH = SFX("explosion");
