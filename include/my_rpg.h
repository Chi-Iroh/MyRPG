/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** header for MY_RPG project
*/

#ifndef MY_RPG_H
    #define MY_RPG_H

    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>

    #include <my_graphics.h>
    #include <audio.h>

    #include <SFML/Audio.h>

    #include "characters.h"
    #include "button_simple.h"

    typedef struct {
        draw_t** title;
        button_s_t** btn;
        sliding_button_t** s_btn;
        layer_t* menu_cat_l;
    } menu_cat_t;

    typedef struct {
        button_s_t* b_start;
        button_s_t* b_settings;
        button_s_t* b_quit;
        menu_cat_t* settings;
        draw_t* bg;
        layer_t* menu_l;
        sfBool show;
    } menu_t;

    typedef struct {
        button_s_t* b_resume;
        button_s_t* b_menu;
        button_s_t* b_save_and_menu;
        button_s_t* b_save_and_quit;
        button_s_t* b_load;
        button_s_t* b_settings;
        menu_cat_t* settings;
        draw_t* bg;
        layer_t* pause_l;
        sfBool show;
    } pause_t;

    typedef struct {
        pause_t* pause_menu;
        character_t* character;
        //crowd_t* crowd;
    } game_t;

    typedef struct {
        menu_t* menu;
        game_t* game;
        list_button_t* all_btn;
    } game_src_t;


    game_src_t* init_game_sources(window_t* wd);

    void core(window_t* wd, game_src_t* g_src);
    void menu(window_t* wd, game_src_t* g_src);

    menu_t* init_menu(window_t* wd, list_button_t** all_btn);

    inv_slot_t* init_inventory(window_t *wd, int nb_slots);
    void change_slot_selected(character_t* charac, sfMouseWheelScrollEvent evt,
        game_src_t* g_src);

    bool save_to_file(char *filename, character_t *character);
    bool read_from_file(char *filename, character_t *character);

    void button_pressed(window_t* wd, list_button_t* all_btn,
        sfMouseButtonEvent evt);
    void sliding_button_moved(list_button_t* all_btn, sfMouseMoveEvent evt);

    void analyse_events(window_t* wd, sfEvent event,
        game_src_t *g_src);
    void mouse_moved(sfMouseMoveEvent evt, game_src_t* g_src);
    void mouse_button_pressed(window_t* wd, sfMouseButtonEvent evt,
        game_src_t* g_src);
    void mouse_button_released(sfRenderWindow* wd, sfMouseButtonEvent evt,
        list_button_t* all_btn);

    void free_g_src(game_src_t* g_src);
    void free_main(window_t *window, game_src_t *g_src, audio_t *audio);

#endif
