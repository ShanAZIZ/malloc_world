/**
 * FILENAME: monsters.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 17/10/2021
 * Dernière modification : 17/10/2021
 * Par: DAILLY Armand
**/

#include <stdlib.h>
#include <stdio.h>
#include "monsters.h"

Monster **createMonsterList(void) {
    Monster **monsterList = malloc(sizeof(Monster *) * 99);
    for (int i = 0; i < 12; i++) {
        monsterList[i] = malloc(sizeof(Monster));
        monsterList[i] = NULL;
    }
    char *names[34] = {"Sanglier", "Pioche en bois", "Serpe en bois", "Hache en bois", "Sapin", "Pierre",
                       "Herbe", "Epee en pierre", "Lance en pierre", "Marteau en pierre", "Plastron en pierre",
                       "Pioche en pierre", "Serpe en pierre", "Hache en pierre", "Potion de vie I", "Hetre", "Fer",
                       "Lavande", "Epee en fer", "Lance en fer", "Marteau en fer", "Plastron en fer",
                       "Pioche en fer", "Serpe en fer", "Hache en fer", "Potion de vie II", "Chene", "Diamant",
                       "Chanvre", "Epee en diamant", "Lance en diamant", "Marteau en diamant", "Plastron en diamant",
                       "Potion de vie III"};
    unsigned short hp[34] = {1, 0, 0, 0, 0, 0, 0, 2, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 5, 7, 10, 0, 0, 0, 0, 0, 0, 0, 0, 10,
                             15, 20, 0, 0};
    unsigned short att[34] = {10, 10, 10, 10, 1, 1, 1, 10, 8, 5, 1, 10, 10, 10, 1, 1, 1, 1, 10, 8, 5, 1, 10, 10, 10, 1,
                              1, 1, 1, 10, 8, 5, 1, 1};
    unsigned short def[34] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 40, 0};
    unsigned short xp[34] = {10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 40, 0};
    for (int i = 12; i < 47; i++) {
        monsterList[i] = malloc(sizeof(Monster));
        *monsterList[i] = (Monster) {i, names[i - 12], hp[i - 12], att[i - 12], def[i - 12], xp[i - 12]};
    }
    return monsterList;
}

Monster getOneMonster(Monster **monsterList, int monsterId) {
    return monsterList[monsterId];
}