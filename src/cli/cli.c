//
// Created by shana on 22/10/2021.
//

#include "cli.h"

void title(){
    printf("|||           ||| |||         |||      |||          |||           ||||||\n");
    printf("||||||      ||||| ||||||      |||      |||        |||  |||      |||\n");
    printf("||| |||   ||| ||| |||  |||    |||      |||       |||    |||    |||\n");
    printf("|||  ||| |||  ||| |||||||||   |||      |||        |||   |||    |||\n");
    printf("|||    |||    ||| |||    |||  |||||||| |||||||||    |||||        |||||||  \n");
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

