/**
 * FILENAME: main.c
 * Made by: GROUPE 5 - AL2 
 * Projet: Malloc-World
 * Date de création: 09/10/2021
 * Dernière modification : 12/10/2021
 * Par: AZIZ Shana
 */

#include<stdio.h>
#include<stdlib.h>
#include "map/map.h"

int main(int argc, char const *argv[])
{
    int** map = createMap(10, 10);
    displayMap(map, 10, 10);
    return 0;
}