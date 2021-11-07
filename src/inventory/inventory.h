/**
 * FILENAME: inventory.h
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 17/10/2021
 * Dernière modification : 22/10/2021
 * Par: DAILLY Armand
 */
#include "../items/items.h"
#ifndef MALLOC_WORLD_INVENTORY_H
#define MALLOC_WORLD_INVENTORY_H
#endif

#define INVENTORY_SIZE 10

typedef struct Inventory {
    item** inventory_content;
} inventory;

inventory* initPlayerInventory(item** item_list);
void appendItemToInventoryWhereEmpty(item** itemList, int itemId, inventory *inventory);
void appendRessourceDeCraft(item** itemList, int itemId, inventory* player_inventory);
