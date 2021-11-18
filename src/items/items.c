/**
 * FILENAME: items.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 15/10/2021
 * Dernière modification : 15/10/2021
 * Par: DAILLY Armand
 */

#include <stdio.h>
#include <stdlib.h>

#include "items.h"

item** createItemList(void){
    int count;
    count = 1;
    item **itemList = malloc(sizeof(item*) * 35);
    itemList[0] = malloc(sizeof(item));
    itemList[0] = NULL;
    char* names[34] = {"Epee en bois", "Pioche en bois", "Serpe en bois", "Hache en bois", "Sapin", "Pierre",
                          "Herbe", "Epee en pierre", "Lance en pierre", "Marteau en pierre", "Plastron en pierre",
                          "Pioche en pierre", "Serpe en pierre", "Hache en pierre", "Potion de vie I", "Hetre", "Fer",
                          "Lavande", "Epee en fer", "Lance en fer", "Marteau en fer", "Plastron en fer",
                          "Pioche en fer", "Serpe en fer", "Hache en fer", "Potion de vie II", "Chene", "Diamant",
                          "Chanvre", "Epee en diamant", "Lance en diamant", "Marteau en diamant", "Plastron en diamant",
                          "Potion de vie III"};
    char* types[34] = {"Arme", "Outil", "Outil", "Outil", "Ressource de craft", "Ressource de craft",
                          "Ressource de craft", "Arme", "Arme", "Arme", "Armure",
                          "Outil", "Outil", "Outil", "Soin", "Ressource de craft", "Ressource de craft",
                          "Ressource de craft", "Arme", "Arme", "Arme", "Armure",
                          "Outil", "Outil", "Outil", "Soin", "Ressource de craft", "Ressource de craft",
                          "Ressource de craft", "Arme", "Arme", "Arme", "Armure",
                          "Soin"};
    unsigned short damage[34] = {1, 0, 0, 0, 0, 0, 0, 2, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 5, 7, 10, 0, 0, 0, 0, 0, 0,
                      0, 0, 10, 15, 20, 0, 0};
    unsigned short durability[34] = {10, 10, 10, 10, 1, 1, 1, 10, 8, 5, 1, 10, 10, 10, 1, 1, 1, 1, 10, 8, 5, 1, 10, 10, 10, 1, 1,
                          1, 1, 10, 8, 5, 1, 1};
    unsigned short protection[34] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 40, 0};
    for (int i = 1; i < 35; i++) {
        count += 1;
        itemList[i] = malloc(sizeof(item));
        *itemList[i] = (item) {i, names[i - 1], types[i - 1], damage[i - 1], durability[i - 1], 1, protection[i - 1]};
    }
    return itemList;
}

item* getOneItem(item** itemList, int itemId){
    return itemList[itemId];
}

item* setNewItemFromList(item** itemList, int itemId){
    item* item1 = malloc(sizeof(item));
    item* temp = getOneItem(itemList, itemId);
    *(item1) = (item){0, "", "", 0, 0, 0, 0};
    item1->value = temp->value;
    item1->name = temp->name;
    item1->type = temp->type;
    item1->damage = temp->damage;
    item1->durability = temp->durability;
    item1->quantity = temp->quantity;
    item1->protection = temp->protection;

    return  item1;
}