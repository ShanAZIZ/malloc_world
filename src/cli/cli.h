/**
 * FILENAME: main.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 09/10/2021
 * Dernière modification : 09/10/2021
 * Par: AZIZ Shana
 */

#ifndef MALLOC_WORLD_CLI_H
#define MALLOC_WORLD_CLI_H

#endif //MALLOC_WORLD_CLI_H

#include<stdio.h>
#include<stdlib.h>

/**
 * Entry point of the CLI
 */
void start();


/**
 * Main game title
 */
void title();

/**
 * Main menu of the game
 * used in mainMenuAction()
 */
int mainMenu();

/**
 * Action after user choice
 */
void mainMenuAction();

/**
 * Launch a new game
 */
void newGame();

/**
 * Play menu
 * @return Int
 */
int tourMenu();
/**
 * Play
 */
void tour();
