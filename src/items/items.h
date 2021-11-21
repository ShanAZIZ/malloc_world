/**
 * FILENAME: items.h
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 15/10/2021
 * Dernière modification : 21/11/2021
 * Par: AZIZ Shana
 */


typedef struct Item {
    int value;
    char *name;
    char *type;
    unsigned short damage;
    unsigned short durability;
    unsigned short quantity;
    unsigned short protection;
} Item;


#ifndef MALLOC_WORLD_ITEMS_H
#define MALLOC_WORLD_ITEMS_H

Item** createItemList();
Item* getOneItem(Item**, int);
Item* setNewItemFromList(Item** itemList, int itemId);


#endif //MALLOC_WORLD_ITEMS_H
