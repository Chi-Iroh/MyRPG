/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** init_player.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

const int CHARACTERS_MAX_BASE_STATS[CHARACTER_MAX][5] = {
    [CHARACTER_RAILWAY_WORKER] = {3,20, 12, 6, 0},
    [CHARACTER_DOCTOR] = {-1, 50, 8, 4, 4},
    [CHARACTER_ART_STUDENT] = {3, 20, 10, 2, 6},
    [CHARACTER_POLITICS_STUDENT] = {1, 21, 10, 12, 0},
    [CHARACTER_PREFECT_SON] = {5, 25, 5, 12, 0},
    [CHARACTER_WORKER] = {5, 25, 5, 5, 5},
    [CHARACTER_TROUBLEMAKER] = {12, 10, 10, 1, 0},
};

void init_stat(stat_t *stat, stat_t* base, character_type_t type)
{
    *base = (stat_t) {
        .damage = CHARACTERS_MAX_BASE_STATS[type][0],
        .defense = CHARACTERS_MAX_BASE_STATS[type][1],
        .speed = CHARACTERS_MAX_BASE_STATS[type][2],
        .hp = CHARACTERS_MAX_BASE_STATS[type][3],
        .level = 1,
        .exp_point = CHARACTERS_MAX_BASE_STATS[type][4],
    };
    *stat = (stat_t) {
        .damage = base->damage,
        .defense = base->defense,
        .speed = base->speed,
        .hp = base->hp,
        .level = base->level,
        .exp_point = base->exp_point,
    };
}

sfTexture *init_player_text(character_type_t type)
{
    char buff[256] = "images/spritesheets/";
    switch (type) {
        case CHARACTER_RAILWAY_WORKER:
            mystrcat(buff,"cheminot_spritesheet"); break;
        case CHARACTER_DOCTOR :
            mystrcat(buff, "docteur_spritesheet"); break;
        case CHARACTER_ART_STUDENT :
            mystrcat(buff,"étudiant_en_arts_spritesheet"); break;
        case CHARACTER_POLITICS_STUDENT :
            mystrcat(buff,"étudiant_sciences_po_spritesheet"); break;
        case CHARACTER_PREFECT_SON :
            mystrcat(buff, "fils_du_préfet_spritesheet"); break;
        case CHARACTER_WORKER :
            mystrcat(buff, "ouvrier_spritesheet"); break;
        case CHARACTER_TROUBLEMAKER :
            mystrcat(buff, "casseur_spritesheet"); break;
        default: break;
    } mystrcat(buff, ".png");
    sfTexture* text = sfTexture_createFromFile(buff, NULL);
    return text;
}

void init_bar(player_t *player, window_t* wd)
{
    data_t *data_hp = create_data(set_3vector(70, 15, 50),
    set_2vector(250, 35), 0.f);
    shape_t *shape_hp = create_shape(RECT, sfGreen, sfBlack, 3);
    init_progress_bar(wd, &player->hp, data_hp, shape_hp);
    data_t *data_exp = create_data(set_3vector(450, 15, 50),
    set_2vector(0, 35), 0.f);
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
    append_draw_layer(wd->ui, player->hp.fill);
    append_draw_layer(wd->ui, player->exp.fill);
}

void init_hitbox(player_t *player, window_t *wd, data_t *data)
{
    data_t *data_r = create_data(data->position, set_2vector(150, 80), 0.f);
    shape_t *shape_r = create_shape(RECT, sfTransparent, sfBlack, 1);
    player->range = create_draw(shape_r, SHAPE, data_r);
    set_origin_draw(player->range, set_2vector
    (data_r->size.x / 2, data_r->size.y / 2));
    append_draw_layer(wd->core, player->range);
    data_t *data_tmp = create_data(set_3vector(50, 990, 0), set_2vector(160, -160),
    0);
    shape_t *shape = create_shape(RECT,
    sfColor_fromRGBA(200, 200, 200, 150), sfTransparent, 1);
    player->cooldown = create_draw(shape, SHAPE, data_tmp);
    data_t *fst = create_data(set_3vector(55, 830, 0), set_2vector(160, -160),
    0);
    sprite_t *sprite = init_sprite();
    sfTexture *texture = sfTexture_createFromFile ("images/Fist.png", NULL);
    set_texture_sprite(sprite, texture, (sfIntRect) {0, 0, 139, 160});
    draw_t *fist = create_draw(sprite, SPRITE, fst);
    append_draw_layer(wd->ui, fist);
    append_draw_layer(wd->ui, player->cooldown);
}

player_t *init_player(window_t* wd, game_t *game)
{
    player_t *player = malloc(sizeof(player_t));
    player->type = select_character();
    if (player->type == CHARACTER_NONE || player->type == CHARACTER_ERROR) {
        free(player);
        return NULL;
    }
    player->clock = sfClock_create();
    data_t *data = create_data(set_3vector(WD_WIDTH / 2 + 400,
    WD_HEIGHT / 2 + 400, 0), set_2vector(48, 72), 0.f);
    sprite_t *sprite = init_sprite();
    sfTexture *texture = init_player_text(player->type);
    set_texture_sprite(sprite, texture, (sfIntRect) {0, 0, 48, 72});
    player->draw = create_draw(sprite, SPRITE, data);
    set_origin_draw(player->draw, set_2vector
    (data->size.x / 2, data->size.y - 5));
    append_draw_layer(wd->core, player->draw);
    init_bar(player, wd);
    init_hitbox(player, wd, data);
    init_stat(&player->stat, &player->base, player->type);
    return player;
}
