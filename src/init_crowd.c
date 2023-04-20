/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** init_crowd.c
*/

#include "../include/my_rpg.h"
#include "../lib/my_graphics/my_graphics.h"

void init_sprite_sheet(sprite_sht_t *spsht, sfSprite *sprite)
{
    sfIntRect textureRect = {0, 0, 48, 72};
    spsht->clock = sfClock_create();
    spsht->cur_frame = 0;
    spsht->elapsedTime = 0;
    spsht->dir = -1;
    sfSprite_setTextureRect(sprite, textureRect);
}

cop_t **init_crowd_cop(window_t* wd)
{
    sfVector2f sprite_size = {288, 72};
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
    sfVector2f sprite_size = {288, 72};
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

player_t *init_player(window_t* wd)
{
    player_t *player = malloc(sizeof(player_t));
    data_t *data = create_data(set_3vector(WD_WIDTH / 2, WD_HEIGHT / 2, 50),
    set_2vector(48, 72), 0.f);
    sprite_t *sprite = init_sprite();
    sfTexture *texture = rand_skin();

    set_texture_sprite(sprite, texture, (sfIntRect) {0, 0, 48, 72});
    player->draw = create_draw(sprite, SPRITE, data);
    //set_animation_draw(player->draw, 3);
    set_origin_draw(player->draw, (sfVector2f) {48 / 2, 72 / 2});
    append_draw_layer(wd->core, player->draw);
    return player;
}

void init_crowd(crowd_t *crowd, window_t* wd)
{
    crowd->player = init_player(wd);
    crowd->mob = init_crowd_mob(wd);
    crowd->cop = init_crowd_cop(wd);
    
}
