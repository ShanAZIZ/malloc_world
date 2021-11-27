/**
 * FILENAME: monsters.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 17/10/2021
 * Dernière modification : 17/11/2021
 * Par: DAILLY Armand
**/

#include <stdlib.h>
#include <stdio.h>
#include "monsters.h"

Monster **createMonsterList(void) {
    Monster **monsterList = malloc(sizeof(Monster *) * 100);
    for (int i = 0; i < 12; i++) {
        monsterList[i] = malloc(sizeof(Monster));
        monsterList[i] = NULL;
    }
    char *names[10] = {"Sanglier", "Slime", "Emmanuel Macron", "Petit ours brun", "Sananes", "Caribou", "Pomme de terre vivante", "Flan", "Ancien dragon", "Jesus"};
    unsigned short hp[10] = {10, 5, 12, 16, 70, 25, 7, 2, 60, 80};
    unsigned short att[10] = {5, 1, 4, 8, 60, 15, 3, 3, 35, 50};
    unsigned short def[10] = {1, 0, 3, 6, 40, 15, 1, 2, 40, 20};
    unsigned short xp[10] = {5, 4, 8, 9, 50, 15, 20, 22, 60, 60};

    for (int i = 12; i < 21; i++) {
        monsterList[i] = malloc(sizeof(Monster));
        *monsterList[i] = (Monster) {i, names[i - 12], hp[i - 12], att[i - 12], def[i - 12], xp[i - 12]};
    }
    monsterList[99] = malloc(sizeof(Monster));
    *monsterList[99] = (Monster) {99, names[9], hp[9], att[9], def[9], xp[9]};

    return monsterList;
}

Monster* getOneMonster(Monster **monsterList, int monsterId) {
    return monsterList[monsterId];
}