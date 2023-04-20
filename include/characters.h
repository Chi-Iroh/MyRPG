/*
** EPITECH PROJECT, 2023
** characters.h
** File description:
** -> Character types
*/

#ifndef MY_RPG_CHARACTERS_H
    #define MY_RPG_CHARACTERS_H

    #include <my_graphics.h>
    #include <drawable.h>

    extern const float POLITICS_STUDENT_CHARISM_MULTIPLIER;
    extern const float ART_STUDENT_TAG_XP_MULTIPLIER;
    extern const float WORKER_FENCE_COST_MULTIPLIER;
    extern const float WORKER_FENCE_BUILD_SPEED_MULTIPLIER;

    /*
        Beware of members order !
        Must be the same as in src/character_menu/character_menu.c
    */
    typedef enum {
        CHARACTER_RAILWAY_WORKER = 0,
        CHARACTER_DOCTOR = 1,
        CHARACTER_ART_STUDENT = 2,
        CHARACTER_POLITICS_STUDENT = 3,
        CHARACTER_PREFECT_SON = 4,
        CHARACTER_WORKER = 5,
        CHARACTER_TROUBLEMAKER = 6,
        CHARACTER_NONE,
        CHARACTER_ERROR
    } character_type_t;

    typedef enum {
        FROM_MARSEILLE,
        FROM_BRETAGNE,
        FROM_CORSE,
        FROM_PERPIGNAN,
        FROM_NORD_PAS_DE_CALAIS,
        FROM_SEINE_ST_DENIS
    } character_origin_t;

    typedef enum {
        CGT,
        NO_TRADE_UNION,
        LREM,
        EASY = CGT,
        INTERMEDIATE = NO_TRADE_UNION,
        HARD = LREM
    } trade_union_t;

    typedef enum {
        NO_WEAPON = 0,
        SPRAY_PAINT = 1 << 0,
        FIREWORKS_MORTAR = 1 << 1,
        BASEBALL_BAT = 1 << 2
    } weapon_t;

    typedef enum {
        NO_ARMOR = 0
    } armor_t;

    typedef struct inv_slot {
        draw_t* object;
        draw_t* slot;
        sfBool is_selected;
        struct inv_slot* prev;
        struct inv_slot* next;
    } inv_slot_t;

    typedef struct {
        drawable_t;
        character_type_t type;
        unsigned char hp;
        unsigned char hp_max;
        unsigned xp;
        unsigned char attack;
        unsigned char speed;
        unsigned char defense;
        unsigned char charism;
        unsigned char luck;
        unsigned char level;
        unsigned char n_allies;
        unsigned char n_floorboards;
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
        inv_slot_t* inv;
    } character_t;

#endif
