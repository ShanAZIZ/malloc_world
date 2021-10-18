#include "player.h"

player * initPlayer(item** item_list){
    player * mainPlayer = malloc(sizeof(player));
    mainPlayer->current_hp = 100;
    mainPlayer->level = 1;
    mainPlayer->current_xp=0;
    mainPlayer->inventory = initPlayerInventory(item_list);
    return mainPlayer;
}