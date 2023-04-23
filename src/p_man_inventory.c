/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** p_man_inventory.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

button_s_t** init_p_man_inv_button(list_button_t** a_btn,
    layer_t* lyr)
{
    button_s_t** btns = malloc(sizeof(button_s_t*) * 2);
    btns[0] = set_button(a_btn, "\n<", set_3vector(1250, 420, 0),
        set_2vector(25, 50));
    btns[0] = append_button_layer(lyr, btns[0]);
    set_size_draw(btns[0]->name, set_2vector(0, 20));
    btns[1] = set_button(a_btn, "\n>", set_3vector(1600, 420, 0),
        set_2vector(25, 50));
    btns[1] = append_button_layer(lyr, btns[1]);
    set_size_draw(btns[1]->name, set_2vector(0, 20));
    return btns;
}

draw_t** init_weapon_sprite(layer_t* lyr)
{
    draw_t** sprite = malloc(sizeof(draw_t*) * (NB_WEAPON + 1));
    const char *tx_path[3] = {"./images/Fist.png", "./images/Batte.png",
    "./images/CodeCivil.png"};
    for (int i = 0; i < NB_WEAPON; i++) {
        sfTexture* tx = sfTexture_createFromFile(tx_path[i], NULL);
        sprite[i] = create_draw(create_sprite(tx,
        set_rectangle(0, 0, 139, 160)), SPRITE, create_data(
        set_3vector(1350, 360, 0), set_2vector(100, 100), 0));
        append_draw_layer(lyr, sprite[i]);
    }
    sprite[NB_WEAPON] = create_draw(create_shape(RECT, sfWhite, sfRed, 5), SHAPE,
    create_data(set_3vector(1320, 330, 0), set_2vector(200, 250), 0));
    append_draw_layer(lyr, sprite[NB_WEAPON]);
    return sprite;
}

draw_t** init_p_man_inv_descriptions(layer_t* lyr)
{
    draw_t** desc = malloc(sizeof(draw_t*) * (NB_WEAPON * 2));
    char *title[NB_WEAPON] = {"TES POINGS DE FORAINS", "LA BATTE DE TA MAMIE",
        "CODE CIVIL"};
    char *name[NB_WEAPON] = {"LE CAC MON GARS !\nPortee: courtenDegats bonus: "
    "+0\nRecharge: courte", "ELLE T'AS DEMANDE D'EN PRENDRE SOIN !\nPortee: lon"
    "gue\nDegats bonus: +5\nRecharge: longue", "L'ARME DES GROS CERVEAUX !\nPor"
    "tee: longue\nDegat bonus: pas de degat\nRecharge: moyenne\nRepousse: haute"
    };
    for (int i = 0; i < NB_WEAPON; i++) {
        desc[i] = create_draw(create_text(title[i], NULL, sfBlack), TEXT,
        create_data(set_3vector(1100, 250, 0), set_2vector(0, 40), 0));
        set_thick_draw(desc[i], 1);
        append_draw_layer(lyr, desc[i]);
    } for (int i = NB_WEAPON; i < NB_WEAPON * 2; i++) {
        desc[i] = create_draw(create_text(name[i - NB_WEAPON], NULL, sfBlack),
        TEXT, create_data(set_3vector(1150, 600, 0), set_2vector(0, 25), 0));
        set_thick_draw(desc[i], 1);
        append_draw_layer(lyr, desc[i]);
    }
    return desc;
}

interface_t* init_p_man_inventory(layer_t* lyr, list_button_t** a_btn)
{
    interface_t* inv_ui = malloc(sizeof(interface_t));
    inv_ui->stat_name = init_p_man_inv_descriptions(lyr);
    inv_ui->stat_btns = init_p_man_inv_button(a_btn, lyr);
    inv_ui->stat_nb = init_weapon_sprite(lyr);
    return inv_ui;
}
