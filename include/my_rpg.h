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
    #include <crowd.h>
    #include <math.h>

    #include <characters.h>
    #include <countryball.h>
    #include <speech_bubble.h>
    #include "button_simple.h"
    #include <my_macros.h>
    #include <my.h>

    typedef struct interface_s {
        draw_t** stat_name;
        draw_t** stat_nb;
        button_s_t** stat_btns;
    } interface_t;

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
        button_s_t* b_save;
        button_s_t* b_load;
        button_s_t* b_settings;
        button_s_t* b_quit;
        menu_cat_t* settings;
        layer_t* pause_l;
        sfBool show;
    } pause_t;

    typedef struct {
        pause_t* pause_menu;
        character_t* character;
        crowd_t crowd;
    } game_t;

    typedef struct {
        menu_t* menu;
        game_t* game;
        list_button_t* all_btn;
        audio_t audio;
        speech_bubble_t speech_bubble;
    } game_src_t;


    game_src_t* init_game_sources(window_t* wd);

    void menu(window_t* wd, game_src_t* g_src);
    void core(window_t* wd, game_src_t* g_src);
    void pause_menu(window_t* wd, game_src_t* g_src);
    bool init_crowd(game_t *game, window_t* wd, list_button_t** a_btn);
    player_t *init_player(window_t* wd, game_t *game);
    void init_stat(stat_t *stat, sfVector3f stat_value, float hp);
    void update_stat_interface(draw_t** stat_nb, stat_t stat);
    void update_stat(stat_t *stat, int type);
    interface_t* init_stat_interface(stat_t stat, layer_t* ui,
        list_button_t** a_btn);
    void settings_core(window_t* wd, game_src_t* g_src, menu_cat_t* settings);

    menu_t* init_menu(window_t* wd, list_button_t** all_btn);
    menu_cat_t* init_settings(list_button_t** all_btn, layer_t* spl);
    pause_t* init_pause_menu(window_t* wd, list_button_t** btns,
        game_src_t* g_src);

    inv_slot_t* init_inventory(window_t *wd, int nb_slots);
    character_t* init_character(window_t* wd);
    void change_slot_selected(character_t* charac, sfMouseWheelScrollEvent evt,
        game_src_t* g_src);

    bool save_to_file(char *filename, character_t *character);
    bool read_from_file(char *filename, character_t *character);

    void button_pressed(window_t* wd, list_button_t* all_btn,
        sfMouseButtonEvent evt, game_src_t* g_src);
    void sliding_button_moved(list_button_t* all_btn, sfMouseMoveEvent evt);

    void analyse_events(window_t* wd, sfEvent event,
        game_src_t *g_src);
    void mouse_moved(sfMouseMoveEvent evt, game_src_t* g_src);
    void mouse_button_pressed(window_t* wd, sfMouseButtonEvent evt,
        game_src_t* g_src);
    void mouse_button_released(sfRenderWindow* wd, sfMouseButtonEvent evt,
        list_button_t* all_btn);


    void change_mouse_from_resolution(sfEvent* evt, sfVector2f size);
    void change_resolution(window_t* wd, sfVector2f size);
    void resolutions(window_t* wd, menu_cat_t* settings);


    void free_g_src(game_src_t* g_src);
    void free_main(window_t *window, game_src_t *g_src);

#endif
