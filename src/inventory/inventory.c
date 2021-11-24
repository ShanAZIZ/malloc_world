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
    Inventory *player_inventory = malloc(sizeof(Inventory));

    player_inventory->inventory_content = malloc(sizeof(Item *) * INVENTORY_SIZE);
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        player_inventory->inventory_content[i] = malloc(sizeof(Item));
        *(player_inventory->inventory_content[i]) = (Item) {0, "", "", 0, 0, 0, 0};
    }
    appendItemToInventoryWhereEmpty(itemList, 1, player_inventory);
    appendItemToInventoryWhereEmpty(itemList, 2, player_inventory);
    appendItemToInventoryWhereEmpty(itemList, 3, player_inventory);
    appendItemToInventoryWhereEmpty(itemList, 4, player_inventory);
    return player_inventory;
}

void appendItemToInventoryWhereEmpty(Item **itemList, int itemId, Inventory *inventory) {
    Item *item = getOneItem(itemList, itemId);
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

void appendRessourceDeCraft(Item **itemList, int itemId, Inventory *player_inventory) {
    Item *item = getOneItem(itemList, itemId);
    int result;
    result = 0;
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (item->value == player_inventory->inventory_content[i]->value &&
            player_inventory->inventory_content[i]->quantity < 20) {
            player_inventory->inventory_content[i]->quantity += 1;
            result = 1;
            break;
        }
    }
    if (result == 0) {
        appendItemToInventoryWhereEmpty(itemList, itemId, player_inventory);
    }
}

void appendPotion(Game* game, int idPotion){
    int result;
    result = 0;
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (idPotion == game->player->inventory->inventory_content[i]->value){
            game->player->inventory->inventory_content[i]->quantity += 1;
            result = 1;
            break;
        }
    }
    if (result == 0) {
        appendItemToInventoryWhereEmpty(game->itemList, idPotion, game->player->inventory);
    }
}

void emptyInventoryElement(Game *game, int id) {
    *game->player->inventory->inventory_content[id] = (Item) {0, "", "", 0, 0, 0, 0};
}

void displayInventory(Game *game) {
    for (int i = 0; i < INVENTORY_SIZE; i += 1) {
        if (game->player->inventory->inventory_content[i]->value != 0) {
            printf("%d | %d | %s\n", i, game->player->inventory->inventory_content[i]->quantity,
                   game->player->inventory->inventory_content[i]->name);
        }
    }
}



