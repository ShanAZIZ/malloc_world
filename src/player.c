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