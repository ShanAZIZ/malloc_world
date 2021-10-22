//
// Created by shana on 22/10/2021.
//

#include "cli.h"

void start(){
    title();
    mainMenuAction();
}

void newGame(){
    // Initialisation du jeu ( se fera dans un module game)
    // Affichage de la map 1
    // Ici l'enchainement des tours dans une fonction
    // Pour le moment un seul tour
    // Enchainement des tours dans une fonction
    tour(); // prendra en paramètre la map, le joueur et la liste d'item
    printf("\nfin du tour");
}

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
    printf("\nBienvenue dans MALLOC WORLD");
    printf("\nQue souhaitez vous faire ? ");
    printf("\n     1. Commencer une nouvelle partie");
    printf("\n     2. Charger une partie");
    printf("\n     0. Quitter");
    printf("\nVotre choix : ");
    scanf(" %d", &value);
    return value;
}

void mainMenuAction() {
    int value;
    do {
        value = mainMenu();
        switch (value) {
            case 1:
                printf("\nDebut d'une partie ");
                newGame();
                break;
            case 2:
                printf("\nChargement d'une partie ");
                break;
            case 0:
                printf("\nJeu stopper ! ");
                break;
            default:
                printf("\nChoix incorrect");
                break;
        }
    } while (value != 0);
}

int tourMenu(){
    printf("\n Etat du joueur a ce tour et coordonnee peut etre");
    // Afficher l'etat du joueur ( santé etc)
    int value;
    printf("\nQue souhaitez vous faire : ");
    printf("\n     1. Effectuer une action (se deplacer, interagir avec les alentours) ");
    printf("\n     2. Mon inventaire");
    printf("\n     3. Informations sur le joueur");
    printf("\n     4. Sauvegarder la partie ");
    printf("\n     0. Terminer le tour ");
    printf("\nVotre choix : ");
    scanf("%d", &value);
    return value;
}

void tour(){
    int value;
    do {
        value = tourMenu();
        switch (value) {
            case 1:
                printf("\nLe menu d'interaction dynamique selon l'emplacement du joueur ");
                value = 0;
                break;
            case 2:
                printf("\nInventaire du joueur ");
                value = 0;
                break;
            case 3:
                printf("\nInformations sur le joueur ");
                break;
            case 4:
                printf("\nSauvegarde de la partie");
                value = 0;
            case 0:
                printf("\nFin du tour");
                value = 0;
            default:
                printf("\nChoix incorrect");
        }
    }while (value != 0);
}