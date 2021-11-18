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
#include <time.h>
#include "save/save.h"

int main(int argc, char const *argv[])
{
    // LOAD INITIAL OBLIGATOIRE
    item** item_list = createItemList();
    player* my_player = initPlayer(item_list);

    // LOAD DE LA MAP
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

    // TESTS
    //printf("%s", my_player->inventory->inventory_content[0]->type);

    appendRessourceDeCraft(item_list, 6, my_player->inventory);
    my_player->inventory->inventory_content[4]->quantity = 20;
    storage* tempStorage = initTempStorage(item_list);
    //saveMap(map, map2, map3, 10, 10);
    //savePlayer(my_player, tempStorage);
    loadMapZone(map, 1, 10, 10);
    displayMap(map, 10, 10);
    loadPlayer(my_player, item_list, tempStorage);
    printf("storage first qty : %d \n", tempStorage->item->quantity);
    printf("second value: %d \n", tempStorage->next->item->value);
    printf("level : %d \n", my_player->level);
    printf("Inventory at index 4 quantity: %d \n", my_player->inventory->inventory_content[4]->quantity);
    printf("Inventory at index 4 name: %s \n", my_player->inventory->inventory_content[4]->name);

    //ladMapZone(map, 2, 10,10);o

    return 0;
}