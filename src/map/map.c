/**
 * FILENAME: map.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 12/10/2021
 * Dernière modification : 12/10/2021
 * Par: DI VITO Audrey
**/

// This file contains function to create a map and to display it

#include "map.h"

#include <stdio.h>
#include <stdlib.h>

// function to make a random number for zone
int defineRandom(int min) {
    int random = (rand() % (7 - 0 + 1 + (-2))) - min;
    return random;
}

// function to create the map
// take the large and long in arguments
int** createMap(int x, int y) {
    int** map = malloc(sizeof(int*) * x);
    for(int i = 0; i < x; i++) {
        map[i] = malloc(sizeof(int) * y);
        for(int j = 0; j < y; j++) {
            int random = defineRandom(5);
            if(random == 1) {
                map[i][j] = 0;
            } else {
                map[i][j] = random;
            }
        }
    }
    return map;
}

// function to print the map
void displayMap(int** map, int x, int y) {
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            printf("%d\t", map[i][j]);
        }
        printf("\n");
    }
}