//
// Created by arman on 24/11/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "pnj.h"

void repairStuff(Game *game) {
    for (int i = 0; i < INVENTORY_SIZE; i += 1) {
        if (game->player->inventory->inventory_content[i]->value != 0) {
            game->player->inventory->inventory_content[i]->durability = game->itemList[game->player->inventory->inventory_content[i]->value]->durability;
        }
    }
}

Storage *initStorage() {
    Storage *storage = malloc(sizeof(Storage));
    *storage = (Storage) {0, 0, NULL};
    return storage;
}

Craft **initCraft() {
    Craft **craft = malloc(sizeof(Craft *) * 25);

    unsigned short itemId[25] = {1, 8, 19, 30, 9, 20, 31, 10, 21, 32, 11, 22, 33, 2, 12, 23, 4, 14, 25, 3, 13, 24, 15,
                                 26, 34};

    unsigned short idResource1[25] = {5, 5, 16, 27, 5, 16, 27, 5, 16, 27, 6, 17, 28, 5, 5, 16, 5, 5, 16, 5, 5, 16, 7,
                                      18, 29};

    unsigned short nbResource1[25] = {3, 2, 2, 2, 3, 3, 3, 2, 2, 2, 10, 12, 16, 3, 2, 2, 3, 2, 2, 3, 2, 2, 2, 2, 2};

    unsigned short idResource2[25] = {0, 6, 17, 17, 6, 17, 28, 6, 17, 28, 0, 0, 0, 0, 6, 17, 0, 6, 17, 0, 6, 17, 0, 0,
                                      0};

    unsigned short nbResource2[25] = {0, 3, 4, 5, 4, 5, 6, 6, 7, 8, 0, 0, 0, 0, 3, 4, 0, 3, 4, 0, 3, 4, 0, 0, 0};

    /*char *resources[25] = {"3 Sapin", "2 Sapin - 3 Pierre", "2 Hetre - 4 Fer", "2 Chene - 5 Fer",
                           "3 Sapin - 4 Pierre", "3 Hetre - 5 Fer", "3 Chene - 6 Diamant",
                           "2 Sapin - 6 Pierre", "2 Hetre - 7 Fer", "2 Chene - 8 Diamant",
                           "10 Pierre", "12 Fer", "16 Diamant",
                           "3 Sapin", "2 Sapin - 3 Pierre", "2 Hetre - 4 Fer",
                           "3 Sapin", "2 Sapin - 3 Pierre", "2 Hetre - 4 Fer",
                           "3 Sapin", "2 Sapin - 3 Pierre", "2 Hetre - 4 Fer",
                           "2 Herbe", "2 Lavande", "2 Chanvre"};*/

    // 1 -> zone 1, 2 -> zone 2, 3 -> zone 3, 4 -> zones 1 et 2, 5 -> zone 2 et 3, 6 -> zone 1 et 2 et 3
    unsigned short zone[25] = {6, 6, 5, 3, 6, 5, 3, 6, 5, 3, 6, 5, 3, 6, 6, 5, 6, 6, 5, 6, 6, 5, 6, 5, 3};

    for (int i = 0; i < 25; i++) {
        craft[i] = malloc(sizeof(Craft));
        *craft[i] = (Craft) {i, itemId[i], idResource1[i], nbResource1[i], idResource2[i], nbResource2[i], zone[i]};
    }
    return craft;
}

void displayCraft(Game *game) {
    printf("Menu Craft\nVoici les crafts disponibles dans votre zone : \n");
    for (int x = 0; x < 25; x += 1) {
        if ((game->player->mapId / 3 == 0 && (game->craft[x]->zone == 4 || game->craft[x]->zone == 6)) ||
            (game->player->mapId / 3 == 1 &&
             (game->craft[x]->zone == 4 || game->craft[x]->zone == 5 || game->craft[x]->zone == 6)) ||
            (game->player->mapId / 3 == 2 &&
             (game->craft[x]->zone == 3 || game->craft[x]->zone == 5 || game->craft[x]->zone == 6))) {
            if (game->craft[x]->nbResource2 > 0) {
                printf("%d, %s, %d %s, %d %s, zone : %d\n", game->craft[x]->id,
                       game->itemList[game->craft[x]->itemId]->name,
                       game->craft[x]->nbResource1, game->itemList[game->craft[x]->idResource1]->name,
                       game->craft[x]->nbResource2, game->itemList[game->craft[x]->idResource2]->name,
                       game->craft[x]->zone);
            } else {
                printf("%d, %s, %d %s, zone : %d\n", game->craft[x]->id, game->itemList[game->craft[x]->itemId]->name,
                       game->craft[x]->nbResource1, game->itemList[game->craft[x]->idResource1]->name,
                       game->craft[x]->zone);
            }
        }
    }
}

void displayPnjStorage(Game *game) {
    Storage *nextElt = game->storage;
    while (nextElt != NULL) {
        printf("address : %p, id : %d, quantity : %d\n", nextElt, nextElt->objectId, nextElt->quantity);
        nextElt = nextElt->next;
    }
}

void addToStorage(Game *game, int itemId, int quantity) {
    Storage *nextElt = game->storage;
    while (nextElt->next != NULL) {
        if (nextElt->objectId == itemId) {
            nextElt->quantity += quantity;
            return;
        }
        nextElt = nextElt->next;
    }
    if (nextElt->objectId == 0) {
        nextElt->objectId = itemId;
        nextElt->quantity = quantity;
    } else if (nextElt->objectId != itemId) {
        nextElt->next = newElementStorage(itemId, quantity);
    } else {
        nextElt->quantity += quantity;
    }
}

Storage *newElementStorage(int itemId, int quantity) {
    Storage *elt = malloc(sizeof(Storage));
    elt->objectId = itemId;
    elt->quantity = quantity;
    elt->next = NULL;
    return elt;
}

void deleteFromStorage(Game *game, int itemId) {
    Storage *nextElt = game->storage;
    if (nextElt->objectId == itemId) {
        if (nextElt->next == NULL) {
            free(game->storage);
            game->storage = initStorage();
            return;
        } else {
            game->storage = nextElt->next;
            free(nextElt);
            return;
        }
    }
    while (nextElt->next != NULL) {
        Storage *temp;
        if (nextElt->next->objectId == itemId) {
            temp = nextElt->next->next;
            free(nextElt->next);
            nextElt->next = temp;
            return;
        }
        nextElt = nextElt->next;
    }

}

void addToInventory(Game *game, int itemId, int quantity) {
    if (strcmp(game->itemList[itemId]->type, "Ressource de craft") == 0) {
        for (int i = 0; i < quantity; i += 1) {
            appendRessourceDeCraft(game->itemList, itemId, game->player->inventory);
        }
    } else if (strcmp(game->itemList[itemId]->type, "Soin") == 0) {
        for (int i = 0; i < quantity; i += 1) {
            appendPotion(game, itemId);
        }
    } else {
        for (int i = 0; i < quantity; i += 1) {
            appendItemToInventoryWhereEmpty(game->itemList, itemId, game->player->inventory);
        }
    }
}

void retrieveFromStorage(Game *game, int itemId, int quantity) {
    Storage *nextElt = game->storage;
    if (nextElt->objectId == itemId && quantity < nextElt->quantity) {
        nextElt->quantity -= quantity;
        addToInventory(game, itemId, quantity);
        return;
    } else if ((nextElt->objectId == itemId && quantity == nextElt->quantity) ||
               (nextElt->objectId == itemId && quantity > nextElt->quantity)) {
        quantity = nextElt->quantity;
        deleteFromStorage(game, itemId);
        addToInventory(game, itemId, quantity);
        return;
    }
    while (nextElt->next != NULL) {
        if (nextElt->objectId == itemId && quantity < nextElt->quantity) {
            nextElt->quantity -= quantity;
            addToInventory(game, itemId, quantity);
            return;
        } else if ((nextElt->objectId == itemId && quantity == nextElt->quantity) ||
                   (nextElt->objectId == itemId && quantity > nextElt->quantity)) {
            quantity = nextElt->quantity;
            deleteFromStorage(game, itemId);
            addToInventory(game, itemId, quantity);
            return;
        }
        nextElt = nextElt->next;
    }
}

void menuCraft(Game *game) {
    int choice;
    int success;
    success = 0;
    displayCraft(game);
    do {
        printf("Tapez l'id de l'objet que vous souhaitez créer.\n");
        scanf("%d", &choice);
    } while (choice < 0 || choice > 24);
    for (int i = 0; i < INVENTORY_SIZE; i += 1) {
        if (game->player->inventory->inventory_content[i]->value == game->craft[choice]->idResource1 && game->player->inventory->inventory_content[i]->quantity >= game->craft[choice]->nbResource1) {
            if (game->craft[choice]->nbResource2 > 0) {
                for (int j = 0; j < INVENTORY_SIZE; j += 1) {
                    if (game->player->inventory->inventory_content[j]->value == game->craft[choice]->idResource2 && game->player->inventory->inventory_content[j]->quantity >= game->craft[choice]->nbResource2) {
                        addToInventory(game, game->craft[choice]->itemId, 1);
                        if(game->player->inventory->inventory_content[j]->quantity == game->craft[choice]->nbResource2){
                            emptyInventoryElement(game, j);
                        }else{
                            game->player->inventory->inventory_content[j]->quantity -= game->craft[choice]->nbResource2;
                        }
                        success = 1;
                        printf("L'objet a bien ete cree.\n");
                    }
                }
            }else{
                addToInventory(game, game->craft[choice]->itemId, 1);
                success = 1;
            }
            if(success == 1 && game->player->inventory->inventory_content[i]->quantity == game->craft[choice]->nbResource1){
                emptyInventoryElement(game, i);
                return;
            }else if(success == 1 && game->player->inventory->inventory_content[i]->quantity > game->craft[choice]->nbResource1){
                game->player->inventory->inventory_content[i]->quantity -= game->craft[choice]->nbResource1;
                return;
            }
        }
    }
}

void storageMenu(Game *game) {
    int choice;
    int itemChoice;
    int quantity;
    do {
        printf("\nVous êtes dans l'inventaire du PNJ. Que voulez-vous faire ?\n1 - Déposer des objets\n2 - Récupérer des objets\n");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 3);
    if (choice == 1) {
        displayInventory(game);
        while (1) {
            printf("Tapez l'id de l'objet que vous souhaitez déposer\n");
            scanf("%d", &itemChoice);
            if (game->player->inventory->inventory_content[itemChoice]->value != 0) {
                addToStorage(game, game->player->inventory->inventory_content[itemChoice]->value,
                             game->player->inventory->inventory_content[itemChoice]->quantity);
                emptyInventoryElement(game, itemChoice);
                break;
            }
        }
    } else if (choice == 2) {
        displayPnjStorage(game);
        do {
            printf("Tapez l'id de l'objet que vous souhaitez récupérer\n");
            scanf("%d", &itemChoice);
        } while (itemChoice < 1 || itemChoice > 34);
        printf("Tapez la quantité voulue\n");
        scanf("%d", &quantity);
        retrieveFromStorage(game, itemChoice, quantity);
    }
}

void menuPnj(Game *game) {
    int choice = 0;
    do {
        printf("Bonjour joueur. \nQue voulez-vous faire ? \n1 - Réparer l'équipement \n2 - Accéder à l'inventaire du PNJ\n3 - Crafter des objets\n4 - Quitter\n");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 4);

    if (choice == 1) {
        repairStuff(game);
    } else if (choice == 2) {
        storageMenu(game);
    } else if (choice == 3) {
        menuCraft(game);
    } else {
        return;
    }
}