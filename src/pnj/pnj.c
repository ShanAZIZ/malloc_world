//
// Created by Audrey Divito on 19/10/2021.
//

#include "pnj.h"

InventoryPnj* initInventoryPnj() {
    InventoryPnj* inventory = malloc(sizeof(*inventory) * 100);
    inventory->idObject = 0;
    inventory->next = NULL;

    return inventory;
}

InventoryPnj* fillInventory(item* item, Player* player, InventoryPnj *inventory) {
    if(inventory->idObject == 0) {
        inventory->idObject = item->value;
        player->inventory[item->value] = 0;
    } else if(inventory->next == NULL) {
        inventory->next = initInventoryPnj();
        inventory->next->idObject = item->value;
        player->inventory[item->value] = 0;
    } else {
        inventory->next = fillInventory(item, player, inventory->next);
    }

    return inventory;
}

void showInventoryContent(InventoryPnj* inventory, int id) {
    item** itemList = createItemList();

    while(inventory->idObject != 0) {
        printf("%p | %d | %s | %s | %d | %d | %d | %d\n", &inventory[id], inventory[id].idObject, itemList[inventory[id].idObject]->name,
               itemList[inventory[id].idObject]->type, itemList[inventory[id].idObject]->damage, itemList[inventory[id].idObject]->durability, itemList[inventory[id].idObject]->quantity,
               itemList[inventory[id].idObject]->protection);
        showInventoryContent(inventory->next, id ++);
    }
}