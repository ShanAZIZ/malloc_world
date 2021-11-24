#include "structures.h"
#include "stdio.h"
#include "stdlib.h"

void freeGame(Game* game){
    freeMap(game);
    // Free player
    for(int i = 0; i < 10; i++){
        free(game->player->inventory->inventoryContent[i]);
    }
    free(game->player->inventory);
    free(game->player);
    // Free monsters
    for(int i = 0; i<21; i += 1){
        free(game->monsterList[i]);
    }
    free(game->monsterList[99]);
    free(game->monsterList);

    // Free craft
    for(int i = 0; i<25; i+= 1){
        free(game->craft[i]);
    }
    free(game->craft);

    freeStorage(game->storage);
    // Free itemList
    for (int i = 0; i < 35; i++) {
        free(game->itemList[i]);
    }
    free(game->itemList);

    free(game);
}

void freeMap(Game* game){
    for(int i = 0; i<9; i+=1 ){
        for(int j = 0; j < game->maps[9][i/3][0]; j+=1){
            free(game->maps[i][j]);
        }
    }
    for(int i = 0; i<3; i+=1){
        free(game->maps[9][i]);
    }
    free(game->maps);
}

void freeStorage(Storage* storage){
    if (storage->next != NULL){
        freeStorage(storage->next);
    }
    free(storage);
}