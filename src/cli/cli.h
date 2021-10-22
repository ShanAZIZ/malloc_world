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
 * @return
 */
int newGame();

/**
 * Load an existing game
 * @return
 */
int loadGame();

/**
 * Play menu
 * @return
 */
int tourMenu();
/**
 * Play
 * @return
 */
int tour();

