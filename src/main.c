/**
 * FILENAME: main.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 09/10/2021
 * Dernière modification : 22/10/2021
 * Par: DAILLY Armand
 */

#include <time.h>
#include "cli/cli.h"

Game* initGame(int, int, int);


int main(int argc, char const *argv[]) {
    srand(time(NULL));

    int x = 10;
    int y = 10;
    int zone = 1;

    Game *game = initGame(x, y, zone); // Initialisation de départ du jeu

    start(game);
    freeGame(game);
    return 0;
}

Game* initGame(int x, int y, int zone){
    Game *game = malloc(sizeof(Game));
    game->maps = initAllMaps(x, y);
    game->maps[0][4][4] = 1;
    fillAllMaps(game->maps, zone);
    game->itemList = createItemList();
    game->monsterList = createMonsterList();
    game->player = initPlayer(game->itemList);
    game->craft = initCraft();
    game->storage = initStorage();
    return game;
}