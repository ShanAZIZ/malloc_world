/**
 * FILENAME: inventory.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 17/10/2021
 * Dernière modification : 22/10/2021
 * Par: DAILLY Armand
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "inventory.h"

inventory *initPlayerInventory(item **itemList) {
    inventory *player_inventory = malloc(sizeof(inventory));
    player_inventory->max_armor = 1;
    player_inventory->max_tool = 6;
    player_inventory->max_weapon = 3;
    player_inventory->current_armor = 0;
    player_inventory->current_weapon = 1;
    player_inventory->current_tool = 3;
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        player_inventory->inventory_content[i] = malloc(sizeof(item));
        *(player_inventory->inventory_content[i]) = (item){0, "", "", 0, 0, 0, 0};
    }
    appendItemToInventoryWhereEmpty(itemList, 1, player_inventory);
    appendItemToInventoryWhereEmpty(itemList, 2, player_inventory);
    appendItemToInventoryWhereEmpty(itemList, 3, player_inventory);
    appendItemToInventoryWhereEmpty(itemList, 4, player_inventory);
    return player_inventory;
}

void appendItemToInventoryWhereEmpty(item** itemList, int itemId, inventory *inventory) {
    item* item = getOneItem(itemList, itemId);
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (inventory->inventory_content[i]->value == 0) {
            inventory->inventory_content[i]->value = item->value;
            inventory->inventory_content[i]->name = item->name;
            inventory->inventory_content[i]->type = item->type;
            inventory->inventory_content[i]->damage = item->damage;
            inventory->inventory_content[i]->durability = item->durability;
            inventory->inventory_content[i]->quantity = item->quantity;
            inventory->inventory_content[i]->protection = item->protection;

            break;
        }
    }
}

void appendNewItemToInventory(item** itemList, item* item, inventory *player_inventory) {
    if (strcmp(item->type, "Arme") == 0) {
        if (canAppendWeapon(player_inventory)) {
            appendItemToInventoryWhereEmpty(itemList, item->value, player_inventory);
        }
    }
    if (strcmp(item->type, "Outil") == 0) {
        if (canAppendTool(player_inventory)) {
            appendItemToInventoryWhereEmpty(itemList, item->value, player_inventory);
        }
    }
    if (strcmp(item->type, "Soin") == 0) {
        appendItemToInventoryWhereEmpty(itemList, item->value, player_inventory);
    }
    if (strcmp(item->type, "Armure") == 0) {
        if (canAppendArmor(player_inventory)) {
            appendItemToInventoryWhereEmpty(itemList, item->value, player_inventory);
        }
    }
}

void appendRessourceDeCraft(item** itemList, int itemId, inventory* player_inventory){
    item* item = getOneItem(itemList, itemId);
    for(int i = 0; i < INVENTORY_SIZE ; i++) {
        if(item->value == player_inventory->inventory_content[i]->value && player_inventory->inventory_content[i]->quantity < 20) {
            player_inventory->inventory_content[i]->quantity += 1;
            break;
        }else if(player_inventory->inventory_content[i]->value == 0){
            appendItemToInventoryWhereEmpty(itemList, itemId, player_inventory);
            break;
        }
    }
}

int canAppendArmor(inventory *player_inventory) {
    if (player_inventory->max_armor > player_inventory->current_armor) {
        return 1;
    }
    return 0;
}

int canAppendTool(inventory *player_inventory) {
    if (player_inventory->max_tool > player_inventory->current_tool) {
        return 1;
    }
    return 0;
}

int canAppendWeapon(inventory *player_inventory) {
    if (player_inventory->max_weapon > player_inventory->current_weapon) {
        return 1;
    }
    return 0;
}

