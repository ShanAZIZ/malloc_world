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
    printf("\n     1. Jouer");
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
                printf("\nLancement du jeu \n");
                newGame(game);
                break;
            case 2:
                printf("\nChargement d'une partie \n");
                loadGame(game);
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
        printf("sante : %d\n", game->player->currentHp);
        printf("xp : %d\n", game->player->currentXp);
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
                saveGame(game);
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
    int done = 0;
    displayMap(game->maps[game->player->mapId], game->maps[9][game->player->mapId / 3][0],
               game->maps[9][game->player->mapId / 3][1]);
    while (done == 0 ){
        printf("1. Haut\n");
        printf("2. Droite\n");
        printf("3. Bas\n");
        printf("4. Gauche\n");
        printf("5. Passer\n");
        scanf(" %d", &input);
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
    return done;
}

void test(Game* game){
    FILE* saveFile = fopen("../resources/save.txt", "r");
    printf("\n line size %d \n", getMapWidth(saveFile, 1));
    printf("\n line height %d \n", getMapHeight(saveFile, 1));

    printf("\n line size %d \n", getMapWidth(saveFile, 2));
    printf("\n line height %d \n", getMapHeight(saveFile, 2));
    printf("\n line size %d \n", getMapWidth(saveFile, 3));
    printf("\n line height %d \n", getMapHeight(saveFile, 3));
    fclose(saveFile);
    printf("Leaving the game");
}