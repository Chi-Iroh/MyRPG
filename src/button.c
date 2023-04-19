/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mypaint-adrien.audiard
** File description:
** button.c
*/

#include "../include/my_rpg.h"

list_button_t* append_btn_list(list_button_t* list, button_s_t* btn)
{
    list_button_t* new_btn = malloc(sizeof(list_button_t));
    new_btn->btn = btn;
    new_btn->next = list;
    return new_btn;
}

button_s_t* set_button(list_button_t** a_btn, char* name,
    sfVector3f pos, sfVector2f size)
{
    shape_t* rect = create_shape(RECT, sfWhite, sfBlack, 3);
    text_t* text = create_text(name, NULL, sfBlack);
    data_t* data = create_data(pos, size, 0);
    data_t* data_txt = create_data(pos, set_2vector(30, 0), 0);
    button_s_t* button = malloc(sizeof(button_s_t));
    button->is_clicked = &is_button_clicked;
    button->is_hover = &is_button_hover;
    button->is_released = &is_button_released;
    button->state = NONE;
    button->rect = create_draw(rect, SHAPE, data);
    button->name = create_draw(text, TEXT, data_txt);
    button->layer_on = NULL;
    *a_btn = append_btn_list(*a_btn, button);
    return button;
}

sfBool is_button_clicked(button_s_t* b, sfMouseButtonEvent* e)
{
    sfFloatRect bound = get_global_bounds_draw(b->rect);
    if (sfFloatRect_contains(&bound, e->x, e->y)) {
        b->state = PRESSED;
        return sfTrue;
    }
    b->state = NONE;
    return sfFalse;
}

sfBool is_button_released(button_s_t* b, sfMouseButtonEvent* e)
{
    sfFloatRect bound = get_global_bounds_draw(b->rect);
    if (sfFloatRect_contains(&bound, e->x, e->y)) {
        b->state = RELEASED;
        return sfTrue;
    }
    b->state = NONE;
    return sfFalse;
}

sfBool is_button_hover(button_s_t* b, sfMouseMoveEvent* e)
{
    sfFloatRect bound = get_global_bounds_draw(b->rect);
    if (sfFloatRect_contains(&bound, e->x, e->y)) {
        b->state = b->state == PRESSED ? PRESSED : HOVER;
        return sfTrue;
    }
    if (IS_PRESSED(b))
        set_color_in_draw(b->rect, sfWhite);
    b->state = NONE;
    return sfFalse;
}
