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
    if(map_save_file != NULL){
        map_save_file = fopen("save_map.txt", "w");
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

void savePlayer(player* player){
    FILE* player_save_file;
    player_save_file = fopen("save_player.txt", "w");
    if(player_save_file != NULL) {
        fprintf(player_save_file, "=== PLAYER ===\n");
        fprintf(player_save_file, "%d\n%d\n%d\n", player->level, player->current_xp, player->current_hp);
        saveInventory(player_save_file, player->inventory);
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

void loadPlayer(player* player, item** item_list){
    FILE* player_save_file;
    player_save_file = fopen("save_player.txt", "r");
    if(player_save_file != NULL){
        signed char texte[256];
        fgets(texte, 255, player_save_file);
        if(strcmp(texte, "=== PLAYER ===\n") == 0){
            printf("IN THE PLAYER\n");
            fscanf(player_save_file, "%d\n", &player->level);
            fscanf(player_save_file, "%d\n", &player->current_xp);
            fscanf(player_save_file, "%d\n", &player->current_hp);
            // loadPlayerInventory(player_save_file, player->inventory, item_list);
        }else {
            printf("Fichier invalide \n");
        }
    } else {
        printf("Impossible d'ouvrir le fichier de sauvegarder");
    }
    fclose(player_save_file);
}

