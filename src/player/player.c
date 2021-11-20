#include "player.h"

Player * initPlayer(Item** item_list){
    Item** itemList2 = createItemList();
    Player * mainPlayer = malloc(sizeof(Player));
    mainPlayer->current_hp = 100;
    mainPlayer->level = 1;
    mainPlayer->current_xp=0;
    mainPlayer->posX = 4;
    mainPlayer->posY = 4;
    mainPlayer->inventory = initPlayerInventory(item_list);
    mainPlayer->mapId = 0;
    return mainPlayer;
}

Inventory* getInventory(Player* player){
    return player->inventory;
}