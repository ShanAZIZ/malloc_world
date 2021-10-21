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
#include<string.h>
#include <time.h>
#include "map/map.h"
#include "player/player.h"

int main(int argc, char const *argv[])
{
    srand( time( NULL ) );
    int x = 10;
    int y = 10;
    int zone = 1;

    int** map = initMap(x, y, zone);
    map[4][4] = 1;
    fillMap(map, x, y, zone);
    zone += 1;
    displayMap(map, x, y);

    printf("\n\n");
    x += 2;
    y += 2;
    int** map2 = initMap(x, y, zone);
    fillMap(map2, x, y, zone);
    zone += 1;
    displayMap(map2, x, y);

    printf("\n\n");

    x += 2;
    y += 2;
    int** map3 = initMap(x, y, zone);
    fillMap(map3, x, y, zone);
    displayMap(map3, x, y);
    printf("bonjour\n");
    item** item_list = createItemList();
    player* my_player = initPlayer(item_list);
    printf("%s", my_player->inventory->inventory_content[0]->type);

    appendRessourceDeCraft(item_list, 6, my_player->inventory);
    my_player->inventory->inventory_content[4]->quantity = 20;
    return 0;
}