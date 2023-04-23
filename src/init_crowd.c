/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** init_crowd.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

void init_cop_hp_bar(window_t *wd, cop_t * cop, sfVector2f pos)
{
    data_t *data_hp = create_data(set_3vector(pos.x, pos.y - 20, 50),
    set_2vector(80, 10), 0.f);
    shape_t *shape_hp = create_shape(RECT, sfRed, sfBlack, 3);
    init_progress_bar(wd, &cop->hp, data_hp, shape_hp);
    set_origin_draw(cop->hp.fill, (sfVector2f)
    {data_hp->size.x / 2, data_hp->size.y / 2});
    append_draw_layer(wd->core, cop->hp.fill);
}

cop_t **init_crowd_cop(window_t* wd)
{
    cop_t **cop = malloc(sizeof(cop_t*) * CROWD_SIZE);
    for (int i = 0; i < CROWD_SIZE; i++) {
        cop[i] = malloc(sizeof(cop_t));
        cop[i]->clock = sfClock_create();
        sprite_t *sprite = init_sprite();
        sfTexture *texture = sfTexture_createFromFile
        ("images/spritesheets/crs_spritesheet.png", NULL);
        sfVector2f pos = get_random_position(wd);
        pos.x += wd->map_size.x;
        data_t *data = create_data(set_3vector(pos.x, pos.y, 0),
        set_2vector(64, 72), 0.f);
        set_texture_sprite(sprite, texture, (sfIntRect) {0, 0, 64, 72});
        cop[i]->draw = create_draw(sprite, SPRITE, data);
        set_origin_draw(cop[i]->draw, (sfVector2f) {64 / 2, 72 / 2});
        append_draw_layer(wd->core, cop[i]->draw);
        cop[i]->stat = (stat_t) {.damage = 5, .hp = 80, .speed = 5,
        .defense = 5};
        init_cop_hp_bar(wd, cop[i], pos);
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
        sfVector2f pos = get_random_position(wd);
        pos.x -= wd->map_size.x;
        data_t *data = create_data(set_3vector(pos.x, pos.y, 0),
        set_2vector(48, 72), 0.f);
        set_texture_sprite(sprite, texture, (sfIntRect) {0, 0, 48, 72});
        mob[i]->draw = create_draw(sprite, SPRITE, data);
        set_origin_draw(mob[i]->draw, (sfVector2f) {48 / 2, 72 / 2});
        append_draw_layer(wd->core, mob[i]->draw);
        mob[i]->in_mob = OUT;
        mob[i]->dir = 1;
    }
    return mob;
}

bool init_crowd(game_t *game, window_t* wd, list_button_t** a_btn,
    game_src_t* g_src)
{
    game->crowd = malloc(sizeof(crowd_t));
    game->crowd->player = init_player(wd, game);
    if (game->crowd->player == NULL) {
        game->crowd = NULL;
        free(game->crowd);
        return false;
    }
    game->crowd->player->weapon = game->all_weapons[0];
    update_weapon_ui(game->all_weapons, game->crowd->player->weapon,
        game->pause_menu->player->other[1]);
    update_stat_ui(game->crowd->player->stat, game->stat_ui);
    append_draw_layer(wd->ui, create_draw(create_shape(RECT,
    sfColor_fromRGBA(220, 220, 220, 100), sfBlack, 3), SHAPE,
    create_data(set_3vector(10, 60, 0), set_2vector(340, 280), 0)));
    game->crowd->mob = init_crowd_mob(wd);
    game->crowd->cop = init_crowd_cop(wd);
    return true;
}
