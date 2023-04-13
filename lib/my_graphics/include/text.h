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
    typedef struct text {
        sfText * text;
        sfUint32 * string;
        sfFont * font;
        sfColor color;
    } text_t;

    text_t * init_text(void);
    text_t * create_text(const char * string, sfFont * font, sfColor color);
    void set_pos_text(text_t * text, sfVector3f position);
    void set_size_text(text_t * text, sfVector2f size);
    void set_angle_text(text_t * text, float angle);
    void set_data_text(text_t * text, data_t * data);
    void set_color_text(text_t * text, sfColor color);
    void set_font_text(text_t * text, sfFont * font);
    void set_string_text(text_t * text, const char * string);
    void draw_text(sfRenderTexture * texture, text_t * text);
    void free_text(text_t * text);
#endif
