/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** header for draw folder
*/
#ifndef MY_GRAPHICS_DRAW
    #define MY_GRAPHICS_DRAW
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include "data.h"
    #include "text.h"
    #include "shape.h"
    #include "sprite.h"
    #include "entity.h"
    /*
    ** =============================== DRAW ================================
    ** drawable : pointer to a struct among shape, sprite, entity, text
    ** type : enum that say to with struct the functions will refer
    ** show : boolean that says if the layer must be displayed or not
    ** data : struct that contain position, size, angle and depth
    ** next : pointer to the next draw
    **        is NULL if there is no next
    ** previous : pointer to the previous draw
    **            is NULL if there is no previous
    */
    typedef enum draw_type {
        NO_TYPE,
        SPRITE,
        ENTITY,
        SHAPE,
        TEXT
    } draw_type_t;

    typedef struct draw {
        void * drawable;
        draw_type_t type;
        bool show;
        data_t * data;
        void * next;
        void * previous;
    } draw_t;

    draw_t * init_draw(void);
    draw_t * create_draw(void * drawable, draw_type_t type,
                    data_t * data, void * previous);
    void set_data_draw(draw_t * draw, data_t * data);
    void switch_draw_show(draw_t * draw);
    void swap_draw_next(draw_t * draw);
    void swap_draw_previous(draw_t * draw);
    draw_t * sort_draws(draw_t * draw);
    void draw_single_draw(sfRenderTexture * texture, draw_t * draw);
    void draw_draws(sfRenderTexture * texture, draw_t * draw);
    void free_single_draw(draw_t * draw);
    void free_draws(draw_t * draw);
#endif
