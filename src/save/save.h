/**
 * FILENAME: save.h
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 27/10/2021
 * Dernière modification : 27/10/2021
 * Par: AZIZ Shana
 */


#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "move.h"
#include "map.h"

#ifndef MALLOC_WORLD_SAVE_H
#define MALLOC_WORLD_SAVE_H

#endif

struct storage {
    Item* item;
    struct storage* next;
};
typedef struct storage storage;

storage* initTempStorage(Item**);
void saveZone(FILE*, int**, int, int);
void saveMap(Game* game, FILE* save_file);
void loadMap(Game* game, FILE* save_file);
void loadMapZone(FILE* save_file, int** map, int mapId, int x, int y, Player* player);
void savePlayer(FILE* save_file, Player* player, storage* storage);
void saveInventory(FILE*, Inventory* inventory);
void saveStorage(FILE* player_save_file, storage* storage);
void loadPlayer(FILE* save_file, Player* player, Item**, storage*);
void loadPlayerInventory(FILE* player_save_file, Inventory* player_inventory, Item**);
void loadStorage(FILE* player_save_file, storage* storage1, Item** item_list);
void appendToStorage(storage* storage1, Item* item);
void saveGame(Game* game, storage* storage);
void loadGame(Game* game, storage* storage);
storage* initEmptyStorage();
