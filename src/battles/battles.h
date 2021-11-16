//
// Created by Audrey Divito on 15/11/2021.
//

#ifndef MALLOC_WORLD_BATTLES_H
#define MALLOC_WORLD_BATTLES_H

#include <stdio.h>
#include <string.h>
#include "../player/player.h"

typedef struct Monster {
    char* name;
    int damage;
    int xp;
    int current_hp;
} Monster;

void initHpByLevel(Player* player);
void updateXP(Player* player, Monster* monster);
void battle(Player* player, Monster* monster, int round, int idWeapon);
int menu(Player* player, Monster monster);

#endif //MALLOC_WORLD_BATTLES_H
