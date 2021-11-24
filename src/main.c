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
#include "../move/move.h"
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
    game->craft = initCraft();
    game->storage = initStorage();

    game->player = initPlayer(game->itemList);

    /*displayMap(game->maps[0], game->maps[9][0][0], game->maps[9][0][1]);

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
    }*/
    displayInventory(game);
    addToStorage(game, 5, 15);
    addToStorage(game, 1, 2);
    addToStorage(game, 7, 15);
    displayPnjStorage(game);
    retrieveFromStorage(game, 1, 2);
    displayPnjStorage(game);
    displayInventory(game);
    printf("Leaving the game");
    return 0;
}
