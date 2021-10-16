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
int** initMap(int width, int height, int zone){
    int** map = malloc(sizeof(int*) * width);

    for(int i = 0; i < width; i++) {
        map[i] = malloc(sizeof(int) * height);
        for(int j = 0; j < height; j++) {
            map[i][j] = 0;
        }
    }
    return map;
}

//function to place grass
int** placeGrass(int** map, int posX, int posY, int zone, int* cpt_grass){
    if(zone == 1){
        map[posX][posY] = 3;
    }else if(zone == 2){
        map[posX][posY] = 6;
    }else{
        map[posX][posY] = 9;
    }
    *cpt_grass += 1;
    return map;
}

//function to place rock
int** placeRock(int** map, int posX, int posY, int zone, int* cpt_rock){
    if(zone == 1){
        map[posX][posY] = 4;
    }else if(zone == 2){
        map[posX][posY] = 7;
    }else{
        map[posX][posY] = 10;
    }
    *cpt_rock += 1;
    return map;
}

//function to place wood
int** placeWood(int** map, int posX, int posY, int zone, int* cpt_wood){
    if(zone == 1){
        map[posX][posY] = 5;
    }else if(zone == 2){
        map[posX][posY] = 8;
    }else{
        map[posX][posY] = 11;
    }
    *cpt_wood += 1;
    return map;
}

//function to place monster
int** placeMonster(int** map, int posX, int posY, int zone, int* cpt_monster){
    switch (rand() % 2 + 1) {
        case 1:
            map[posX][posY] = rand() % 85 + 12;
            break;
        default:
            break;
    }
    *cpt_monster += 1;
    return map;
}

//function to place the NPC
int** placeNPC(int** map, int width){
    do{
        int randomPos = rand() % (width - 1);
        if(map[randomPos][randomPos] != 0){
            continue;
        }else{
            map[randomPos][randomPos] = 2;
        }
        break;
    }while(1);
    return map;
}

//function
int** placePortal(int** map, int width, int zone){
    int randomPos;
    int finished = 0;
    do{
        randomPos = rand() % (width - 1);
        switch (zone) {
            case 1:
                if(map[randomPos][randomPos] != 0){
                    continue;
                }else{
                    map[randomPos][randomPos] = -2;
                    finished = 1;
                }
                break;
            case 2:
                if(map[randomPos][randomPos] != 0){
                    continue;
                }else{
                    map[randomPos][randomPos] = -2;
                    do{
                        randomPos = rand() % (width - 1);
                        if(map[randomPos][randomPos] != 0){
                            continue;
                        }else{
                            map[randomPos][randomPos] = -3;
                            finished = 1;
                            break;
                        }
                    }while(1);
                }
                break;
            default:
                if(map[randomPos][randomPos] != 0){
                    continue;
                }else{
                    map[randomPos][randomPos] = -3;
                    finished = 1;
                }
                break;
        }
    }while(finished != 1);
    return map;
}

//function to place boss in zone 3
int** placeBoss(int** map, int width){
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

//function that fill the map using all place functions except placeBoss
int** fillMap(int** map, int width, int height, int zone){
    int* cpt_grass = malloc(sizeof(int));
    *cpt_grass = 0;
    int* cpt_rock = malloc(sizeof(int));
    *cpt_rock = 0;
    int* cpt_wood = malloc(sizeof(int));
    *cpt_wood = 0;
    int* cpt_monster = malloc(sizeof(int));
    *cpt_monster = 0;
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            if(map[i][j] == 0){
                switch (((width + 1) == 6) ? (rand() % 6 + 1) : (rand() % width + 1)) {
                    case 1:
                        if(*cpt_grass <= (3 + 0.1 * (width * height))){
                            map = placeGrass(map, i, j, zone, cpt_grass);
                        }
                        break;
                    case 2:
                        if(*cpt_rock <= (3 + 0.1 * (width * height))){
                            map = placeRock(map, i, j, zone, cpt_rock);
                        }
                        break;
                    case 3:
                        if(*cpt_wood <= (3 + 0.1 * (width * height))){
                            map = placeWood(map, i, j, zone, cpt_wood);
                        }
                        break;
                    case 4:
                        if(*cpt_monster <= (10 + 0.05 * (width * height))){
                            map = placeMonster(map, i, j, zone, cpt_monster);
                        }
                        break;
                    case 5:
                        if(*cpt_monster <= (10 + 0.05 * (width * height))){
                            map = placeMonster(map, i, j, zone, cpt_monster);
                        }
                        break;
                    case 6:
                        map[i][j] = -1;
                        break;
                    default:
                        break;
                }
            }
        }
    }
    map = placeNPC(map, width);
    map = placePortal(map, width, zone);
    return map;
}


