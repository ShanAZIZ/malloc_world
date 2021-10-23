/**
 * FILENAME: items.h
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 15/10/2021
 * Dernière modification : 15/10/2021
 * Par: DAILLY Armand
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

#endif //MALLOC_WORLD_ITEMS_H
