/**
 * FILENAME: pnj.h
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 19/10/2021
 * Dernière modification : 25/10/2021
 * Par: DI VITO Audrey
 */

#ifndef MALLOC_WORLD_PNJ_H
#define MALLOC_WORLD_PNJ_H

#include "../player/player.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// use function appendItemToInventoryWhereEmpty of inventory.h
// put id of the itemList

typedef struct InventoryPnj {
    int idObject;   // id of the object stock in inventory of pnj
    int quantity; // quantity of the object stock in inventory of pnj
    struct InventoryPnj* next;
} InventoryPnj;

typedef struct Craft {
    unsigned short id;
    char* name;
    char* resources;
    unsigned short zone;
} Craft;

InventoryPnj* initInventoryPnj();
InventoryPnj* fillInventory(Player*, InventoryPnj*, int, int);
int showInventoryContent(InventoryPnj*, int);
void menuPnj(Player*, int, InventoryPnj**);
int menuCraft(int, Player*);
void repairStuff(Player*);
InventoryPnj* inventoryMenu(InventoryPnj**, Player*);
InventoryPnj* getFromInventory(Player*, InventoryPnj*, int, int);

#endif //MALLOC_WORLD_PNJ_H