/**
 * FILENAME: map.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 12/10/2021
 * Dernière modification : 17/10/2021
 * Par: DAILLY Armand
**/

// This file contains function to create a map and to display it

#include "map.h"
#include <stdio.h>
#include <stdlib.h>


// function to print the map
void displayMap(int** map, int x, int y) {
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            printf("%d\t", map[i][j]);
        }
        printf("\n");
    }
}

//function to initialize map to 0
int** initMap(int height, int width){
    int** map = malloc(sizeof(int*) * height);

    for(int i = 0; i < width; i++) {
        map[i] = malloc(sizeof(int) * width);
        for(int j = 0; j < height; j++) {
            map[i][j] = 0;
        }
    }
    return map;
}

int*** initAllMaps(int height, int width){
    int*** maps = malloc(sizeof(int**) * 10);
    maps[9] = malloc(sizeof(int*) * 3);
    for(int x = 0; x < 3; x += 1){
        maps[9][x] = malloc(sizeof(int)*2);
        maps[9][x][0] = height + 2 * x;
        maps[9][x][1] = width + 2 * x;
    }

    for(int i = 0; i < 9; i += 1){
        maps[i] = initMap(maps[9][i/3][0], maps[9][i/3][1]);
    }
    return maps;
}

void fillBaseMap(int** map, int** baseMap, int height, int width){
    for(int i = 0; i < height; i += 1){
        for(int j = 0; j < width; j += 1){
            if(map[i][j] != 1){
                baseMap[i][j] = map[i][j];
            }
        }
    }
}


//function that place walls
int** placeWalls(int** map, int width, int height){
    int randomPosX;
    int randomPosY;
    int cpt_walls;
    cpt_walls = 0;
    while(cpt_walls <= (3 + 0.1 * (width * height))){
        randomPosX = rand() % width;
        randomPosY = rand() % height;
        if(map[randomPosX][randomPosY] == 0){
            map[randomPosX][randomPosY] = -1;
            cpt_walls += 1;
        }
    }
    return map;
}

//function to place grass
int** placeGrass(int** map, int width, int height, int zone){
    int randomPosX;
    int randomPosY;
    int cpt_grass;
    cpt_grass = 0;
    while(cpt_grass <= (3 + 0.1 * (width * height))){
        randomPosX = rand() % width;
        randomPosY = rand() % height;
        if(map[randomPosX][randomPosY] == 0){
            if(zone == 1){
                map[randomPosX][randomPosY] = 3;
            }else if(zone == 2){
                map[randomPosX][randomPosY] = 6;
            }else{
                map[randomPosX][randomPosY] = 9;
            }
            cpt_grass += 1;
        }
    }
    return map;
}

//function to place rock
int** placeRock(int** map, int width, int height, int zone){
    int randomPosX;
    int randomPosY;
    int cpt_rock;
    cpt_rock = 0;
    while(cpt_rock <= (3 + 0.1 * (width * height))){
        randomPosX = rand() % width;
        randomPosY = rand() % height;
        if(map[randomPosX][randomPosY] == 0){
            if(zone == 1){
                map[randomPosX][randomPosY] = 4;
            }else if(zone == 2){
                map[randomPosX][randomPosY] = 7;
            }else{
                map[randomPosX][randomPosY] = 10;
            }
            cpt_rock += 1;
        }
    }
    return map;
}

//function to place wood
int** placeWood(int** map, int width, int height, int zone){
    int randomPosX;
    int randomPosY;
    int cpt_wood;
    cpt_wood = 0;
    while(cpt_wood <= (3 + 0.1 * (width * height))){
        randomPosX = rand() % width;
        randomPosY = rand() % height;
        if(map[randomPosX][randomPosY] == 0){
            if(zone == 1){
                map[randomPosX][randomPosY] = 5;
            }else if(zone == 2){
                map[randomPosX][randomPosY] = 8;
            }else{
                map[randomPosX][randomPosY] = 11;
            }
            cpt_wood += 1;
        }
    }
    return map;
}

//function to place the NPC
int** placeNPC(int** map, int width, int height){
    int randomPosX;
    int randomPosY;
    do{
        randomPosX = rand() % width;
        randomPosY = rand() % height;
        if(map[randomPosX][randomPosY] != 0){
            continue;
        }else{
            map[randomPosX][randomPosY] = 2;
        }
        break;
    }while(1);
    return map;
}

//function that places the portals
int** placePortal(int** map, int width, int height, int zone){
    int randomPosX;
    int randomPosY;
    while(1){
        randomPosX = rand() % width;
        randomPosY = rand() % height;
        if(map[randomPosX][randomPosY] != 0){
            continue;
        }else if(zone == 1){
            map[randomPosX][randomPosY] = -2;
        }else if(zone == 2){
            map[randomPosX][randomPosY] = -2;
            while(1){
                randomPosX = rand() % width;
                randomPosY = rand() % height;
                if(map[randomPosX][randomPosY] != 0){
                    continue;
                }else{
                    map[randomPosX][randomPosY] = -3;
                }
                break;
            }
        }else if(zone == 3){
            map[randomPosX][randomPosY] = -3;
        }
        break;
    }
    return map;
}

//function to place boss in zone 3
int** placeBoss(int** map, int width, int height){
    do{
        int randomPos = rand() % (width - 1);
        if(map[randomPos][randomPos] != 0){
            continue;
        }else{
            map[randomPos][randomPos] = 99;
        }
        break;
    }while(1);
    return map;
}

//function that places monsters
int** placeMonsters(int** map, int width, int height, int zone){
    int randomPosX;
    int randomPosY;
    int cpt_monster;
    cpt_monster = 0;
    while(cpt_monster <= (10 + 0.05 * (width * height))){
        randomPosX = rand() % width;
        randomPosY = rand() % height;
        if(map[randomPosX][randomPosY] == 0){
            map[randomPosX][randomPosY] = rand() % 3 + 9 + (zone * 3);
            cpt_monster += 1;
        }
    }
    return map;
}

//function that fill the map by calling all the "place" functions
int** fillMap(int** map, int width, int height, int zone){
    if(zone == 3){
        map = placeBoss(map, width, height);
    }
    map = placeNPC(map, width, height);
    map = placePortal(map, width, height, zone);
    map = placeMonsters(map, width, height, zone);
    map = placeWood(map, width, height, zone);
    map = placeRock(map, width, height, zone);
    map = placeGrass(map, width, height, zone);
    map = placeWalls(map, width, height);
    return map;

}

void fillAllMaps(int*** maps, int zone){
    for(int x = 0; x < 3; x += 1){
        maps[0 + x * 3] = fillMap(maps[0 + x * 3], maps[9][x][1], maps[9][x][0], zone + x);
        fillBaseMap(maps[0 + x * 3], maps[2 + x * 3], maps[9][x][0], maps[9][x][1]);
    }
}

