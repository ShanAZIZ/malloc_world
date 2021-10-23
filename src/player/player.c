#include "player.h"

Player * initPlayer(Item** item_list){
    printf("\ntest3");
    Player* mainPlayer = malloc(sizeof(Player));
    mainPlayer->current_hp = 100;
    mainPlayer->level = 1;
    mainPlayer->current_xp = 0;
    mainPlayer->inventory = initPlayerInventory(item_list);
    return mainPlayer;
}

Inventory* getInventory(Player* player){
    return player->inventory;
}