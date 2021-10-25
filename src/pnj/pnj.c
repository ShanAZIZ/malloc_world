/**
 * FILENAME: pnj.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 19/10/2021
 * Dernière modification : 25/10/2021
 * Par: DI VITO Audrey
 */

#include "pnj.h"

InventoryPnj* initInventoryPnj() {
    InventoryPnj* inventory = malloc(sizeof(InventoryPnj));
    inventory->idObject = 0;
    inventory->next = NULL;

    return inventory;
}

InventoryPnj* fillInventory(Item* item, Player* player, InventoryPnj* inventory, int quantity, int idObject) {
    if(inventory->next == NULL) {
        inventory->next = initInventoryPnj();
        inventory->next->idObject = item->value;
        inventory->next->quantity += quantity;
        player->inventory[idObject].inventory_content[idObject]->quantity -= quantity;
    } else if(inventory->idObject == 0) {
        inventory->idObject = item->value;
        inventory->quantity += quantity;
        player->inventory[idObject].inventory_content[idObject]->quantity -= quantity;
    } else {
        inventory->next = fillInventory(item, player, inventory->next, quantity, idObject);
    }

    return inventory;
}

void showInventoryContent(InventoryPnj* inventory, int id) {
    Item** itemList = createItemList();
    InventoryPnj* nextElement = inventory;
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
        printf("Bonjour joueur. \nQue voulez-vous faire ? \n1 - Réparer l'équipement \n2 - Accéder à l'inventaire du PNJ\n");
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

InventoryPnj* inventoryMenu(InventoryPnj** inventoryPnj, Player* player) {
    int choice = 0;
    do {
        printf("\nVous êtes dans l'inventaire du PNJ. Que voulez-vous faire ?\n1 - Déposer des objets\n2 - Récupérer des objets\n");
        scanf("%d", &choice);
    } while(choice < 1 || choice > 2);

    if(choice == 1) {
        choice = 0;
        printf("Voici l'inventaire du PNJ :\n");
        showInventoryContent(*inventoryPnj, 0);
        while(1) {
            printf("\nTapez l'id de l'objet que vous souhaitez déposer.\n");
            scanf("%d", &choice);

            Inventory* inventory = getInventory(player);
            if(inventory->inventory_content[choice]) {
                continue;
            } else {
                int quantity = 0;
                scanf("%d", &quantity);
                if(inventory->inventory_content[choice]->quantity <= 0) {
                    continue;
                } else {
                    inventoryPnj = fillInventory(inventory->inventory_content[choice], player, *inventoryPnj, quantity, choice);
                    return inventoryPnj;
                }
            }
        }

    } else if(choice == 2) {
        choice = 0;
        printf("Voici l'inventaire du joueur :\n");
        showInventoryContent(*inventoryPnj, 0);
        while(1) {
            printf("\nTapez l'id de l'objet que vous souhaitez déposer.\n");
            scanf("%d", &choice);

            Inventory* inventory = getInventory(player);
            if(inventory->inventory_content[choice]) {
                continue;
            } else {
                int quantity = 0;
                scanf("%d", &quantity);
                if(inventory->inventory_content[choice]->quantity <= 0) {
                    continue;
                } else {
                    *inventoryPnj = getFromInventory(player, *inventoryPnj, quantity, choice);
                    return inventoryPnj;
                }
            }
        }
    }

    return NULL;
}

InventoryPnj* getFromInventory(Player* player, InventoryPnj* inventory, int quantity, int idObject) {
    for(int i = 0; i < sizeof(*inventory); i++) {
        if(inventory[i].idObject == idObject) {
            player->inventory->inventory_content[i]->quantity += quantity;
            inventory[i].quantity -= quantity;
        }
    }

    return inventory;
}