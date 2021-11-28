/**
 * FILENAME: save.h
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 27/10/2021
 * Dernière modification : 25/11/2021
 * Par: AZIZ Shana
 */

#ifndef MALLOC_WORLD_SAVE_H
#define MALLOC_WORLD_SAVE_H


#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "move.h"
#include "map.h"

void saveZone(FILE*, int**, int, int);
void saveMap(Game* game, FILE* saveFile);
void loadMap(Game* game, FILE* saveFile);
void loadMapZone(FILE* saveFile, int** map, int mapId, int x, int y, Player* player);
void savePlayer(FILE* saveFile, Game* game);
void saveInventory(FILE*, Inventory* inventory);
void saveStorage(FILE* playerSaveFile, Game* game);
void loadPlayer(FILE* saveFile, Game* game);
void loadPlayerInventory(FILE* playerSaveFile, Inventory* playerInventory, Item**);
void loadStorage(FILE* playerSaveFile, Game* game);
void saveGame(Game* game);
void loadGame(Game* game);
int getMapWidth(FILE* saveFile, int zone);
int getMapHeight(FILE* saveFile, int zone);

#endif