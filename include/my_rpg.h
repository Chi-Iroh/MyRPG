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

    #include "../lib/my_graphics/my_graphics.h"

    #include <SFML/Audio.h>


    #include "characters.h"
    #include "button_simple.h"

    typedef struct inv_slot {
        draw_t* object;
        draw_t* slot;
        sfBool is_selected;
        struct inv_slot* prev;
        struct inv_slot* next;
    } inv_slot_t;

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
        menu_t* menu;
        inv_slot_t* first;
        list_button_t* all_btn;
    } game_src_t;


    game_src_t* init_game_sources(window_t* wd);

    void core(window_t* wd, game_src_t* g_src);
    void menu(window_t* wd, game_src_t* g_src);





    menu_t* init_menu(window_t* wd, list_button_t** all_btn);

    inv_slot_t* init_inventory(window_t *wd, int nb_slots);
    void change_slot_selected(game_src_t* g_src, sfMouseWheelScrollEvent evt);

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

#endif
