/**
 * FILENAME: monsters.h
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 17/10/2021
 * Dernière modification : 17/10/2021
 * Par: DAILLY Armand
**/

#ifndef MALLOC_WORLD_MONSTERS_H
#define MALLOC_WORLD_MONSTERS_H

#include "../include/structures.h"

Monster** createMonsterList(void);
Monster* getOneMonster(Monster **monsterList, int monsterId);

#endif //MALLOC_WORLD_MONSTERS_H
