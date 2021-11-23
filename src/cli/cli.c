/**
 * FILENAME: main.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 09/10/2021
 * Dernière modification : 22/11/2021
 * Par: AZIZ Shana
 */

#include "cli.h"

void title(){
    printf("|||           ||| |||         |||      |||          |||         |||||||\n");
    printf("||||||      ||||| ||||||      |||      |||        |||  |||    |||      \n");
    printf("||| |||   ||| ||| |||  |||    |||      |||       |||    |||  |||       \n");
    printf("|||  ||| |||  ||| |||||||||   |||      |||        |||   |||   |||      \n");
    printf("|||    |||    ||| |||    |||  |||||||| |||||||||    |||||       |||||||\n");
    printf("\nESGI AL GROUPE 5\n");
}

int mainMenu(){
    int value;
    printf("\nBienvenue dans le menu principal");
    printf("\nQue souhaitez vous faire ? ");
    printf("\n     1. Commencer une nouvelle partie");
    printf("\n     2. Charger une partie");
    printf("\n     3. Lancer les tests");
    printf("\n     0. Quitter");
    printf("\nVotre choix : ");
    scanf(" %d", &value);
    return value;
}

void mainMenuAction(Game* game) {
    int value;
    do {
        value = mainMenu();
        switch (value) {
            case 1:
                printf("\nDebut d'une partie \n");
                newGame(game);
                break;
            case 2:
                printf("\nChargement d'une partie \n");
                storage* tempStorage = initTempStorage(game->itemList); // A supprimer plus tard
                loadGame(game, tempStorage);
                newGame(game);
                break;
            case 3:
                printf("\nLancement des tests \n");
                test(game);
                break;
            case 0:
                printf("\nFin ! \n");
                break;
            default:
                printf("\nChoix incorrect\n");
                break;
        }
    } while (value != 0);
}


void start(Game* game){
    title();
    mainMenuAction(game);
}

void newGame(Game* game){
    int choice;
    do {
        printf("\n---- Joueur ----- \n");
        printf("niveau : %d\n", game->player->level);
        printf("sante : %d\n", game->player->current_hp);
        printf("xp : %d\n", game->player->current_xp);
        printf("position : %d | %d\n", game->player->posX, game->player->posY);
        printf("map : %d\n", game->player->mapId/3);
        printf("\n1. Jouer");
        printf("\n2. Sauvegarder la partie");
        printf("\n0. Quitter la partie");
        printf("\nVotre choix : ");
        scanf(" %d", &choice);
        switch (choice) {
            case 1:
                tourAction(game);// prendra en paramètre la map, le joueur et la liste d'item
                break;
            case 2:
                printf("\nSauvegarde..");
                storage* tempStorage = initTempStorage(game->itemList); // A supprimer plus tard
                saveGame(game, tempStorage);
                break;
            case 0:
                break;
            default:
                printf("\nChoix incorrect");
        }
    } while (choice != 0);
}

int tourMenu(){
    int value;
    printf("\nQue souhaitez vous faire : ");
    printf("\n1. Me deplacer ");
    printf("\n2. Mon inventaire");
    printf("\n0. Terminer le tour ");
    printf("\nVotre choix : ");
    scanf(" %d", &value);
    return value;
}

void tourAction(Game* game){
    int value;
    do {
        value = tourMenu();
        switch (value) {
            case 1:
                printf("\n");
                value = callMove(game);
                break;
            case 2:
                printf("\nInventaire du joueur \n");
                showPlayerInventory(game->player->inventory);
                value = 0;
                break;
            case 0:
                printf("\nFin du tour");
                value = 0;
            default:
                printf("\nChoix incorrect");
        }
    }while (value != 0);
}

int callMove(Game* game){
    int input;
    int done;
    displayMap(game->maps[game->player->mapId], game->maps[9][game->player->mapId / 3][0],
               game->maps[9][game->player->mapId / 3][1]);
    printf("1. Haut\n");
    printf("2. Droite\n");
    printf("3. Bas\n");
    printf("4. Gauche\n");
    printf("5. Passer\n");
    scanf(" %d", &input);
    if (input == 5) {
        done = 0;
    } else {
        checkCanMove(game, input);
        displayMap(game->maps[game->player->mapId], game->maps[9][game->player->mapId / 3][0],
                   game->maps[9][game->player->mapId / 3][1]);
        decrementTimers(game);
        fflush(stdin);
    }
    return done;
}

void test(Game* game){
    storage* tempStorage = initTempStorage(game->itemList); // A supprimer plus tard
    game->player->level = 3;
    displayMap(game->maps[0], game->maps[9][0][0], game->maps[9][0][1]);
    //loadMap(game);
    int done = 0;
    int input = 0;


    //saveGame(game, tempStorage);
    //loadGame(game, tempStorage);
    //loadPlayer(game->player, game->itemList, tempStorage);
    printf("first value : %d \n", tempStorage->item->value);
    printf("second value: %d \n", tempStorage->next->item->value);

    printf("level : %d \n", game->player->level);
    printf("Inventory at index 4 quantity: %d \n", game->player->inventory->inventory_content[4]->quantity);
    printf("Inventory at index 4 name: %s \n", game->player->inventory->inventory_content[4]->name);
    while (done == 0) {
        scanf("%d", &input);
        if (input == 5) {
            done = 1;
        } else {
            checkCanMove(game, input);
            displayMap(game->maps[game->player->mapId], game->maps[9][game->player->mapId / 3][0],
                       game->maps[9][game->player->mapId / 3][1]);
            decrementTimers(game);
            fflush(stdin);
        }
    }
    printf("Leaving the game");
}