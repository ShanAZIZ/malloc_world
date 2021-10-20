/**
 * FILENAME: main.c
 * Made by: GROUPE 5 - AL2 
 * Projet: Malloc-World
 * Date de création: 09/10/2021
 * Dernière modification : 21/10/2021
 * Par: DAILLY Armand
 */

#include <stdio.h>
#include <stdlib.h>
#include "monsters/monsters.h"

int main(int argc, char const *argv[]) {
    Monster **monsterlist;
    monsterlist = createMonsterList();
    printf("%p | %d | %s | %u | %u | %u | %u", monsterlist[12], monsterlist[12]->id, monsterlist[12]->name,
           monsterlist[12]->hp, monsterlist[12]->att, monsterlist[12]->def, monsterlist[12]->xp);
    return 0;
}