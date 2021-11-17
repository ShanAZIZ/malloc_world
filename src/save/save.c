/**
 * FILENAME: save.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 27/10/2021
 * Dernière modification : 27/10/2021
 * Par: AZIZ Shana
 */

#include "save.h"

void saveMap(int** zone_1, int** zone_2, int** zone_3, int x, int y){
    //TODO: manage size differently
    FILE* map_save_file;
    map_save_file = fopen("save_map.txt", "w");
    if(map_save_file != NULL){
        fprintf(map_save_file, "=== MAP ===\n");
        fprintf(map_save_file, "-- ZONE 1 --\n");
        saveZone(map_save_file, zone_1, x, y);
        fprintf(map_save_file, "-- ZONE 2 --\n");
        saveZone(map_save_file, zone_2, x+2, y+2);
        fprintf(map_save_file, "-- ZONE 3 --\n");
        saveZone(map_save_file, zone_3, x+4, y+4);
    }
    fclose(map_save_file);
}

void saveZone(FILE* map_save_file, int** zone, int x, int y){
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            fprintf(map_save_file, "%d", zone[i][j]);
            if(j+1 != y){
                fprintf(map_save_file, " ");
            }
        }
        fprintf(map_save_file,"\n");
    }
}

void loadMapZone(int** map, int zone, int x, int y){
    FILE* map_save_file;
    map_save_file = fopen("save_map.txt", "r");
    if(map_save_file != NULL){
        char zoneStr[14];
        snprintf(zoneStr, 14, "-- ZONE %d --\n", zone); // puts string into buffer
        signed char texte[256];
        do {
            fgets(texte, 255, map_save_file);
            if(strcmp(texte,zoneStr) == 0){
                for( int i=0; i<x; i++){
                    for(int j = 0; j<y; j++){
                        fscanf(map_save_file,"%d", &map[i][j]);
                    }
                }
                break;
            }
        } while (texte != NULL);
    }
}

void savePlayer(player* player, storage* storage){
    FILE* player_save_file;
    player_save_file = fopen("save_player.txt", "w");
    if(player_save_file != NULL) {
        fprintf(player_save_file, "=== PLAYER ===\n");
        fprintf(player_save_file, "%d\n%d\n%d\n", player->level, player->current_xp, player->current_hp);
        saveInventory(player_save_file, player->inventory);
        saveStorage(player_save_file, storage);
    }
    fclose(player_save_file);
}

void saveInventory(FILE* save_file, inventory* inventory){
    fprintf(save_file, "-- INVENTORY --\n");
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        fprintf(
                save_file,
                "%d@%d@%d\n",
                inventory->inventory_content[i]->quantity,
                inventory->inventory_content[i]->value,
                inventory->inventory_content[i]->durability
                );
    }
}

void saveStorage(FILE* player_save_file, storage* storage){
    fprintf(player_save_file, "-- STORAGE --\n");
    while(storage != NULL){
        fprintf(player_save_file,"%d@%d\n", storage->item->quantity, storage->item->value);
        storage = storage->next;
    }
}

void loadPlayer(player* player, item** item_list){
    FILE* player_save_file;
    player_save_file = fopen("save_player.txt", "r");
    if(player_save_file != NULL){
        signed char texte[256];
        fgets(texte, 255, player_save_file);
        if(strcmp(texte, "=== PLAYER ===\n") == 0){
            fscanf(player_save_file, "%d\n", &player->level);
            fscanf(player_save_file, "%d\n", &player->current_xp);
            fscanf(player_save_file, "%d\n", &player->current_hp);
            loadPlayerInventory(player_save_file, player->inventory, item_list);
        }else {
            printf("Fichier invalide \n");
        }
    } else {
        printf("Impossible d'ouvrir le fichier de sauvegarder");
    }
    fclose(player_save_file);
}

void loadPlayerInventory(FILE* player_save_file, inventory* player_inventory, item** item_list){
    signed char texte[256];
    fgets(texte, 255, player_save_file);
    if(strcmp(texte, "-- INVENTORY --\n") == 0){
        int actual_value;
        int actual_quantity;
        int actual_durability;
        int i=0;
        for(; i< INVENTORY_SIZE; i++){
            fscanf(player_save_file, "%d@%d@%d\n", &actual_quantity, &actual_value, &actual_durability);
            appendItemToInventoryAtIndex(item_list, actual_value, i, player_inventory);
            player_inventory->inventory_content[i]->quantity = actual_quantity;
            player_inventory->inventory_content[i]->durability = actual_durability;
        }
    }
}

storage* initTempStorage(item** itemList){
    storage* tempStorage = malloc(sizeof(storage));
    storage* tempStorage1 = malloc(sizeof(storage));
    tempStorage->next = NULL;
    item* tempItemStored1 = malloc(sizeof(item*));
    item* tempItemStored2 = malloc(sizeof(item*));
    tempItemStored1 = getOneItem(itemList, 6);
    tempItemStored1->quantity = 10;
    tempItemStored2 = getOneItem(itemList, 8);
    tempItemStored2->quantity = 15;
    tempStorage->item = tempItemStored1;
    tempStorage->next = tempStorage1;
    tempStorage1->item = tempItemStored2;
    tempStorage1->next = NULL;
    return tempStorage;
}