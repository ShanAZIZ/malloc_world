/**
 * FILENAME: monsters.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 17/10/2021
 * Dernière modification : 25/11/2021
 * Par: DAILLY Armand
**/

#include "player.h"

Player * initPlayer(Item** itemList){
    Player * mainPlayer = malloc(sizeof(Player));
    mainPlayer->currentHp = 100;
    mainPlayer->level = 1;
    mainPlayer->currentXp=0;
    mainPlayer->posX = 4;
    mainPlayer->posY = 4;
    mainPlayer->inventory = initPlayerInventory(itemList);
    mainPlayer->mapId = 0;
    return mainPlayer;
}

Inventory* getInventory(Player* player){
    return player->inventory;
}