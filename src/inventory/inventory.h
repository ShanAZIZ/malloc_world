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

typedef struct Inventory {
    Item** inventory_content;
    int max_weapon;
    int max_tool;
    int max_armor;
    int current_weapon;
    int current_tool;
    int current_armor;
} Inventory;

Inventory* initPlayerInventory(Item** item_list);
void appendItemToInventoryWhereEmpty(Item** itemList, int itemId, Inventory *inventory);
void appendNewItemToInventory(Item** itemList, Item* item, Inventory* player_inventory);
void appendRessourceDeCraft(Item** itemList, int itemId, Inventory* player_inventory);
int canAppendArmor(Inventory* player_inventory);
int canAppendTool(Inventory* player_inventory);
int canAppendWeapon(Inventory* player_inventory);

#endif