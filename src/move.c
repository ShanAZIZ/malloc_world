//
// Created by arman on 30/10/2021.
//
#include "move.h"

void checkCanMove(Game *game, int choice) {
    if (choice == 1) {
        if (game->player->posX == 0) {
            printf("pas possible");
        } else {
            move(game, game->player->posX - 1, game->player->posY);
        }
    } else if (choice == 2) {
        if (game->player->posY == game->maps[9][game->player->mapId / 3][1] - 1) {
            printf("pas possible");
        } else {
            move(game, game->player->posX, game->player->posY + 1);
        }
    } else if (choice == 3) {
        if (game->player->posX == game->maps[9][game->player->mapId / 3][0] - 1) {
            printf("pas possible");
        } else {
            move(game, game->player->posX + 1, game->player->posY);
        }
    } else if (choice == 4) {
        if (game->player->posY == 0) {
            printf("pas possible");
        } else {
            move(game, game->player->posX, game->player->posY - 1);
        }
    }
}

int checkInInventory(Player *player, int itemId) {
    for (int x = 0; x < INVENTORY_SIZE; x += 1) {
        if (player->inventory->inventoryContent[x]->value == itemId && player->inventory->inventoryContent[x]->durability > 0) {
            player->inventory->inventoryContent[x]->durability = player->inventory->inventoryContent[x]->durability * (0.9 - 0.1 * (player->mapId / 3));
            printf("Your %s now has %d durability\n", player->inventory->inventoryContent[x]->name, player->inventory->inventoryContent[x]->durability);
            return x;
        }
    }
    return -1;
}

int collectStone(Game *game, int posX, int posY) {
    if (game->maps[game->player->mapId][posX][posY] == 4) {
        if (checkInInventory(game->player, 2) != -1 || checkInInventory(game->player, 12) != -1 || checkInInventory(game->player, 23) != -1) {
            appendRessourceDeCraft(game->itemList, 6, game->player->inventory);
            printf("1 %s added to the inventory\n", game->itemList[6]->name);
            return 1;
        }
    } else if (game->maps[game->player->mapId][posX][posY] == 7) {
        if (checkInInventory(game->player, 12) != -1 || checkInInventory(game->player, 23) != -1) {
            appendRessourceDeCraft(game->itemList, 17, game->player->inventory);
            printf("1 %s added to the inventory\n", game->itemList[17]->name);
            return 1;
        }
    } else if (game->maps[game->player->mapId][posX][posY] == 10) {
        if (checkInInventory(game->player, 23) != -1) {
            appendRessourceDeCraft(game->itemList, 28, game->player->inventory);
            printf("1 %s added to the inventory\n", game->itemList[28]->name);
            return 1;
        }
    }
    return -1;
}

int collectWood(Game *game, int posX, int posY) {
    if (game->maps[game->player->mapId][posX][posY] == 5) {
        if (checkInInventory(game->player, 4) != -1 || checkInInventory(game->player, 14) != -1 || checkInInventory(game->player, 24) != -1) {
            appendRessourceDeCraft(game->itemList, 5, game->player->inventory);
            printf("1 %s added to the inventory\n", game->itemList[5]->name);
            return 1;
        }
    } else if (game->maps[game->player->mapId][posX][posY] == 8) {
        if (checkInInventory(game->player, 13) != -1 || checkInInventory(game->player, 24) != -1) {
            appendRessourceDeCraft(game->itemList, 16, game->player->inventory);
            printf("1 %s added to the inventory\n", game->itemList[16]->name);
            return 1;
        }
    } else if (game->maps[game->player->mapId][posX][posY] == 11) {
        if (checkInInventory(game->player, 24) != -1) {
            appendRessourceDeCraft(game->itemList, 27, game->player->inventory);
            printf("1 %s added to the inventory\n", game->itemList[27]->name);
            return 1;
        }
    }
    return -1;
}

int collectPlant(Game *game, int posX, int posY) {
    if (game->maps[game->player->mapId][posX][posY] == 3) {
        if (checkInInventory(game->player, 3) != -1 || checkInInventory(game->player, 13) != -1 || checkInInventory(game->player, 25) != -1) {
            appendRessourceDeCraft(game->itemList, 7, game->player->inventory);
            printf("1 %s added to the inventory\n", game->itemList[7]->name);
            return 1;
        }
    } else if (game->maps[game->player->mapId][posX][posY] == 6) {
        if (checkInInventory(game->player, 14) != -1 || checkInInventory(game->player, 25) != -1) {
            appendRessourceDeCraft(game->itemList, 18, game->player->inventory);
            printf("1 %s added to the inventory\n", game->itemList[18]->name);
            return 1;
        }
    } else if (game->maps[game->player->mapId][posX][posY] == 9) {
        if (checkInInventory(game->player, 25) != -1) {
            appendRessourceDeCraft(game->itemList, 29, game->player->inventory);
            printf("1 %s added to the inventory\n", game->itemList[29]->name);
            return 1;
        }
    }
    return -1;
}

void collectResources(Game *game, int posX, int posY) {
    if (game->maps[game->player->mapId][posX][posY] == 4 || game->maps[game->player->mapId][posX][posY] == 7 || game->maps[game->player->mapId][posX][posY] == 10) {
        if (collectStone(game, posX, posY) == 1) {
            movePlayerAddTimer(game, posX, posY, 10);
        }else{
            printf("I don't have the tool or it has no durability left");
        }
    } else if (game->maps[game->player->mapId][posX][posY] == 5 || game->maps[game->player->mapId][posX][posY] == 8 || game->maps[game->player->mapId][posX][posY] == 11) {
        if (collectWood(game, posX, posY) == 1) {
            movePlayerAddTimer(game, posX, posY, 10);
        }else{
            printf("I don't have the tool or it has no durability left");
        }
    } else if (game->maps[game->player->mapId][posX][posY] == 3 || game->maps[game->player->mapId][posX][posY] == 6 || game->maps[game->player->mapId][posX][posY] == 9) {
        if (collectPlant(game, posX, posY) == 1) {
            movePlayerAddTimer(game, posX, posY, 10);
        }else{
            printf("I don't have the tool or it has no durability left");
        }
    }
}

void findPortal(Game* game, int idPortal){
    for(int x = 0; x < game->maps[9][game->player->mapId / 3][0]; x += 1){
        for(int y = 0; y < game->maps[9][game->player->mapId / 3][1]; y += 1){
            if(game->maps[game->player->mapId][x][y] == idPortal){
                game->player->posX = x;
                game->player->posY = y;
                game->maps[game->player->mapId + 1][x][y] = 1;
                game->maps[game->player->mapId][x][y] = 1;
            }
        }
    }
}

void passPortal(Game* game, int idPortal){
    if(game->player->mapId == 0 && game->player->level >= 3){
        game->player->mapId = 3;
        findPortal(game, idPortal);
        printf("You are now on map %d, you are on the row %d and the column %d\n", 1 + game->player->mapId / 3, game->player->posX, game->player->posY);
    }else if(game->player->mapId == 6){
        game->player->mapId = 3;
        findPortal(game, idPortal);
        printf("You are now on map %d, you are on the row %d and the column %d\n", 1 + game->player->mapId / 3, game->player->posX, game->player->posY);
    }else if(game->player->mapId == 3){
        if(idPortal == -2){
            game->player->mapId = 0;
            findPortal(game, idPortal);
            printf("You are now on map %d, you are on the row %d and the column %d\n", 1 + game->player->mapId / 3, game->player->posX, game->player->posY);
        }else if(idPortal == -3 && game->player->level >= 7){
            game->player->mapId = 6;
            findPortal(game, idPortal);
            printf("You are now on map %d, you are on the row %d and the column %d\n", 1 + game->player->mapId / 3, game->player->posX, game->player->posY);
        }
    }else{
        printf("You do not have the required level, come back later.\n");
    }
}

void decrementTimers(Game* game){
    for(int x = 0; x < game->maps[9][game->player->mapId / 3][0]; x += 1) {
        for (int y = 0; y < game->maps[9][game->player->mapId / 3][1]; y += 1) {
            if(game->maps[game->player->mapId + 1][x][y] != 0){
                if(game->maps[game->player->mapId + 1][x][y] > 1){
                    game->maps[game->player->mapId + 1][x][y] = game->maps[game->player->mapId + 1][x][y] - 1;
                }else{
                    if(game->maps[game->player->mapId][x][y] != 1){
                        game->maps[game->player->mapId + 1][x][y] = 0;
                        game->maps[game->player->mapId][x][y] = game->maps[game->player->mapId + 2][x][y];
                    }
                }
            }
        }
    }
}
void move(Game* game, int posX, int posY) {
    if (game->maps[game->player->mapId][posX][posY] < 12 && game->maps[game->player->mapId][posX][posY] > 2) {
        collectResources(game, posX, posY);
    } else if (game->maps[game->player->mapId][posX][posY] == 2) {
        menuPnj(game);
    } else if (game->maps[game->player->mapId][posX][posY] == -1) {
        printf("I can't\n");
    } else if (game->maps[game->player->mapId][posX][posY] < 100 && game->maps[game->player->mapId][posX][posY] > 11) {
        menu(game->player, game->monsterList[game->maps[game->player->mapId][posX][posY]], game, posX, posY);
    } else if (game->maps[game->player->mapId][posX][posY] == -2 || game->maps[game->player->mapId][posX][posY] == -3) {
        passPortal(game, game->maps[game->player->mapId][posX][posY]);
    } else {
        game->maps[game->player->mapId][posX][posY] = 1;
        game->maps[game->player->mapId][game->player->posX][game->player->posY] = 0;
        game->player->posY = posY;
        game->player->posX = posX;
    }
}

void movePlayerAddTimer(Game *game, int posX, int posY, int timer) {
    game->maps[game->player->mapId][game->player->posX][game->player->posY] = 0;
    game->maps[game->player->mapId][posX][posY] = 1;
    game->maps[game->player->mapId + 1][posX][posY] = timer;
    game->player->posX = posX;
    game->player->posY = posY;
}