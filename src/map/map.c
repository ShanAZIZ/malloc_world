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
    return (rand() % (max - min) + min);
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
    int* cptGrass = malloc(sizeof(int));
    int* cptWood = 0;
    int* cptRocks = 0;
    int** map = malloc(sizeof(int*) * x);

    *cptGrass = 0;

    for(int i = 0; i < x; i++) {
        map[i] = malloc(sizeof(int) * y);
        for(int j = 0; j < y - 1; j++) {
            map = generateByZone(map, zone, i, j, cptGrass, cptRocks, cptWood);
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
int** generateByZone(int** map, int zone, int i, int j, int* cptGrass, int* cptRocks, int* cptWood) {
    int random = 0;
    switch(zone) {
        case 1: {
            do {
                random = defineRandom(-1, 2);
            } while (random == 1);

            map[i][j] = random;

            while(*cptGrass < 3) {
                printf("%d\n", *cptGrass);
                map = placeGrass(map, cptGrass, i, j, zone);
                *cptGrass += 1;
            }


            /*for(int cptRocks = 0; cptRocks < 3; cptRocks++) {
                map = placeRocks(map, cptRocks, i, j, zone);
            }

            for(int cptGrass = 1; cptGrass <= 3; cptGrass++) {
                map = placeGrass(map, cptGrass, i, j, zone);
            }

            for(int cptWood = 0; cptWood < 3; cptWood++) {
                if(map[i][j] == 0) {
                    map = placeWood(map, cptWood, i, j, zone);
                }
            }*/

            break;
        }

        case 2: {
            do {
                random = defineRandom(-1, 2);
            } while(random == 1);

            for(int cptRocks = 0; cptRocks < 3; cptRocks++) {
                map = placeRocks(map, cptRocks, i, j, zone);
            }

            for(int cptGrass = 0; cptGrass < 3; cptGrass++) {
                map = placeGrass(map, cptGrass, i, j, zone);
            }

            for(int cptWood = 0; cptWood < 3; cptWood++) {
                map = placeWood(map, cptWood, i, j, zone);
            }

            map[i][j] = random;
            break;
        }

        case 3: {
            do {
                random = defineRandom(-1, 2);
            } while(random == 1);

            for(int cptGrass = 0; cptGrass < 3; cptGrass++) {
                map = placeGrass(map, cptGrass, i, j, zone);
            }

            for(int cptRocks = 0; cptRocks < 3; cptRocks++) {
                map = placeRocks(map, cptRocks, i, j, zone);
            }

            for(int cptWood = 0; cptWood < 3; cptWood++) {
                map = placeWood(map, cptWood, i, j, zone);
            }

            map[i][j] = random;
            break;
        }

        default: {
            return 0;
        }
    }
    return map;
}

// place the rocks
int** placeRocks(int** map, int cptRocks, int i, int j, int zone) {
    if(zone == 1) {
        map[i][j] = 4;
    } else if(zone == 2) {
        map[i][j] = 7;
    } else if(zone == 3) {
        map[i][j] = 10;
    }

    return map;
}

// place the grass
int** placeGrass(int** map, int* cptGrass, int i, int j, int zone) {
    if(zone == 1) {
        printf("%d - %d\n", i, j);
        map[i][j] = 3;
    } else if(zone == 2) {
        map[i][j] = 6;
    } else if(zone == 3) {
        map[i][j] = 9;
    }
    return map;
}

// place the wood
int** placeWood(int** map, int cptWood, int i, int j, int zone) {
    if(cptWood < 3) {
        if(zone == 1) {
            map[i][j] = 5;
        } else if(zone == 2) {
            map[i][j] = 8;
        } else if(zone == 3) {
            map[i][j] = 11;
        }
    }

    return map;
}