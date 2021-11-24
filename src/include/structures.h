//
// Created by arman on 24/11/2021.
//

#ifndef MALLOC_WORLD_STRUCTURES_H
#define MALLOC_WORLD_STRUCTURES_H

typedef struct Item {
    int value;
    char *name;
    char *type;
    unsigned short damage;
    unsigned short durability;
    unsigned short quantity;
    unsigned short protection;
} Item;

typedef struct Inventory {
    Item** inventory_content;
} Inventory;

typedef struct Player {
    int current_xp;
    int level;
    int current_hp;
    Inventory* inventory;
    int posX;
    int posY;
    int mapId;
} Player;

typedef struct Storage {
    int objectId;
    int quantity;
    struct Storage* next;
} Storage;

typedef struct Craft{
    unsigned short id;
    unsigned short itemId;
    unsigned short idResource1;
    unsigned short nbResource1;
    unsigned short idResource2;
    unsigned short nbResource2;
    unsigned short zone;
} Craft;

typedef struct Game {
    int ***maps;
    Item **itemList;
    Player *player;
    Craft** craft;
    Storage* storage;
} Game;
#endif //MALLOC_WORLD_STRUCTURES_H
