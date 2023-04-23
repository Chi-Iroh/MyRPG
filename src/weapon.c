/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** weapon.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

void update_weapon_ui(weapon_t** all_weapons, weapon_t* current,
    interface_t* inv_ui)
{
    int slct = 0;
    for (; all_weapons[slct] != current; slct++) {
    }
    for (int i = 0; i < NB_WEAPON; i++) {
        inv_ui->stat_nb[i]->show = i == slct ? true : false;
        inv_ui->stat_name[i]->show = i == slct ? true : false;
        inv_ui->stat_name[i + NB_WEAPON]->show = i == slct ? true : false;
    }
}

weapon_t* select_weapon(weapon_t** all_weapons, weapon_t* current, int dir)
{
    int slct = 0;
    for (; all_weapons[slct] != current; slct++) {
    }
    slct += dir;
    if (slct < 0)
        slct = NB_WEAPON - 1;
    if (slct == NB_WEAPON)
        slct = 0;
    return all_weapons[slct];
}

weapon_t** init_all_weapons(void)
{
    weapon_t** all_weapons = malloc(sizeof(weapon_t) * NB_WEAPON);
    for (int i = 0; i < NB_WEAPON; i++)
        all_weapons[i] = malloc(sizeof(weapon_t));
    *all_weapons[0] = (weapon_t) {.cooldown = 0.4, .dmg = 0, .knockback = 40,
.size_hitbox = set_2vector(50, 50)};
    *all_weapons[1] = (weapon_t) {.cooldown = 0.8, .dmg = 5, .knockback = 40,
.size_hitbox = set_2vector(50, 100)};
    *all_weapons[2] = (weapon_t) {.cooldown = 0.6, .dmg = , .knockback = 150,
.size_hitbox = set_2vector(150, 100)};
    return all_weapons;
}
