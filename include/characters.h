/*
** EPITECH PROJECT, 2023
** characters.h
** File description:
** -> Character types
*/

#ifndef MY_RPG_CHARACTERS_H
    #define MY_RPG_CHARACTERS_H

    #include "drawable.h"

    extern const float POLITICS_STUDENT_CHARISM_MULTIPLIER;
    extern const float ART_STUDENT_TAG_XP_MULTIPLIER;
    extern const float WORKER_FENCE_COST_MULTIPLIER;
    extern const float WORKER_FENCE_BUILD_SPEED_MULTIPLIER;

    typedef enum {
        POLITICS_STUDENT,
        ART_STUDENT,
        WORKER,
        PREFECT_SON,
        RAILWAY_WORKER,
        TROUBLEMAKER,
        DOCTOR
    } character_type_t;

    typedef enum {
        FROM_MARSEILLE,
        FROM_BRETAGNE,
        FROM_CORSE,
        FROM_SEINE_ST_DENIS
    } character_origin_t;

    typedef enum {
        CGT,
        EASY = CGT,
        NO_TRADE_UNION,
        INTERMEDIATE = NO_TRADE_UNION,
        LREM,
        HARD = LREM
    } trade_union_t;

    typedef enum {
        NO_WEAPON = 0,
        SPRAY_PAINT = 1 << 0,
        FIREWORKS_MORTAR = 1 << 1,
        BASEBALL_BAT = 1 << 2
    } weapon_t;

    typedef enum {
        NO_ARMOR
    } armor_t;

    typedef struct {
        drawable_t;
        character_type_t type;
        unsigned char hp;
        unsigned char hp_max;
        unsigned xp;
        unsigned char n_allies;
        unsigned char n_floorboards;
        unsigned char level;
        unsigned char speed;
        unsigned char attack;
        unsigned char defense;
        unsigned char luck;
        unsigned char charism;
        unsigned char ability_points;
        float crowd_multiplier;
        float tag_xp_multiplier;
        float fence_build_speed_multiplier;
        float fence_cost_multiplier;
        float charism_multiplier;
        float luck_multiplier;
        armor_t armor;
        weapon_t weapon;
        trade_union_t trade_union;
        character_origin_t origin;
    } character_t;

#endif
