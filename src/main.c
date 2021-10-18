/**
 * FILENAME: main.c
 * Made by: GROUPE 5 - AL2 
 * Projet: Malloc-World
 * Date de création: 09/10/2021
 * Dernière modification : 09/10/2021
 * Par: AZIZ Shana
 */

#include<stdio.h>
#include<stdlib.h>
#include<player.h>

int main(int argc, char const *argv[])
{
    printf("bonjour\n");
    item** item_list = createItemList();
    player* my_player = initPlayer(item_list);
    printf("%s", my_player->inventory->inventory_content[0]->type);
    return 0;
}