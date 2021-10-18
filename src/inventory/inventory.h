#include "items.h"
#ifndef MALLOC_WORLD_INVENTORY_H
#define MALLOC_WORLD_INVENTORY_H
#endif

#define INVENTORY_SIZE 10

/**
 * TODO: Les ressources du craft peuvent s'empiler
 */
typedef struct Inventory {
    item** inventory_content;
    int max_weapon;
    int max_tool;
    int max_armor;
    int current_weapon;
    int current_tool;
    int current_armor;
} inventory;

inventory* initPlayerInventory(item** item_list);
void appendItemToInventoryWhereEmpty(item* item, inventory* inventory);
void appendNewItemToInventory(item* item, inventory* player_inventory);
int canAppendArmor(inventory* player_inventory);
int canAppendTool(inventory* player_inventory);
int canAppendWeapon(inventory* player_inventory);

