/**
 * FILENAME: main.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 09/10/2021
 * Dernière modification : 22/10/2021
 * Par: DAILLY Armand
 */

#include<stdio.h>
#include<stdlib.h>

#include "move/move.h"
#include <time.h>
#include "map/map.h"

typedef struct Game{
    int*** maps;
    Item** itemList;
    Player* player;

} Game;
int main(int argc, char const *argv[]) {
    srand(time(NULL));
    int x = 10;
    int y = 10;
    int zone = 1;

    Game* game = malloc(sizeof(Game));
    game->maps = initAllMaps(x, y);
    game->maps[0][4][4] = 1;
    fillAllMaps(game->maps, zone);
    game->itemList = createItemList();

    game->player = initPlayer(game->itemList);

    displayMap(game->maps[0], game->maps[9][0][0], game->maps[9][0][1]);


    /*int done = 0;
    int input = 0;
    while(done == 0){
        scanf("%d", &input);
        if(input == 5){
            done = 1;
        }else{
            checkCanMove(map, my_player, playerPosX, playerPosY, input, 10, 10);
            displayMap(map, x, y);
        }
    }*/

    return 0;
}
