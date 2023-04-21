/*
** EPITECH PROJECT, 2022
** My_rpg_tmp
** File description:
** rand.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

sfTexture* rand_skin(void)
{
    char buff[256] = "images/spritesheets/";
    switch (rand() % 7) {
        case 0: mystrcat(buff,"cheminot_spritesheet"); break;
        case 1: mystrcat(buff,"étudiant_en_arts_spritesheet"); break;
        case 2: mystrcat(buff,"étudiant_sciences_po_spritesheet"); break;
        case 3: mystrcat(buff, "fils_du_préfet_spritesheet"); break;
        case 4: mystrcat(buff, "ouvrier_spritesheet"); break;
        case 5: mystrcat(buff, "casseur_spritesheet"); break;
        case 6: mystrcat(buff, "docteur_spritesheet"); break;
    }
    mystrcat(buff, ".png");
    sfTexture* text = sfTexture_createFromFile(buff, NULL);
    return text;
}

sfVector2f get_random_position(window_t *wd)
{
    sfVector2f position;
    position.x = (float)(rand() % ((int)wd->map_size.x));
    position.y = (float)(rand() % ((int)wd->map_size.y));
    return position;
}
