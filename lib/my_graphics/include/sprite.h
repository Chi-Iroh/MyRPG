/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** header for sprite folder
*/
#ifndef MY_GRAPHICS_SPRITE
    #define MY_GRAPHICS_SPRITE
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include "vector.h"
    #include "rect.h"
    #include "data.h"
    /*
    ** ============================== SPRITES ==============================
    ** scale :
    ** sprite :
    ** texture :
    ** rect :
    ** animated :
    ** nb_frame :
    ** current :
    */
    typedef struct sprite {
        sfSprite * sprite;
        sfTexture * texture;
        sfIntRect rect;
        bool animated;
        int nb_frame;
        int current;
    } sprite_t;

    sprite_t * init_sprite(void);
    void set_pos_sprite(sprite_t * sprite, sfVector3f position);
    void set_scale_sprite(sprite_t * sprite, sfVector2f scale);
    void set_angle_sprite(sprite_t * sprite, float angle);
    void set_data_sprite(sprite_t * sprite, data_t * data);
    void set_texture_sprite(sprite_t * sprite, sfTexture * texture, sfIntRect rect);
    void set_animation_sprite(sprite_t * sprite, int nb_frame);
    void draw_sprite(sfRenderTexture * texture, sprite_t * sprite);
    void free_sprite(sprite_t * sprite);
#endif
