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

    Game *game = malloc(sizeof(Game));
    game->maps = initAllMaps(x, y);
    game->maps[0][4][4] = 1;
    fillAllMaps(game->maps, zone);
    game->itemList = createItemList();

    game->player = initPlayer(game->itemList);
    game->player->level = 3;
    displayMap(game->maps[0], game->maps[9][0][0], game->maps[9][0][1]);

    int done = 0;
    int input = 0;
    while (done == 0) {
        scanf("%d", &input);
        if (input == 5) {
            done = 1;
        } else {
            checkCanMove(game, input);
            displayMap(game->maps[game->player->mapId], game->maps[9][game->player->mapId / 3][0],
                       game->maps[9][game->player->mapId / 3][1]);
            decrementTimers(game);
            fflush(stdin);
        }
    }
    printf("Leaving the game");


//    int** map = initMap(x, y, zone);
//    map[4][4] = 1;
//    fillMap(map, x, y, zone);
//    zone += 1;
//    displayMap(map, x, y);
//
//    printf("\n\n");
//    x += 2;
//    y += 2;
//    int** map2 = initMap(x, y, zone);
//    fillMap(map2, x, y, zone);
//    zone += 1;
//    displayMap(map2, x, y);
//
//    printf("\n\n");
//
//    x += 2;
//    y += 2;
//    int** map3 = initMap(x, y, zone);
//    fillMap(map3, x, y, zone);
//    displayMap(map3, x, y);
//
//    // TESTS
//    //printf("%s", my_player->inventory->inventory_content[0]->type);
//
//    appendRessourceDeCraft(item_list, 6, my_player->inventory);
//    my_player->inventory->inventory_content[4]->quantity = 20;
//    storage* tempStorage = initTempStorage(item_list);
//    //saveMap(map, map2, map3, 10, 10);
//    //savePlayer(my_player, tempStorage);
//    loadMapZone(map, 1, 10, 10);
//    displayMap(map, 10, 10);
//    loadPlayer(my_player, item_list, tempStorage);
//    printf("storage first qty : %d \n", tempStorage->item->quantity);
//    printf("second value: %d \n", tempStorage->next->item->value);
//    printf("level : %d \n", my_player->level);
//    printf("Inventory at index 4 quantity: %d \n", my_player->inventory->inventory_content[4]->quantity);
//    printf("Inventory at index 4 name: %s \n", my_player->inventory->inventory_content[4]->name);
//
//    //ladMapZone(map, 2, 10,10);o

    return 0;
}
