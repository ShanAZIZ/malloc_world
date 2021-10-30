/**
 * FILENAME: map.h
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 12/10/2021
 * Dernière modification : 17/10/2021
 * Par: DAILLY Armand
 */

#ifndef MAP_H
#define MAP_H


void displayMap(int**, int, int);
int** initMap(int width, int height, int zone);
int** placeWalls(int** map, int width, int height);
int** placeGrass(int** map, int posX, int posY, int zone);
int** placeRock(int** map, int posX, int posY, int zone);
int** placeWood(int** map, int posX, int posY, int zone);
int** placeMonsters(int** map, int posX, int posY, int zone);
int** placeNPC(int** map, int width, int height);
int** placePortal(int** map, int width, int height, int zone);
int** placeBoss(int** map, int width, int height);
int** fillMap(int** map, int width, int height, int zone);

#endif