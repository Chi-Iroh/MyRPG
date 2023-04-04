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
    #include <stdbool.h>
    /*
    ** =============================== DRAW ================================
    ** texture : sfml struct for dynamic texture
    ** sprite : sprite_t struct
    ** show : boolean that says if the layer must be displayed or not
    ** next : pointer to the next layer
    **        is NULL if there is no next
    ** previous : pointer to the previous layer
    **            is NULL if there is no previous
    */

    // add animation

    typedef struct draw {
        sfRenderTexture * texture;
        void * drawable;
        bool show;
        void * next;
        void * previous;
    } draw_t;

    //draw_t * create_draw(sprite_t sprite, void * previous);
    void set_pos_draw(draw_t * draw, sfVector2f position);
    void set_size_draw(draw_t * draw, sfVector2f size);
    void set_angle_draw(draw_t * draw, double a);
    void set_data_draw(draw_t * draw,
                        sfVector2f position, sfVector2f size, double a);
    void switch_draw_show(draw_t * draw);
    void swap_draw_next(draw_t * draw);
    void swap_draw_previous(draw_t * draw);
    void sort_draws(draw_t * draw);
    void draw_single_draw(sfRenderTexture * texture, draw_t * draw);
    void draw_draws(sfRenderTexture * texture, draw_t * draw);
    void free_single_draw(draw_t * draw);
    void free_draws(draw_t * draw);
#endif
