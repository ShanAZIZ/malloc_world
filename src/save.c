/**
 * FILENAME: save.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 27/10/2021
 * Dernière modification : 23/11/2021
 * Par: AZIZ Shana
 */

#include "save.h"

void saveMap(Game* game, FILE* saveFile){
    //Recuperer ce qu'il y a à l'emplacement actuel du joueur sur la map source
    int tempPlayerPositionItem = game->maps[game->player->mapId+2][game->player->posX][game->player->posY];
    //Placer le joueur sur la map mirroir
    game->maps[game->player->mapId+2][game->player->posX][game->player->posY] = 1;
    if(saveFile != NULL){
        fprintf(saveFile, "=== MAP ===\n");
        fprintf(saveFile, "-- ZONE 1 --\n");
        saveZone(saveFile, game->maps[2], game->maps[9][0][0], game->maps[9][0][1]);
        fprintf(saveFile, "-- ZONE 2 --\n");
        saveZone(saveFile, game->maps[5],game->maps[9][1][0], game->maps[9][1][1]);
        fprintf(saveFile, "-- ZONE 3 --\n");
        saveZone(saveFile,game->maps[8],game->maps[9][2][0], game->maps[9][2][1]);
    }
    //Replacer ce qu'il y a à l'emplacement actuel du joueur sur la map source
    game->maps[game->player->mapId+2][game->player->posX][game->player->posY] = tempPlayerPositionItem;
}

void saveZone(FILE* mapSaveFile, int** zone, int x, int y){
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            fprintf(mapSaveFile, "%d", zone[i][j]);
            if(j+1 != y){
                fprintf(mapSaveFile, " ");
            }
        }
        fprintf(mapSaveFile,"\n");
    }
}

void loadMap(Game* game, FILE* saveFile){
    for(int i = 0; i<3; i+=1){
        loadMapZone(saveFile,game->maps[i*3], i+1, game->maps[9][i][0], game->maps[9][i][1], game->player);
        fillBaseMap(game->maps[i*3], game->maps[i*3+2], game->maps[9][i][0], game->maps[9][i][1]);
    }
    game->maps[game->player->mapId][game->player->posX][game->player->posY] = 1;
}

void loadMapZone(FILE* saveFile, int** map, int zone, int x, int y, Player* player){
    if(saveFile != NULL){
        int value;
        char zoneStr[14];
        snprintf(zoneStr, 14, "-- ZONE %d --\n", zone); // puts string into buffer
        signed char texte[256];
        do {
            fgets(texte, 255, saveFile);
            if(strcmp(texte,zoneStr) == 0){
                for( int i=0; i<x; i++){
                    for(int j = 0; j<y; j++){
                        fscanf(saveFile,"%d", &value);
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

void savePlayer(FILE* saveFile, Game* game){
    if(saveFile != NULL) {
        fprintf(saveFile, "=== PLAYER ===\n");
        fprintf(
                saveFile,
                "{%d}\n{%d}/{%d}\n{%d}/{%d}\n",
                game->player->level,
                game->player->currentXp,
                getNextXp(game),
                game->player->currentHp,
                getNextHp(game)
                );
        saveInventory(saveFile, game->player->inventory);
        saveStorage(saveFile, game);
    }
}

void saveInventory(FILE* saveFile, Inventory* inventory){
    fprintf(saveFile, "-- INVENTORY --\n");
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        fprintf(
                saveFile,
                "{%d}@{%d}@{%d}\n",
                inventory->inventoryContent[i]->quantity,
                inventory->inventoryContent[i]->value,
                inventory->inventoryContent[i]->durability
                );
    }
}

void saveStorage(FILE* playerSaveFile, Game* game){
    fprintf(playerSaveFile, "-- STORAGE --\n");
    while(game->storage != NULL){
        fprintf(playerSaveFile,"{%d}@{%d}\n", game->storage->quantity, game->storage->objectId);
        game->storage = game->storage->next;
    }
}

void loadPlayer(FILE* saveFile, Game* game){
    if(saveFile != NULL){
        signed char texte[256];
        do {
            fgets(texte, 255, saveFile);
            if(strcmp(texte, "=== PLAYER ===\n") == 0) {
                fscanf(saveFile, "{%d}\n", &game->player->level);
                fscanf(saveFile, "{%d}\n", &game->player->currentXp);
                fscanf(saveFile, "{%d}\n", &game->player->currentHp);
                loadPlayerInventory(saveFile, game->player->inventory, game->itemList);
                loadStorage(saveFile, game);
                break;
            }
        } while (texte!= NULL);
    } else {
        printf("Impossible d'ouvrir le fichier de sauvegarder");
    }
}

void loadPlayerInventory(FILE* playerSaveFile, Inventory* playerInventory, Item** itemList){
    signed char texte[256];
    fgets(texte, 255, playerSaveFile);
    if(strcmp(texte, "-- INVENTORY --\n") == 0){
        int actualValue;
        int actualQuantity;
        int actualDurability;
        int i=0;
        for(; i< INVENTORY_SIZE; i++){
            fscanf(playerSaveFile, "{%d}@{%d}@{%d}\n", &actualQuantity, &actualValue, &actualDurability);
            appendItemToInventoryAtIndex(itemList, actualValue, i, playerInventory);
            playerInventory->inventoryContent[i]->quantity = actualQuantity;
            playerInventory->inventoryContent[i]->durability = actualDurability;
        }
    }
}
void loadStorage(FILE* playerSaveFile, Game* game){
    signed char texte[256];
    game->storage = initStorage();
    fgets(texte, 255, playerSaveFile);
    if(strcmp(texte, "-- STORAGE --\n") == 0){
        int actualQuantity;
        int actualValue;
        while (fscanf(playerSaveFile, "{%d}@{%d}\n", &actualQuantity, &actualValue) == 2){
            printf("actual value : %d\n", actualValue);
            addToStorage(game, actualValue, actualQuantity);
        }
    }
}

void saveGame(Game* game){
    FILE* saveFile;
    saveFile = fopen("..\\resources\\save.txt", "w");
    if(saveFile != NULL){
        saveMap(game, saveFile);
        savePlayer(saveFile, game);
    } else {
        printf("Echec de creation du fichier de sauvegarde 'save.txt' \n");
    }
    fclose(saveFile);
}

void loadGame(Game* game){
    FILE* saveFile;
    saveFile = fopen("..\\resources\\save.txt", "r");
    if(saveFile != NULL){
        loadMap(game, saveFile);
        loadPlayer(saveFile, game);
    } else {
        printf("Echec de l'ouverture du fichier de sauvegarde 'save.txt' \n");
    }
    fclose(saveFile);
}