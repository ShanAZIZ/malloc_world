/**
 * FILENAME: monsters.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 10/11/2021
 * Dernière modification : 24/11/2021
 * Par: DAILLY Armand
**/
#include "structures.h"
#include "inventory.h"
#include <string.h>

#ifndef MALLOC_WORLD_PNJ_H
#define MALLOC_WORLD_PNJ_H


void repairStuff(Game *game);

Storage *initStorage();

Craft **initCraft();

void displayCraft(Game *game);

void displayPnjStorage(Game *game);

void addToStorage(Game *game, int itemId, int quantity);

Storage *newElementStorage(int itemId, int quantity);

void deleteFromStorage(Game *game, int itemId);

void addToInventory(Game *game, int itemId, int quantity);

void retrieveFromStorage(Game *game, int itemId, int quantity);

void storageMenu(Game *game);

void menuCraft(Game *game);

void menuPnj(Game *game);

#endif //MALLOC_WORLD_PNJ_H
