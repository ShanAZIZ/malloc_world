//
// Created by arman on 30/10/2021.
//

#ifndef MALLOC_WORLD_MOVE_H
#define MALLOC_WORLD_MOVE_H

#include "../player/player.h"
int** checkCanMove(int** map, player* player, int* playerPosX, int* playerPosY, int choice, int lenX, int lenY);
int** collectRessources(int** map, player* player, int posX, int posY);
int** move(int** map, player* player, int* playerPosX, int* playerPosY, int posX, int posY);

#endif //MALLOC_WORLD_MOVE_H
