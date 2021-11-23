//
// Created by Audrey Divito on 22/11/2021.
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

typedef struct Monster {
    int id;
    char *name;
    unsigned short hp;
    unsigned short att;
    unsigned short def;
    unsigned short xp;
} Monster;

typedef struct Player {
    int current_xp;
    int level;
    int current_hp;
    Inventory* inventory;
    int posX;
    int posY;
    int mapId;
} Player;

typedef struct Game {
    int*** maps;
    Item** itemList;
    Player* player;
    Monster** monsterList;
} Game;

#endif //MALLOC_WORLD_STRUCTURES_H
