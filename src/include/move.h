/**
 * FILENAME: monsters.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 30/10/2021
 * Dernière modification : 20/11/2021
 * Par: DAILLY Armand
**/

#ifndef MALLOC_WORLD_MOVE_H
#define MALLOC_WORLD_MOVE_H

#include "player.h"
#include "battles.h"
#include "pnj.h"

void checkCanMove(Game* game, int choice);
int checkInInventory(Player* player, int itemId);
int collectStone(Game* game, int posX, int posY);
int collectWood(Game* game, int posX, int posY);
int collectPlant(Game* game, int posX, int posY);
void collectResources(Game* game, int posX, int posY);
void findPortal(Game* game, int idPortal);
void passPortal(Game* game, int idPortal);
void decrementTimers(Game* game);
void move(Game* game, int posX, int posY);
void movePlayerAddTimer(Game *game, int posX, int posY, int timer);
int getNextHp(Game *game);
int getNextXp(Game* game);

#endif //MALLOC_WORLD_MOVE_H
