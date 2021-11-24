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

Inventory *initPlayerInventory(Item **itemList) {
    Inventory *playerInventory = malloc(sizeof(Inventory));

    playerInventory->inventoryContent = malloc(sizeof(Item *) * INVENTORY_SIZE);
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        playerInventory->inventoryContent[i] = malloc(sizeof(Item));
        *(playerInventory->inventoryContent[i]) = (Item) {0, "", "", 0, 0, 0, 0};
    }
    appendItemToInventoryWhereEmpty(itemList, 1, playerInventory);
    appendItemToInventoryWhereEmpty(itemList, 2, playerInventory);
    appendItemToInventoryWhereEmpty(itemList, 3, playerInventory);
    appendItemToInventoryWhereEmpty(itemList, 4, playerInventory);
    return playerInventory;
}

void appendItemToInventoryWhereEmpty(Item **itemList, int itemId, Inventory *inventory) {
    Item *item = getOneItem(itemList, itemId);
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (inventory->inventoryContent[i]->value == 0) {
            inventory->inventoryContent[i]->value = item->value;
            inventory->inventoryContent[i]->name = item->name;
            inventory->inventoryContent[i]->type = item->type;
            inventory->inventoryContent[i]->damage = item->damage;
            inventory->inventoryContent[i]->durability = item->durability;
            inventory->inventoryContent[i]->quantity = item->quantity;
            inventory->inventoryContent[i]->protection = item->protection;
            break;
        }
    }
}

void appendItemToInventoryAtIndex(Item** itemList, int itemId, int index, Inventory* inventory){
    if(itemId != 0){
        Item* item = getOneItem(itemList, itemId);
        inventory->inventoryContent[index]->value = item->value;
        inventory->inventoryContent[index]->name = item->name;
        inventory->inventoryContent[index]->type = item->type;
        inventory->inventoryContent[index]->damage = item->damage;
        inventory->inventoryContent[index]->durability = item->durability;
        inventory->inventoryContent[index]->quantity = item->quantity;
        inventory->inventoryContent[index]->protection = item->protection;
    }
    else {
        *(inventory->inventoryContent[index]) = (Item){0, "", "", 0, 0, 0, 0};
    }
}

void appendRessourceDeCraft(Item **itemList, int itemId, Inventory *playerInventory) {
    Item *item = getOneItem(itemList, itemId);
    int result;
    result = 0;
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (item->value == playerInventory->inventoryContent[i]->value &&
            playerInventory->inventoryContent[i]->quantity < 20) {
            playerInventory->inventoryContent[i]->quantity += 1;
            result = 1;
            break;
        }
    }
    if (result == 0) {
        appendItemToInventoryWhereEmpty(itemList, itemId, playerInventory);
    }
}


void appendPotion(Game* game, int idPotion){
    int result;
    result = 0;
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (idPotion == game->player->inventory->inventoryContent[i]->value){
            game->player->inventory->inventoryContent[i]->quantity += 1;
            result = 1;
            break;
        }
    }
    if (result == 0) {
        appendItemToInventoryWhereEmpty(game->itemList, idPotion, game->player->inventory);
    }
}

void showPlayerInventory(Inventory* playerInventory){
    for(int i = 0; i < INVENTORY_SIZE; i += 1) {
        if (playerInventory->inventoryContent[i]->value != 0) {
            printf("\n %d | %s | %s | %d | %d | %d | %d |",
                   playerInventory->inventoryContent[i]->value,
                   playerInventory->inventoryContent[i]->type,
                   playerInventory->inventoryContent[i]->name,
                   playerInventory->inventoryContent[i]->quantity,
                   playerInventory->inventoryContent[i]->durability,
                   playerInventory->inventoryContent[i]->damage,
                   playerInventory->inventoryContent[i]->protection
            );
        }
    }
}

void emptyInventoryElement(Game *game, int id) {
    *game->player->inventory->inventoryContent[id] = (Item) {0, "", "", 0, 0, 0, 0};
}

void displayInventory(Game *game) {
    for (int i = 0; i < INVENTORY_SIZE; i += 1) {
        if (game->player->inventory->inventoryContent[i]->value != 0) {
            printf("%d | %d | %s\n", i, game->player->inventory->inventoryContent[i]->quantity,
                   game->player->inventory->inventoryContent[i]->name);
        }
    }
}