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
#define BGM(path) "musics/" path ".ogg"

#ifdef SFX
    #undef SFX
#endif
#define SFX(path) "sounds/" path ".ogg"

const char *const MENU_BGM_PATH = BGM("Kevin MacLeod - Happy Bee");
const char *const BOSS_BGM_PATH = BGM("Bonetrousle");

const char *const QUEST_SFX_PATH = SFX("Discord Notification");
