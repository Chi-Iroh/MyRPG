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
    /*
    ** =============================== DRAW ================================
    ** drawable : pointer to a struct among shape, sprite, entity, text
    ** type : enum that say to with struct the functions will refer
    ** id : number that identify multiple identical draws
    ** show : boolean that says if the layer must be displayed or not
    ** data : struct that contain position, size, angle and depth
    ** next : pointer to the next draw
    **            is NULL if there is no next
    ** previous : pointer to the previous draw
    **            is NULL if there is no previous
    */
    typedef enum draw_type {
        NO_TYPE,
        SPRITE,
        SHAPE,
        TEXT
    } draw_type_t;

    typedef struct draw draw_t;

    struct draw {
        void * drawable;
        draw_type_t type;
        int id;
        bool show;
        data_t * data;
        draw_t * next;
        draw_t * previous;
    };

    // ### ### Creation ### ###
    draw_t * init_draw(void);
    draw_t * create_draw(void * drawable, draw_type_t type,
                    data_t * data, draw_t * previous);

    // ### ### Struct manipulation ### ###
    void switch_draw_show(draw_t * draw);
    void swap_draw_next(draw_t * draw);
    void swap_draw_previous(draw_t * draw);

    // ### ### Data manipulation ### ###
    // SPRITE, SHAPE (CIRCLE & RECT), TEXT
    void set_pos_draw(draw_t * draw, sfVector3f position);
    // SPRITE, SHAPE (CIRCLE & RECT), TEXT
    void set_size_draw(draw_t * draw, sfVector2f size);
    // SPRITE, SHAPE (CIRCLE & RECT), TEXT
    void set_angle_draw(draw_t * draw, float angle);
    // see set_pos_draw, set_size_draw, set_angle_draw
    void set_data_draw(draw_t * draw, data_t * data);
    // SHAPE (CIRCLE & RECT), TEXT
    void set_color_in_draw(draw_t * draw, sfColor color);
    // SHAPE (CIRCLE & RECT), TEXT
    void set_color_out_draw(draw_t * draw, sfColor color);
    // SHAPE (CIRCLE & RECT), TEXT
    void set_thick_draw(draw_t * draw, int thick);
    // see set_color_in_draw, set_color_out_draw, set_thick_draw
    void set_attributes_draw(draw_t * draw, sfColor color_in,
                        sfColor color_out, int thick);
    // TEXT
    void set_string_draw(draw_t * draw, const char * string);
    // SPRITE
    void set_animation_draw(draw_t * draw, int nb_frame);
    // SPRITE, SHAPE (CIRCLE & RECT), TEXT
    void set_origin_draw(draw_t * draw, sfVector2f origin);
    // SPRITE, SHAPE (CIRCLE & RECT), TEXT
    sfVector2f get_position_draw(draw_t * draw);
    // SPRITE, SHAPE (CIRCLE & RECT), TEXT
    float get_rotation_draw(draw_t * draw);
    // SPRITE, SHAPE (CIRCLE & RECT), TEXT
    sfVector2f get_scale_draw(draw_t * draw);
    // SPRITE, SHAPE (CIRCLE & RECT), TEXT
    sfVector2f get_origin_draw(draw_t * draw);
    // SPRITE, SHAPE (CIRCLE & RECT), TEXT
    void move_draw(draw_t * draw, sfVector2f offset);
    // SPRITE, SHAPE (CIRCLE & RECT), TEXT
    void scale_draw(draw_t * draw, sfVector2f scale);
    // SPRITE, SHAPE (CIRCLE & RECT), TEXT
    void rotate_draw(draw_t * draw, float angle);
    // see move_draw, scale_draw, rotate_draw
    void modify_draw(draw_t * draw, sfVector2f offset,
                    sfVector2f scale, float angle);
    // SPRITE, SHAPE (CIRCLE & RECT), TEXT
    sfFloatRect get_local_bounds_draw(draw_t * draw);
    // SPRITE, SHAPE (CIRCLE & RECT), TEXT
    sfFloatRect get_global_bounds_draw(draw_t * draw);

    // ### ### Displaying ### ###
    draw_t * sort_draws(draw_t * draw);
    void draw_single_draw(sfRenderTexture * texture, draw_t * draw);
    void draw_draws(sfRenderTexture * texture, draw_t * draw);

    // ### ### Free ### ###
    void free_single_draw(draw_t * draw);
    void free_draws(draw_t * draw);
#endif
