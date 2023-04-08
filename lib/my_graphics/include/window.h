/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** header for window folder
*/
#ifndef MY_GRAPHICS_WINDOW
    #define MY_GRAPHICS_WINDOW
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include "vector.h"
    #include "layer.h"
    /*
    ** ============================== WINDOW ===============================
    ** size : vector that give width and height
    ** window : sfml dynamic window
    ** view : sfml camera to crop core layer if needed
    ** core : layer that display the core of the app
    ** ui : layer that display the user interface
    */
    typedef struct window {
        sfVector2f size;
        sfRenderWindow * window;
        sfTexture * spritesheet;
        sfView * view;
        layer_t * core;
        layer_t * ui;
    } window_t;

    window_t * init_window(void);
    window_t * create_window(const char * title, const sfVideoMode mode,
                            const char * file, const char * spritesheet);
    void actualize_window(window_t * window);
    void view_resize(window_t * window, sfVector2f size);
    void view_center(window_t * window, sfVector2f center);
    void view_set_rotation(window_t * window, float angle);
    void view_rotate(window_t * window, float angle);
    void view_zoom(window_t * window, float factor);
    void free_window(window_t * window);
#endif
