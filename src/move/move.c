//
// Created by arman on 30/10/2021.
//
#include "move.h"

int** checkCanMove(int** map, player* player, int* playerPosX, int* playerPosY, int choice, int lenX, int lenY){
    if(choice == 1){
        if(*playerPosY == 0){
            printf("pas possible");
        }else{
            move(map, player, playerPosX, playerPosY, *playerPosX, *playerPosY - 1);
        }
    }else if(choice == 2){
        if(*playerPosX == lenX - 1){
            printf("pas possible");
        }else{
            move(map, player, playerPosX, playerPosY, *playerPosX + 1, *playerPosY);
        }
    }else if(choice == 3){
        if(*playerPosY == lenY - 1){
            printf("pas possible");
        }else{
            move(map, player, playerPosX, playerPosY, *playerPosX, *playerPosY + 1);
        }
    }else if(choice == 4){
        if(*playerPosX == 0){
            printf("pas possible");
        }else{
            move(map, player, playerPosX, playerPosY, *playerPosX - 1, *playerPosY);
        }
    }
    return map;
}

int** collectRessources(int** map, player* player, int posX, int posY){
    printf("ressource");
    return map;
}

int** move(int** map, player* player, int* playerPosX, int* playerPosY, int posX, int posY){
    if(map[posY][posX] < 12 && map[posY][posX] > 2){
        collectRessources(map, player, posX, posY);
    }else if(map[posY][posX] == 2) {
        printf("pnj");
    }else if(map[posY][posX] == -1){
        printf("mur");
    }else if(map[posY][posX] < 100 && map[posY][posX] > 11){
        printf("monstre");
    }else{
        map[posY][posX] = 1;
        map[*playerPosY][*playerPosX] = 0;
        *playerPosX = posX;
        *playerPosY = posY;
    }
    return map;
}