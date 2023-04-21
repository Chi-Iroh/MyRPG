/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** resolution.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

void change_mouse_from_resolution(sfEvent* evt, sfVector2f size)
{
    if (evt->type == sfEvtMouseButtonPressed ||
        evt->type == sfEvtMouseButtonReleased) {
        evt->mouseButton.x *= WD_WIDTH / size.x;
        evt->mouseButton.y *= WD_HEIGHT / size.y;
    } else if (evt->type == sfEvtMouseMoved) {
        evt->mouseMove.x *= WD_WIDTH / size.x;
        evt->mouseMove.y *= WD_HEIGHT / size.y;
    }
}

void change_resolution(window_t* wd, sfVector2f size)
{
    sfVector2u size_u = {.x = size.x, .y = size.y};
    wd->size = size;
    sfRenderWindow_setSize(wd->window, size_u);
}

void resolutions(window_t* wd, menu_cat_t* settings)
{
    if (IS_RELEASED(settings->btn[1])) {
        change_resolution(wd, set_2vector(1920, 1080));
        settings->btn[1]->state = NONE;
    }
    if (IS_RELEASED(settings->btn[2])) {
        change_resolution(wd, set_2vector(1280, 720));
        settings->btn[2]->state = NONE;
    }
    if (IS_RELEASED(settings->btn[3])) {
        change_resolution(wd, set_2vector(960, 540));
        settings->btn[3]->state = NONE;
    }
    if (IS_RELEASED(settings->btn[4])) {
        change_resolution(wd, set_2vector(640, 360));
        settings->btn[4]->state = NONE;
    }
}
