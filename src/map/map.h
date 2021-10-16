/**
 * FILENAME: map.h
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 12/10/2021
 * Dernière modification : 13/10/2021
 * Par: DI VITO Audrey
 */

#ifndef MAP_H
#define MAP_H


void displayMap(int**, int, int);
int** initMap(int width, int height, int zone);
int** placeGrass(int** map, int posX, int posY, int zone, int* cpt_grass);
int** placeRock(int** map, int posX, int posY, int zone, int* cpt_rock);
int** placeWood(int** map, int posX, int posY, int zone, int* cpt_wood);
int** placeMonster(int** map, int posX, int posY, int zone, int* cpt_monster);
int** placeNPC(int** map, int width);
int** placePortal(int** map, int width, int zone);
int** placeBoss(int** map, int width);
int** fillMap(int** map, int width, int height, int zone);

#endif