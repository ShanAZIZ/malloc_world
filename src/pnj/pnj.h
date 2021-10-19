//
// Created by Audrey Divito on 19/10/2021.
//

#ifndef MALLOC_WORLD_PNJ_H
#define MALLOC_WORLD_PNJ_H

#endif //MALLOC_WORLD_PNJ_H

#include <player.h>
#include <stdlib.h>
#include <stdio.h>
#include "../items/items.h"

typedef struct InventoryPnj InventoryPnj;
struct InventoryPnj {
    int idObject;   // id of the object stock in inventory of pnj
    InventoryPnj* next;
};

InventoryPnj* initInventoryPnj();
InventoryPnj* fillInventory(item*, Player*, InventoryPnj*);
void showInventoryContent();