/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** init_crowd.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

cop_t **init_crowd_cop(window_t* wd)
{
    cop_t **cop = malloc(sizeof(cop_t*) * CROWD_SIZE);
    for (int i = 0; i < CROWD_SIZE; i++) {
        cop[i] = malloc(sizeof(cop_t));
        cop[i]->clock = sfClock_create();
        sprite_t *sprite = init_sprite();
        sfTexture *texture = sfTexture_createFromFile
        ("images/spritesheets/casseur_spritesheet.png", NULL);
        sfVector2f pos = get_random_position();
        data_t *data = create_data(set_3vector(pos.x, pos.y, 25),
        set_2vector(48, 72), 0.f);
        set_texture_sprite(sprite, texture, (sfIntRect) {0, 0, 48, 72});

        cop[i]->draw = create_draw(sprite, SPRITE, data);
        set_origin_draw(cop[i]->draw, (sfVector2f) {48 / 2, 72 / 2});

        append_draw_layer(wd->core, cop[i]->draw);
    }
    return cop;
}

mob_t **init_crowd_mob(window_t* wd)
{
    mob_t **mob = malloc(sizeof(cop_t*) * CROWD_SIZE);
    for (int i = 0; i < CROWD_SIZE; i++) {
        mob[i] = malloc(sizeof(mob_t));
        sprite_t *sprite = init_sprite();
        sfTexture *texture = rand_skin();
        sfVector2f pos = get_random_position();
        data_t *data = create_data(set_3vector(pos.x, pos.y, 25),
        set_2vector(48, 72), 0.f);
        set_texture_sprite(sprite, texture, (sfIntRect) {0, 0, 48, 72});

        mob[i]->draw = create_draw(sprite, SPRITE, data);
        set_origin_draw(mob[i]->draw, (sfVector2f) {48 / 2, 72 / 2});
        append_draw_layer(wd->core, mob[i]->draw);
        mob[i]->in_mob = OUT;
        mob[i]->dir = (pos.y > WD_HEIGHT / 2 && pos.y <= WD_HEIGHT) ? 1 : -1;

        //set_animation_draw(mob[i]->draw, 3);
    }
    return mob;
}

void init_bar(player_t *player, window_t* wd)
{
    data_t *data_hp = create_data(set_3vector(70, 15, 50),
    set_2vector(250, 35), 0.f);
    shape_t *shape_hp = create_shape(RECT, sfGreen, sfBlack, 3);
    init_progress_bar(wd, &player->hp, data_hp, shape_hp);
    data_t *data_exp = create_data(set_3vector(450, 15, 50),
    set_2vector(250, 35), 0.f);
    shape_t *shape_exp = create_shape(RECT, sfBlue, sfBlack, 3);
    init_progress_bar(wd, &player->exp, data_exp, shape_exp);
    data_t *data_hp_txt = create_data(set_3vector(10, 10, 50),
    set_2vector(0, 35), 0.f);
    data_t *data_exp_txt = create_data(set_3vector(370, 10, 50),
    set_2vector(0, 35), 0.f);
    text_t *text_hp = create_text("HP", NULL, sfBlack);
    text_t *text_exp = create_text("EXP", NULL, sfBlack);
    draw_t *draw_hp = create_draw(text_hp, TEXT, data_hp_txt);
    draw_t *draw_exp = create_draw(text_exp, TEXT, data_exp_txt);
    append_draw_layer(wd->ui, draw_hp);
    append_draw_layer(wd->ui, draw_exp);
}

player_t *init_player(window_t* wd)
{
    player_t *player = malloc(sizeof(player_t));
    data_t *data = create_data(set_3vector(WD_WIDTH / 2 + 400, WD_HEIGHT / 2 + 400, 50),
    set_2vector(48, 72), 0.f);
    sprite_t *sprite = init_sprite();
    sfTexture *texture = rand_skin();
    set_texture_sprite(sprite, texture, (sfIntRect) {0, 0, 48, 72});
    player->draw = create_draw(sprite, SPRITE, data);
    //set_animation_draw(player->draw, 3);
    set_origin_draw(player->draw, (sfVector2f) {48 / 2, 72 / 2});
    append_draw_layer(wd->core, player->draw);
    init_bar(player, wd);
    return player;
}

void init_crowd(crowd_t *crowd, window_t* wd)
{
    crowd->player = init_player(wd);
    crowd->mob = init_crowd_mob(wd);
    crowd->cop = init_crowd_cop(wd);
    
}
