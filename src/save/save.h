/**
 * FILENAME: save.h
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 27/10/2021
 * Dernière modification : 27/10/2021
 * Par: AZIZ Shana
 */


#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "map.h"
#include "string.h"

#ifndef MALLOC_WORLD_SAVE_H
#define MALLOC_WORLD_SAVE_H

#endif

void saveZone(FILE*, int**, int, int);
void saveMap(int**, int**, int**, int, int);
void savePlayer(player* player);
void saveInventory(FILE*, inventory* inventory);
void loadPlayer(player* player, item**);
void loadPlayerInventory(FILE* player_save_file, inventory* player_inventory, item**);
