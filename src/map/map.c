/**
 * FILENAME: map.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 12/10/2021
 * Dernière modification : 13/10/2021
 * Par: DI VITO Audrey
**/

// This file contains function to create a map and to display it

#include "map.h"

#include <stdio.h>
#include <stdlib.h>

// function to make a random number for zone
int defineRandom(int min, int max) {
    int random = (rand() % (max - 0 + 1 + (-2))) - min;
    return random;
}

// function to place the portal in first zone to second zone and second zone to first zone
int** placePortalZone2(int** map) {
    int random1 = (rand() % (sizeof(**map)));
    int random2 = (rand() % (sizeof(**map)));

    if(map[random1][random2] == 0) {
        map[random1][random2] = -2;
    } else {
        map = placePortalZone2(map);
    }

    return map;
}

// function to place the portal in first zone to second zone and second zone to first zone
int** placePortalZone3(int** map) {
    int random1 = (rand() % (sizeof(**map)));
    int random2 = (rand() % (sizeof(**map)));

    if(map[random1][random2] == 0) {
        map[random1][random2] = -3;
    } else {
        map = placePortalZone3(map);
    }

    return map;
}

// function to create the map
// take the large, long and zone to create in arguments
int** createMap(int x, int y, int zone) {
    int** map = malloc(sizeof(int*) * x);
    for(int i = 0; i < x; i++) {
        map[i] = malloc(sizeof(int) * y);
        for(int j = 0; j < y; j++) {
            map = generateByZone(map, zone, i, j);
        }
    }

    if(zone == 1 || zone == 2) {
        map = placePortalZone2(map);
    }

    if(zone == 2 || zone == 3) {
        map = placePortalZone3(map);
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

// function to place the player
int** placePlayer(int** map) {
    int random1 = (rand() % (sizeof(**map)));
    int random2 = (rand() % (sizeof(**map)));

    if(map[random1][random2] == 0) {
        map[random1][random2] = 1;
    } else {
        map = placePlayer(map);
    }

    return map;
}

// function to generate map by zone
int** generateByZone(int** map, int zone, int i, int j) {
    int random;
    switch(zone) {
        case 1: {
            random = defineRandom(1, 7);
            if(random == 1) {
                map[i][j] = 0;
            } else {
                map[i][j] = random;
            }
            break;
        }

        case 2: {
            random = defineRandom(1, 9);
            if(random == 1 || random == 3 || random == 5 || random == 4) {
                map[i][j] = 0;
            } else {
                map[i][j] = random;
            }
            break;
        }

        case 3: {
            random = defineRandom(1, 14);
            if(random == 1 || random == -2 || random == 3 || random == 4 || random == 5 || random == 6 || random == 7 || random == 8) {
                map[i][j] = 0;
            } else {
                map[i][j] = random;
            }
            break;
        }

        default: {
            return 0;
        }
    }
    return map;
}