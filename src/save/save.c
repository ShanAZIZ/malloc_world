/**
 * FILENAME: save.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 27/10/2021
 * Dernière modification : 27/10/2021
 * Par: AZIZ Shana
 */

#include "save.h"

void saveMap(Game* game, FILE* save_file){
    //Recuperer ce qu'il y a à l'emplacement actuel du joueur sur la map source
    int temp_player_position_item = game->maps[game->player->mapId+2][game->player->posX][game->player->posY];
    //Placer le joueur sur la map mirroir
    game->maps[game->player->mapId+2][game->player->posX][game->player->posY] = 1;
    if(save_file != NULL){
        fprintf(save_file, "=== MAP ===\n");
        fprintf(save_file, "-- ZONE 1 --\n");
        saveZone(save_file, game->maps[2], game->maps[9][0][0], game->maps[9][0][1]);
        fprintf(save_file, "-- ZONE 2 --\n");
        saveZone(save_file, game->maps[5],game->maps[9][1][0], game->maps[9][1][1]);
        fprintf(save_file, "-- ZONE 3 --\n");
        saveZone(save_file,game->maps[8],game->maps[9][2][0], game->maps[9][2][1]);
    }
    //Replacer ce qu'il y a à l'emplacement actuel du joueur sur la map source
    game->maps[game->player->mapId+2][game->player->posX][game->player->posY] = temp_player_position_item;
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

void loadMap(Game* game, FILE* save_file){
    for(int i = 0; i<3; i+=1){
        loadMapZone(save_file,game->maps[i*3], i+1, game->maps[9][i][0], game->maps[9][i][1], game->player);
        fillBaseMap(game->maps[i*3], game->maps[i*3+2], game->maps[9][i][0], game->maps[9][i][1]);
    }
    game->maps[game->player->mapId][game->player->posX][game->player->posY] = 1;
}

void loadMapZone(FILE* save_file, int** map, int zone, int x, int y, Player* player){
    if(save_file != NULL){
        int value;
        char zoneStr[14];
        snprintf(zoneStr, 14, "-- ZONE %d --\n", zone); // puts string into buffer
        signed char texte[256];
        do {
            fgets(texte, 255, save_file);
            if(strcmp(texte,zoneStr) == 0){
                for( int i=0; i<x; i++){
                    for(int j = 0; j<y; j++){
                        fscanf(save_file,"%d", &value);
                        if(value !=1){
                            map[i][j] = value;
                        } else {
                            map[i][j] = 0;
                            player->posX = i;
                            player->posY = j;
                            player->mapId = (zone-1)*3;
                        }
                    }
                }
                break;
            }
        } while (texte != NULL);
    }
}

void savePlayer(FILE* save_file, Player* player, storage* storage){
    if(save_file != NULL) {
        fprintf(save_file, "=== PLAYER ===\n");
        fprintf(save_file, "{%d}\n{%d}\n{%d}\n", player->level, player->current_xp, player->current_hp);
        saveInventory(save_file, player->inventory);
        saveStorage(save_file, storage);
    }
}

void saveInventory(FILE* save_file, Inventory* inventory){
    fprintf(save_file, "-- INVENTORY --\n");
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        fprintf(
                save_file,
                "{%d}@{%d}@{%d}\n",
                inventory->inventory_content[i]->quantity,
                inventory->inventory_content[i]->value,
                inventory->inventory_content[i]->durability
                );
    }
}

void saveStorage(FILE* player_save_file, storage* storage){
    fprintf(player_save_file, "-- STORAGE --\n");
    while(storage != NULL){
        fprintf(player_save_file,"{%d}@{%d}\n", storage->item->quantity, storage->item->value);
        storage = storage->next;
    }
}

void loadPlayer(FILE* save_file, Player* player, Item** item_list, storage* storage){
    if(save_file != NULL){
        signed char texte[256];
        do {
            fgets(texte, 255, save_file);
            if(strcmp(texte, "=== PLAYER ===\n") == 0) {
                fscanf(save_file, "{%d}\n", &player->level);
                fscanf(save_file, "{%d}\n", &player->current_xp);
                fscanf(save_file, "{%d}\n", &player->current_hp);
                loadPlayerInventory(save_file, player->inventory, item_list);
                loadStorage(save_file, storage, item_list);
                break;
            }
        } while (texte!= NULL);
    } else {
        printf("Impossible d'ouvrir le fichier de sauvegarder");
    }
}

void loadPlayerInventory(FILE* player_save_file, Inventory* player_inventory, Item** item_list){
    signed char texte[256];
    fgets(texte, 255, player_save_file);
    if(strcmp(texte, "-- INVENTORY --\n") == 0){
        int actual_value;
        int actual_quantity;
        int actual_durability;
        int i=0;
        for(; i< INVENTORY_SIZE; i++){
            // TODO: User AppendWhereEmpty
            fscanf(player_save_file, "{%d}@{%d}@{%d}\n", &actual_quantity, &actual_value, &actual_durability);
            appendItemToInventoryAtIndex(item_list, actual_value, i, player_inventory);
            player_inventory->inventory_content[i]->quantity = actual_quantity;
            player_inventory->inventory_content[i]->durability = actual_durability;
        }
    }
}
void loadStorage(FILE* player_save_file, storage* storage1, Item** item_list){
    signed char texte[256];
    fgets(texte, 255, player_save_file);
    if(strcmp(texte, "-- STORAGE --\n") == 0){
        int actual_quantity;
        int actual_value;
        if(fscanf(player_save_file, "{%d}@{%d}\n", &actual_quantity, &actual_value) == 2){
            printf("actual value : %d\n", actual_value);
            storage1->item = setNewItemFromList(item_list, actual_value);
            storage1->item->quantity = actual_quantity;
            storage1->next= NULL;
        }
        while (fscanf(player_save_file, "{%d}@{%d}\n", &actual_quantity, &actual_value) == 2){
            printf("actual value : %d\n", actual_value);
            Item* tempItem = setNewItemFromList(item_list, actual_value);
            appendToStorage(storage1, tempItem);
        }
    }
}

void saveGame(Game* game, storage* storage){
    FILE* save_file;
    save_file = fopen("save.txt", "w");
    if(save_file != NULL){
        saveMap(game, save_file);
        savePlayer(save_file, game->player, storage);
    }
    fclose(save_file);
}

void loadGame(Game* game, storage* storage){
    FILE* save_file;
    save_file = fopen("save.txt", "r");
    if(save_file != NULL){
        loadMap(game, save_file);
        loadPlayer(save_file, game->player, game->itemList, storage);
    }
    fclose(save_file);
}


storage* initTempStorage(Item** itemList){
    storage* tempStorage = malloc(sizeof(storage));
    storage* tempStorage1 = malloc(sizeof(storage));
    tempStorage->next = NULL;
    Item* tempItemStored1 = malloc(sizeof(Item*));
    Item* tempItemStored2 = malloc(sizeof(Item*));
    tempItemStored1 = setNewItemFromList(itemList, 5);
    tempItemStored1->quantity = 10;
    tempItemStored2 = setNewItemFromList(itemList, 8);
    tempItemStored2->quantity = 15;
    tempStorage->item = tempItemStored1;
    tempStorage->next = tempStorage1;
    tempStorage1->item = tempItemStored2;
    tempStorage1->next = NULL;
    return tempStorage;
}

void appendToStorage(storage* storage1, Item* item){
    storage* storage2 = malloc(sizeof(storage));
    storage2->item = item;
    storage1->next = storage2;
    storage2->next = NULL;
}