/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** button_simple.h
*/

#ifndef BUTTON_SIMPLE_H
    #define BUTTON_SIMPLE_H

    #include "my_rpg.h"

    #define IS_HOVER(b) (b->state == HOVER)
    #define IS_PRESSED(b) (b->state == PRESSED)
    #define IS_RELEASED(b) (b->state == RELEASED)

    enum e_gui_state {
        NONE = 0,
        HOVER,
        PRESSED,
        RELEASED,
    };

    typedef struct button_s {
        draw_t* name;
        draw_t* rect;
        sfBool (*is_clicked)(struct button_s* , sfMouseButtonEvent*);
        sfBool (*is_hover)(struct button_s* , sfMouseMoveEvent*);
        sfBool (*is_released)(struct button_s* , sfMouseButtonEvent*);
        enum e_gui_state state;
        layer_t* layer_on;
    } button_s_t;

    typedef struct list_button {
        button_s_t* btn;
        struct list_button* next;
    } list_button_t;

    typedef struct sliding_button {
        float min_value;
        float max_value;
        float (*value)(struct sliding_button*);
        draw_t* line;
        button_s_t* btn;
    } sliding_button_t;


    button_s_t* set_button(list_button_t** a_btn, char* name, sfVector3f pos,
        sfVector2f size);



    sfBool is_button_released(button_s_t* b, sfMouseButtonEvent* e);
    sfBool is_button_clicked(button_s_t* b, sfMouseButtonEvent* e);
    sfBool is_button_hover(button_s_t* b, sfMouseMoveEvent* e);
    void sliding_button_pressed(window_t* wd, sliding_button_t* s_btn);

    void destroy_button(button_s_t* button);

#endif
