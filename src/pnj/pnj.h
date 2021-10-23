//
// Created by Audrey Divito on 19/10/2021.
//

#ifndef MALLOC_WORLD_PNJ_H
#define MALLOC_WORLD_PNJ_H

#endif //MALLOC_WORLD_PNJ_H

#include <player.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct InventoryPnj {
    int idObject;   // id of the object stock in inventory of pnj
    struct InventoryPnj* next;
} InventoryPnj;

InventoryPnj* initInventoryPnj();
InventoryPnj* fillInventory(Item*, Player*, InventoryPnj*);
void showInventoryContent();
void menuPnj(Player*);
void repairStuff(Player*);
void inventoryMenu();