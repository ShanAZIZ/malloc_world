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

typedef struct InventoryPnj {
    int idObject;   // id of the object stock in inventory of pnj
    int quantity; // quantity of the object stock in inventory of pnj
    struct InventoryPnj* next;
} InventoryPnj;

typedef struct Craft {
    int id;
    char* name;
    char* resources;
    unsigned short zone;
} Craft;

InventoryPnj* initInventoryPnj();
InventoryPnj* fillInventory(Item*, Player*, InventoryPnj**, int, int);
void showInventoryContent(InventoryPnj**, int);
void menuPnj(Player*, int, InventoryPnj**);
void menuCraft(int, Player*);
void repairStuff(Player*);
InventoryPnj* inventoryMenu(InventoryPnj**, Player*);
InventoryPnj* getFromInventory(Player*, InventoryPnj**, int, int);

#endif //MALLOC_WORLD_PNJ_H