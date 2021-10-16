#include "player.h"
#include <stdlib.h>
#include <stdio.h>

player * initPlayer(){
    player * mainPlayer = malloc(sizeof(player));
    mainPlayer->maxHp = 100;
    mainPlayer->currentHp = 100;
    mainPlayer->level = 1;
    for (int i = 0; i < 4; i++)
    {
        mainPlayer->inventory[i] = i+1;
    }
    return mainPlayer;
}

void appendToInventory(int stuff_id, player* player){
    // Recuperer l'objet dans ITEM
    // verifier le type de l'objet 
    // Utiliser l'append qui va bien
    for (int i = 0; i < INVENTORY_LENGHT - 1; i++)
    {
        if (player->inventory[i] == NULL)
        {
            player->inventory[i] = stuff_id;
            printf(" l'objet %d à bien été ajouter dans l'inventaire", stuff_id);
        }
        else {
           printf("Echec de l'ajout à l'inventaire car l'inventaire est plein");
        }
        
    }
    
}