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

char* split(char* str, char* delim) {
    char* ptr = strtok(str, delim);

    return ptr;
}

Craft** initCraft() {
    Craft** craft = malloc(sizeof(Craft*) * 25);

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
                            "2 Plante Zone 1", "2 plante zone 2", "2 plante zone 3"};

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
        *craft[i] = (Craft) {i, names[i], resources[i], zone[i]};
    }

    return craft;
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

void menuPnj(Player* player, int zone, InventoryPnj** inventoryPnj) {
    int choice = 0;
    do {
        printf("Bonjour joueur. \nQue voulez-vous faire ? \n1 - Réparer l'équipement \n2 - Accéder à l'inventaire du PNJ\n3 - Crafter des objets\n4 - Quitter");
        scanf("%d", &choice);
    } while(choice < 1 || choice > 4);

    if(choice == 1) {
        repairStuff(player);
    } else if(choice == 2) {
        inventoryMenu(inventoryPnj, player);
    } else if(choice == 3) {
        menuCraft(zone);
    } else {
        return;
    }
}

void menuCraft(int zone) {
    printf("Vous êtes dans le menu de craft. Voici les objets que vous pouvez créer.\n");
    Craft** craft = initCraft();
    for (int i = 1; i < 25; i++) {
        if((zone == 1 && (craft[i]->zone == 4 || craft[i]->zone == 6)) || (zone == 2 && (craft[i]->zone == 4 || craft[i]->zone == 5 || craft[i]->zone == 6)) || (zone == 3 && (craft[i]->zone == 3 || craft[i]->zone == 5 || craft[i]->zone == 6))) {
            printf("%d | %s | %s \n", craft[i]->id, craft[i]->name,
                   craft[i]->resources);
        }
    }
    printf("\nSaisissez l'id de l'objet que vous souhaitez crafter.\n");
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
                    *inventoryPnj = fillInventory(inventory->inventory_content[choice], player, *inventoryPnj, quantity, choice);
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