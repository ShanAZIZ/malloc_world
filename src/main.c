/**
 * FILENAME: main.c
 * Made by: GROUPE 5 - AL2 
 * Projet: Malloc-World
 * Date de création: 09/10/2021
 * Dernière modification : 12/10/2021
 * Par: AZIZ Shana
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "map/map.h"

int main(int argc, char const *argv[])
{
    int x = 10;
    int y = 10;
    int zone = 1;

    int** map = createMap(x, y, zone);
    map = placePlayer(map);
    displayMap(map, x, y);
    zone += 1;
    printf("\n\n");

    int** map2 = createMap(x, y, zone);
    displayMap(map2, x, y);
    zone += 1;
    printf("\n\n");

    int** map3 = createMap(x, y, zone);
    displayMap(map3, x, y);
    return 0;
}