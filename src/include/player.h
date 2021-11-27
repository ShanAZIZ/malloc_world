/**
 * FILENAME: monsters.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 15/10/2021
 * Dernière modification : 20/11/2021
 * Par: DAILLY Armand
**/

#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"

#ifndef MALLOC_WORLD_PLAYER_H
#define MALLOC_WORLD_PLAYER_H

/**
 * Struct Player
 */


/**
 * Initialise un joueur de debut de partie
 * @return
 */
Player* initPlayer(Item**);
Inventory* getInventory(Player* player);

#endif