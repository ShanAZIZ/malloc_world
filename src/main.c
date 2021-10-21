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
#include "player/player.h"

int main(int argc, char const *argv[])
{
    printf("bonjour\n");
    item** item_list = createItemList();
    player* my_player = initPlayer(item_list);
    appendRessourceDeCraft(item_list, 6, my_player->inventory);
    my_player->inventory->inventory_content[4]->quantity = 20;
    appendRessourceDeCraft(item_list, 6, my_player->inventory);
    return 0;
}