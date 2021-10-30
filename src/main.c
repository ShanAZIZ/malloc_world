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

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    int x = 10;
    int y = 10;
    int zone = 1;
    int* playerPosX = malloc(sizeof(int));
    int* playerPosY = malloc(sizeof(int));
    *playerPosY = 4;
    *playerPosX = 4;
    int **map = initMap(x, y, zone);
    map[*playerPosY][*playerPosX] = 1;
    fillMap(map, x, y, zone);
    displayMap(map, x, y);

    item **item_list = createItemList();
    player *my_player = initPlayer(item_list);
    int done = 0;
    int input = 0;
    while(done == 0){
        scanf("%d", &input);
        if(input == 5){
            done = 1;
        }else{
            checkCanMove(map, my_player, playerPosX, playerPosY, input, 10, 10);
            displayMap(map, x, y);
        }
    }







    /*
    srand(time(NULL));
    int x = 10;
    int y = 10;
    int zone = 1;

    int **map = initMap(x, y, zone);
    map[0][4] = 1;
    fillMap(map, x, y, zone);
    zone += 1;
    displayMap(map, x, y);

    printf("\n\n");
    x += 2;
    y += 2;
    int **map2 = initMap(x, y, zone);
    fillMap(map2, x, y, zone);
    zone += 1;
    displayMap(map2, x, y);

    printf("\n\n");

    x += 2;
    y += 2;
    int **map3 = initMap(x, y, zone);
    fillMap(map3, x, y, zone);
    displayMap(map3, x, y);
    printf("bonjour\n");
    item **item_list = createItemList();
    player *my_player = initPlayer(item_list);
    appendRessourceDeCraft(item_list, 6, my_player->inventory);
    my_player->inventory->inventory_content[4]->quantity = 20;
    appendRessourceDeCraft(item_list, 6, my_player->inventory);
    */
    return 0;
}
