/**
 * FILENAME: items.h
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 15/10/2021
 * Dernière modification : 15/10/2021
 * Par: DAILLY Armand
 */

struct item {
    int value;
    char *name;
    char *type;
    unsigned short damage;
    unsigned short durability;
    unsigned short quantity;
    unsigned short protection;
};

typedef struct item item;

#ifndef MALLOC_WORLD_ITEMS_H
#define MALLOC_WORLD_ITEMS_H

item** createItemList();

#endif //MALLOC_WORLD_ITEMS_H
