//
// Created by shana on 22/10/2021.
//

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
    printf("\n Bienvenue dans MALLOC WORLD");
    printf("\n Que souhaitez vous faire ? ");
    printf("\n      1. Commencer une nouvelle partie");
    printf("\n      2. Charger une partie");
    printf("\n      0. Quitter");
    printf("\n Votre choix : ")
    scanf("%d", &value);
    return value;
}

void mainMenuAction() {
    int value;
    do {
        int value = mainMenu();
        switch (value) {
            case 1:
                printf("\nDebut d'une partie ")
                newGame();
                value = 0;
                break;
            case 2:
                printf("\nChargement d'une partie ")
                value = 0;
                break;
            case 0:
                printf("\nFin, Merci ! ")
                break;
            default:
                printf("\n Choix incorrect");
        }
    }while (value != 0);
}

int newGame(){
    // Initialisation du jeu ( se fera dans un module game)
    // Affichage de la map 1
    int end; //Sera retournée par la fonction tour si le joueur decide de quitter
    do {
        end = tour(); // prendra en paramètre la map, le joueur et la liste d'item
    }while(end != 0);
    printf("\nfin du tour");
    return end;
}

int tourMenu(){
    // Afficher les coordonnées du joueur
    // Afficher l'etat du joueur ( santé etc)
    int value;
    printf("\n Que souhaitez vous faire : ");
    printf("\n      1. Effectuer une action (se deplacer, interagir avec les alentours) ");
    printf("\n      2. Mon inventaire");
    printf("\n      3. Informations sur le joueur");
    printf("\n      4. Sauvegarder la partie ");
    printf("\n      0. Terminer le tour ");
    printf("\nVotre choix : ")
    scanf("%d", &value);
    return value;
}

int tour(){
    int value;
    do {
        int value = tourMenu();
        switch (value) {
            case 1:
                printf("\nLe menu d'interaction dynamique selon l'emplacement du joueur ")
                value = 0;
                break;
            case 2:
                printf("\n Inventaire du joueur ")
                value = 0;
                break;
            case 3:
                printf("\n Informations sur le joueur ")
                break;
            case 4:
                printf("\n Sauvegarde de la partie");
                value = 0;
            case 0:
                value = 0;
            default:
                printf("\n Choix incorrect");
        }
    }while (value != 0);
    return value;
}

void start(){
    title();
    mainMenuAction();
}