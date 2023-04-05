/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** header for shape folder
*/
#ifndef MY_GRAPHICS_SHAPE
    #define MY_GRAPHICS_SHAPE
    /*
    ** ============================== SHAPES ===============================
    ** position : position du coin superieur gauche du sprite
    **
    */
    typedef struct shape {} shape_t;

    // create sub struct for rectangle circle shape

    void draw_shape(sfRenderTexture * texture, shape_t * shape);
    void free_shape(shape_t * shape);
#endif
