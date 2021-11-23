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

#define INVENTORY_SIZE 10



Inventory* initPlayerInventory(Item** item_list);
void appendItemToInventoryWhereEmpty(Item** itemList, int itemId, Inventory *inventory);
void appendItemToInventoryAtIndex(Item** itemList, int itemId, int index, Inventory* inventory);
void appendRessourceDeCraft(Item** itemList, int itemId, Inventory* player_inventory);

#endif