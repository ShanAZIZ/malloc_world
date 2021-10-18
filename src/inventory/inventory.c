#include <stdlib.h>
#include <stdio.h>
#include <items.h>
#include "string.h"
#include "inventory.h"

inventory* initPlayerInventory(item** item_list){
    inventory* player_inventory = malloc(sizeof(inventory));
    player_inventory->max_armor = 1;
    player_inventory->max_tool = 6;
    player_inventory->max_weapon = 3;
    player_inventory->current_armor = 0;
    player_inventory->current_weapon = 1;
    player_inventory->current_tool = 3;
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        player_inventory->inventory_content[i] = malloc(sizeof(item*));
    }
    player_inventory->inventory_content[0] = item_list[1];
    player_inventory->inventory_content[1] = item_list[2];
    player_inventory->inventory_content[2] = item_list[3];
    player_inventory->inventory_content[3] = item_list[4];
    return player_inventory;
};

void appendItemToInventoryWhereEmpty(item* item, inventory* inventory){
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if(inventory->inventory_content[i] == NULL){
            inventory->inventory_content[i] = item;
            break;
        }
    }
}

void appendNewItemToInventory(item* item, inventory* player_inventory){
    if(strcmp(item->type, "Arme") == 0){
        if(canAppendWeapon(player_inventory)){
            appendItemToInventoryWhereEmpty(item, player_inventory);
        }
    }
    if(strcmp(item->type, "Outil") == 0){
        if(canAppendTool(player_inventory)){
            appendItemToInventoryWhereEmpty(item, player_inventory);
        }
    }
    if(strcmp(item->type, "Ressource de craft") == 0){

    }
    if(strcmp(item->type, "Soin") == 0){
        appendItemToInventoryWhereEmpty(item, player_inventory);
    }
    if(strcmp(item->type, "Armure") == 0){
        if(canAppendArmor(player_inventory)){
            appendItemToInventoryWhereEmpty(item, player_inventory);
        }
    }
}

//void appendRessourceDuCraft(item* item, inventory* player_inventory){
//    int already_stacked = 0;
//    for(int i = 0; i < INVENTORY_SIZE ; i++) {
//        if(item->value == player_inventory->inventory_content[i]->value) {
//            if (player_inventory->inventory_content[i]->quantity < 20) {
//                player_inventory->inventory_content[i]->quantity += 1;
//                already_stacked = 1;
//            }
//        }
//    }
//    if(already_stacked == 0) {
//    }
//}

int canAppendArmor(inventory* player_inventory){
    if(player_inventory->max_armor > player_inventory->current_armor){
        return 1;
    }
    return 0;
}

int canAppendTool(inventory* player_inventory){
    if(player_inventory->max_tool > player_inventory->current_tool){
        return 1;
    }
    return 0;
}

int canAppendWeapon(inventory* player_inventory){
    if(player_inventory->max_weapon > player_inventory->current_weapon){
        return 1;
    }
    return 0;
}

