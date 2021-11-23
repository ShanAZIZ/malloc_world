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
    inventory->quantity = 0;
    inventory->next = NULL;

    return inventory;
}

Craft** initCraft() {
    Craft** craft = malloc(sizeof(Craft*) * 25);

    unsigned short id[25] = {1, 8, 19, 30,
                             9, 20, 31,
                             10, 21, 32,
                             11, 22, 33,
                             2, 12, 23,
                             4, 14, 25,
                             3, 13, 24,
                             15, 26, 34};

    char* names[25] = {"Epee en bois", "Epee en pierre", "Epee en fer", "Epee en diamant",
                       "Lance en pierre", "Lance en fer", "Lance en diamant",
                       "Marteau en pierre", "Marteau en fer", "Marteau en diamant",
                       "Plastron en pierre", "Plastron en fer", "Plastron en diamant",
                       "Pioche en bois", "Pioche en pierre", "Pioche en fer",
                       "Hache en bois", "Hache en pierre", "Hache en fer",
                       "Serpe en bois", "Serpe en pierre", "Serpe en fer",
                       "Potion de vie I", "Potion de vie II", "Potion de vie III"};

    char* resources[25] = {"3 Sapin", "2 Sapin - 3 Pierre", "2 Hetre - 4 Fer", "2 Chene - 5 Fer",
                           "3 Sapin - 4 Pierre", "3 Hetre - 5 Fer", "3 Chene - 6 Diamant",
                           "2 Sapin - 6 Pierre", "2 Hetre - 7 Fer", "2 Chene - 8 Diamant",
                           "10 Pierre", "12 Fer", "16 Diamant",
                           "3 Sapin", "2 Sapin - 3 Pierre", "2 Hetre - 4 Fer",
                           "3 Sapin", "2 Sapin - 3 Pierre", "2 Hetre - 4 Fer",
                           "3 Sapin", "2 Sapin - 3 Pierre", "2 Hetre - 4 Fer",
                           "2 Herbe", "2 Lavande", "2 Chanvre"};

    // 1 -> zone 1, 2 -> zone 2, 3 -> zone 3, 4 -> zones 1 et 2, 5 -> zone 2 et 3, 6 -> zone 1 et 2 et 3
    unsigned short zone[25] = {6, 6, 5, 3,
                               6, 5, 3,
                               6, 5, 3,
                               6, 5, 3,
                               6, 6, 5,
                               6, 6, 5,
                               6, 6, 5,
                               6, 5, 3};

    for (int i = 0; i < 25; i++) {
        craft[i] = malloc(sizeof(Item));
        *craft[i] = (Craft) {id[i], names[i], resources[i], zone[i]};
    }

    return craft;
}

InventoryPnj* fillInventory(Player* player, InventoryPnj* inventory, int quantity, int idObject) {
    if(inventory->next == NULL) {
        inventory->next = initInventoryPnj();
        inventory->next->idObject = idObject;
        inventory->next->quantity += quantity;
        if(player->inventory->inventory_content[idObject]->quantity > 0){
            player->inventory->inventory_content[idObject]->quantity -= quantity;
        }
    } else if(inventory->idObject == 0) {
        inventory->idObject = idObject;
        inventory->quantity += quantity;
        if(player->inventory->inventory_content[idObject]->quantity > 0){
            player->inventory->inventory_content[idObject]->quantity -= quantity;
        }
    } else {
        inventory->next = fillInventory(player, inventory->next, quantity, idObject);
    }

    return inventory;
}

void showInventoryContent(InventoryPnj* inventory, int id) {
    Item** itemList = createItemList();
    InventoryPnj* nextElement = inventory;

    if(inventory->idObject == 0) {
        printf("L'inventaire du PNJ est vide.");
        return;
    }

    while(nextElement != NULL) {
        printf("%d | %s | %s | %d | %d | %d | %d\n", nextElement->idObject, itemList[nextElement->idObject]->name,
               itemList[nextElement->idObject]->type, itemList[nextElement->idObject]->damage,
               itemList[nextElement->idObject]->durability, itemList[nextElement->idObject]->quantity,
               itemList[nextElement->idObject]->protection);
        nextElement = nextElement->next;
        id += 1;
    }
}

void menuPnj(Player* player, int zone, InventoryPnj** inventoryPnj) {
    int choice = 0;
    int res = 0;
    do {
        printf("Bonjour joueur. \nQue voulez-vous faire ? \n1 - Réparer l'équipement \n2 - Accéder à l'inventaire du PNJ\n3 - Crafter des objets\n4 - Quitter\n");
        scanf("%d", &choice);
    } while(choice < 1 || choice > 4);

    if(choice == 1) {
        repairStuff(player);
    } else if(choice == 2) {
        inventoryMenu(inventoryPnj, player);
    } else if(choice == 3) {
        res = menuCraft(zone, player);
    } else {
        return;
    }

    if(res == 1) {
        return;
    }
}

int menuCraft(int zone, Player* player) {
    printf("Vous êtes dans le menu de craft. Voici les objets que vous pouvez créer.\n");
    Craft** craft = initCraft();
    for (int i = 0; i < 24; i++) {
        if((zone == 1 && (craft[i]->zone == 4 || craft[i]->zone == 6)) || (zone == 2 && (craft[i]->zone == 4 || craft[i]->zone == 5 || craft[i]->zone == 6)) || (zone == 3 && (craft[i]->zone == 3 || craft[i]->zone == 5 || craft[i]->zone == 6))) {
            printf("%d | %s | %s \n", craft[i]->id, craft[i]->name,
                   craft[i]->resources);
        }
    }

    int choice = 0;
    do {
        printf("Tapez l'id de l'objet que vous souhaitez créer.\n");
        choice = scanf("%d", &choice);
    } while (choice < 0 || choice > 25);

    // new function craft()
    int nbResource1 = 0;
    int nbResource2 = 0;
    char* resource1 = malloc(sizeof(char) * (sizeof(craft[choice]->resources) / 2));
    char* resource2 = malloc(sizeof(char) * (sizeof(craft[choice]->resources) / 2));
    sscanf(craft[choice]->resources, "%d %[^-] - %d %[^-]", &nbResource1, resource1, &nbResource2, resource2);
    Item** itemList = createItemList();

    for(int i = 0; i < sizeof(player->inventory->inventory_content); i++) {
        if(player->inventory->inventory_content[i]->name == resource1 && player->inventory->inventory_content[i]->quantity >= nbResource1) {
            for(int j = 0; j < sizeof(player->inventory->inventory_content); j++) {
                if(player->inventory->inventory_content[j]->name == resource2 && player->inventory->inventory_content[j]->quantity >= nbResource2) {
                    appendItemToInventoryWhereEmpty(itemList, choice, player->inventory);
                    printf("L'objet a bien été créé.");
                } else {
                    player->inventory->inventory_content[i]->quantity -= nbResource1;
                }
            }
        }
    }
    return 0;
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
                    *inventoryPnj = fillInventory(player, *inventoryPnj, quantity, choice);
                    return *inventoryPnj;
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
                    return *inventoryPnj;
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