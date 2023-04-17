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

    draw_t * init_draw(void);
    draw_t * create_draw(void * drawable, draw_type_t type,
                    data_t * data, draw_t * previous);
    void switch_draw_show(draw_t * draw);
    void swap_draw_next(draw_t * draw);
    void swap_draw_previous(draw_t * draw);
    //void set_pos_sprite(sprite_t * sprite, sfVector3f position);
    //void set_size_shape(shape_t * shape, sfVector2f size);
    //void set_scale_sprite(sprite_t * sprite, sfVector2f scale);
    //void set_angle_sprite(sprite_t * sprite, float angle);
    void set_data_draw(draw_t * draw, data_t * data);
    // SHAPE (CIRCLE & RECT), TEXT
    void set_color_in_draw(draw_t * draw, sfColor color);
    // SHAPE (CIRCLE & RECT), TEXT
    void set_color_out_draw(draw_t * draw, sfColor color);
    // SHAPE (CIRCLE & RECT), TEXT
    void set_thick_draw(draw_t * draw, int thick);
    // SHAPE (CIRCLE & RECT), TEXT
    void set_attributes_draw(draw_t * draw, sfColor color_in,
                        sfColor color_out, int thick);
    //void set_string_text(text_t * text, const char * string);
    //void set_animation_sprite(sprite_t * sprite, int nb_frame);
    //*void sfText_setOrigin(sfText* text, sfVector2f origin);
    //sfVector2f sfText_getPosition(const sfText* text);
    //float sfText_getRotation(const sfText* text);
    //sfVector2f sfText_getScale(const sfText* text);
    //sfVector2f sfText_getOrigin(const sfText* text);
    //void sfText_move(sfText* text, sfVector2f offset);
    //void sfText_rotate(sfText* text, float angle);
    //sfFloatRect sfText_getLocalBounds(const sfText* text);
    //*sfFloatRect sfText_getGlobalBounds(const sfText* text);
    draw_t * sort_draws(draw_t * draw);
    void draw_single_draw(sfRenderTexture * texture, draw_t * draw);
    void draw_draws(sfRenderTexture * texture, draw_t * draw);
    void free_single_draw(draw_t * draw);
    void free_draws(draw_t * draw);
#endif
