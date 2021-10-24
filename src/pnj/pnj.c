//
// Created by Audrey Divito on 19/10/2021.
//

#include "pnj.h"

InventoryPnj* initInventoryPnj() {
    InventoryPnj* inventory = malloc(sizeof(InventoryPnj));
    inventory->idObject = 0;
    inventory->next = NULL;

    return inventory;
}

InventoryPnj* fillInventory(Item* item, Player* player, InventoryPnj *inventory) {
    if(inventory->next == NULL) {
        inventory->next = initInventoryPnj();
        inventory->next->idObject = item->value;
        // player->inventory[item->value] = 0;
    } else if(inventory->idObject == 0) {
        inventory->idObject = item->value;
        // player->inventory[item->value] = 0;
    } else {
        inventory->next = fillInventory(item, player, inventory->next);
    }

    return inventory;
}

void showInventoryContent(InventoryPnj* inventory, int id) {
    Item** itemList = createItemList();
    InventoryPnj* nextElement = malloc(sizeof(InventoryPnj));
    nextElement = inventory;
    while(nextElement != NULL) {
        printf("%d | %s | %s | %d | %d | %d | %d\n", nextElement->idObject, itemList[nextElement->idObject]->name,
               itemList[nextElement->idObject]->type, itemList[nextElement->idObject]->damage, itemList[nextElement->idObject]->durability, itemList[nextElement->idObject]->quantity,
               itemList[nextElement->idObject]->protection);
        nextElement = nextElement->next;
        id += 1;
    }
}

void menuPnj(Player* player) {
    int choice = 0;
    do {
        printf("Hello player. \nWhat do you want to do ?\n1 - Repair your stuff\n2 - Access to the inventory of the PNJ\n");
        scanf("%d", &choice);
    } while(choice < 1 || choice > 2);

    if(choice == 1) {
        repairStuff(player);
    } else if(choice == 2) {
        inventoryMenu();
    }
}

void repairStuff(Player* player) {
    Item** itemList = createItemList();
    Inventory* inventoryPlayer = getInventory(player);
    for(int i = 0; i < INVENTORY_SIZE; i++) {
        for(int j = 1; j < sizeof(itemList); j++) {
            if(inventoryPlayer->inventory_content[i]->name == itemList[j]->name) {
                inventoryPlayer->inventory_content[i]->durability = itemList[j]->durability;
            }
        }
    }
}

void inventoryMenu(InventoryPnj** inventoryPnj) {
    int choice = 0;
    do {
        printf("\nYou are in the inventory of the pnj. What do you want to do ?\n1 - Drop objects\n2 - Collect objects\n");
        scanf("%d", &choice);
    } while(choice < 1 || choice > 2);

    if(choice == 1) {
        // TODO choose the objects (id) and number check if exists and put it in pnj's inventory
        printf("Choose the object");
        showInventoryContent(inventoryPnj, 0);
    } else if(choice == 2) {
        // TODO choose the objects (id) and number check if exists and put it in player's inventory
        printf("Choose the object");
    }
}