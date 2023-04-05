/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** header for text folder
*/
#ifndef MY_GRAPHICS_TEXT
    #define MY_GRAPHICS_TEXT
    /*
    ** =============================== TEXT ================================
    **
    */
    typedef struct text {} text_t;

    // implement text

    void draw_text(sfRenderTexture * texture, text_t * text);
    void free_text(text_t * text);
#endif
