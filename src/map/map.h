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

int** createMap(int, int, int);
void displayMap(int**, int, int);
int defineRandom(int, int);
int** placePlayer(int**);
int** generateByZone(int**, int, int, int);
int** placePortalZone2(int**);
int** placePortalZone3(int**);

#endif