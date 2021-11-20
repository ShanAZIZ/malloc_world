//
// Created by arman on 30/10/2021.
//

#ifndef MALLOC_WORLD_MOVE_H
#define MALLOC_WORLD_MOVE_H

#include "../player/player.h"

typedef struct Game {
    int ***maps;
    Item **itemList;
    Player *player;

} Game;

void checkCanMove(Game* game, int choice);
int checkInInventory(Player* player, int itemId);
int collectStone(Game* game, int posX, int posY);
int collectWood(Game* game, int posX, int posY);
int collectPlant(Game* game, int posX, int posY);
void collectRessources(Game* game, int posX, int posY);
void findPortal(Game* game, int idPortal);
void passPortal(Game* game, int idPortal);
void decrementTimers(Game* game);
void move(Game* game, int posX, int posY);

#endif //MALLOC_WORLD_MOVE_H
