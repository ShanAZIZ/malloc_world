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
#include "pnj/pnj.h"

int main(int argc, char const *argv[])
{
    /*Player* player = initPlayer();
    item** itemList = createItemList();
    item* item = getOneItem(itemList, 5);
    InventoryPnj* inventory = initInventoryPnj();
    inventory = fillInventory(item, player, inventory);

    item = getOneItem(itemList, 10);
    inventory = fillInventory(item, player, inventory);

    item = getOneItem(itemList, 15);
    inventory = fillInventory(item, player, inventory);

    showInventoryContent(inventory, 0);*/

    Item** itemList = createItemList();
    Player* player = initPlayer(itemList);
    menuPnj(player);

    return 0;
}