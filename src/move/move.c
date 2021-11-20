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
        printf("%d", x);
        if (player->inventory->inventory_content[x]->value == itemId && player->inventory->inventory_content[x]->durability > 0) {
            printf("\ndura avant : %d\n", player->inventory->inventory_content[x]->durability);
            player->inventory->inventory_content[x]->durability = player->inventory->inventory_content[x]->durability * (0.9 - 0.1 * (player->mapId / 3));
            printf("\ndura après : %d\n", player->inventory->inventory_content[x]->durability);
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

void collectRessources(Game *game, int posX, int posY) {
    if (game->maps[game->player->mapId][posX][posY] == 4 || game->maps[game->player->mapId][posX][posY] == 7 || game->maps[game->player->mapId][posX][posY] == 10) {
        printf("stone\n");
        if (collectStone(game, posX, posY) == 1) {
            game->maps[game->player->mapId][game->player->posX][game->player->posY] = 0;
            game->maps[game->player->mapId][posX][posY] = 1;
            game->maps[game->player->mapId + 1][posX][posY] = 10;
            game->player->posX = posX;
            game->player->posY = posY;
        }
    } else if (game->maps[game->player->mapId][posX][posY] == 5 || game->maps[game->player->mapId][posX][posY] == 8 || game->maps[game->player->mapId][posX][posY] == 11) {
        printf("wood\n");
        if (collectWood(game, posX, posY) == 1) {
            game->maps[game->player->mapId][game->player->posX][game->player->posY] = 0;
            game->maps[game->player->mapId][posX][posY] = 1;
            game->maps[game->player->mapId + 1][posX][posY] = 10;
            game->player->posX = posX;
            game->player->posY = posY;
        }
    } else if (game->maps[game->player->mapId][posX][posY] == 3 || game->maps[game->player->mapId][posX][posY] == 6 || game->maps[game->player->mapId][posX][posY] == 9) {
        printf("plant");
        if (collectPlant(game, posX, posY) == 1) {
            game->maps[game->player->mapId][game->player->posX][game->player->posY] = 0;
            game->maps[game->player->mapId][posX][posY] = 1;
            game->maps[game->player->mapId + 1][posX][posY] = 10;
            game->player->posX = posX;
            game->player->posY = posY;
        }
    }
}

void move(Game *game, int posX, int posY) {
    if (game->maps[game->player->mapId][posX][posY] < 12 && game->maps[game->player->mapId][posX][posY] > 2) {
        collectRessources(game, posX, posY);
    } else if (game->maps[game->player->mapId][posX][posY] == 2) {
        printf("pnj\n");
    } else if (game->maps[game->player->mapId][posX][posY] == -1) {
        printf("Je ne peux pas\n");
    } else if (game->maps[game->player->mapId][posX][posY] < 100 && game->maps[game->player->mapId][posX][posY] > 11) {
        printf("monstre\n");
    } else if (game->maps[game->player->mapId][posX][posY] == -2 || game->maps[game->player->mapId][posX][posY] == -3) {
        printf("portail\n");
    } else {
        game->maps[game->player->mapId][posX][posY] = 1;
        game->maps[game->player->mapId][game->player->posX][game->player->posY] = 0;
        game->player->posY = posY;
        game->player->posX = posX;
    }
}