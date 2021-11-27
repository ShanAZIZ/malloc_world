/**
 * FILENAME: monsters.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 15/11/2021
 * Dernière modification : 20/11/2021
 * Par: DAILLY Armand
**/

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
    Item** inventoryContent;
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
    int currentXp;
    int level;
    int currentHp;
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
    Monster** monsterList;
    Storage* storage;
} Game;

void freeGame(Game* game);
void freeMap(Game* game);
void freeStorage(Storage* storage);

#endif //MALLOC_WORLD_STRUCTURES_H
