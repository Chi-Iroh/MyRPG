/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** update_sheet.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

void other_dir(draw_t *draw, sfVector2f move, dir_cop_e *dir)
{
    if (move.x < 0 && move.y >= 0 && *dir != SW) {
        set_anim_rect_draw(draw, (sfIntRect) {192 * 6, 0, 64, 72});
        *dir = SW;
    }
    if (move.x < 0 && move.y <= 0 && *dir != NW) {
        set_anim_rect_draw(draw, (sfIntRect) {192 * 4, 0, 64, 72});
        *dir = NW;
    }
    if (move.x >= 0 && move.y >= 0 && *dir != SE) {
        set_anim_rect_draw(draw, (sfIntRect) {192 * 7, 0, 64, 72});
        *dir = SE;
    }
    if (move.x >= 0 && move.y <= 0 && *dir != NE) {
        set_anim_rect_draw(draw, (sfIntRect) {192 * 5, 0, 64, 72});
        *dir = NE;
    }
}

void get_sprt_cop(draw_t *draw, sfVector2f move, dir_cop_e *dir)
{
    if (move.x == 0 && move.y == 0) {
        set_anim_rect_draw(draw, (sfIntRect) {0, 0, 64, 72});
        return;
    }
    if (move.y < 0 && move.x == 0 && *dir != N) {
        set_anim_rect_draw(draw, (sfIntRect) {192, 0, 64, 72});
        *dir = N;
    }
    if (move.y >= 0 && move.x == 0 && *dir != S) {
        set_anim_rect_draw(draw, (sfIntRect) {0, 0, 64, 72});
        *dir = S;
    }
    if (move.x < 0 && move.y == 0 && *dir != E) {
        set_anim_rect_draw(draw, (sfIntRect) {384, 0, 64, 72});
        *dir = E;
    }
    if (move.x >= 0 && move.y == 0 && *dir != W) {
        set_anim_rect_draw(draw, (sfIntRect) {576, 0, 64, 72});
        *dir = W;
    } other_dir(draw, move, dir);
}
