/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** header for entity folder
*/
#ifndef MY_GRAPHICS_ENTITY
    #define MY_GRAPHICS_ENTITY
    /*
    ** ============================== ENTITY ===============================
    ** position : position x y z du coin superieur gauche du sprite
    ** size : taille du sprite
    ** scale : resize de la taille
    ** a : angle de rotation en degrees
    ** sprite : sfml struct for sprites
    */
    typedef struct entity entity_t;

    // add animation + scale position + auto scale

    void draw_entity(sfRenderTexture * texture, entity_t * entity);
    void free_entity(entity_t * entity);
#endif
