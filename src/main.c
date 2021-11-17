/**
 * FILENAME: main.c
 * Made by: GROUPE 5 - AL2 
 * Projet: Malloc-World
 * Date de création: 09/10/2021
 * Dernière modification : 22/10/2021
 * Par: DAILLY Armand
 */

#include <stdio.h>
#include <stdlib.h>
#include "monsters/monsters.h"

#include "battles/battles.h"

int main(int argc, char const *argv[])
{
    Item** itemList = createItemList();
    Player *player = initPlayer(itemList);
    Monster monster;
    monster = (Monster) {"Test", 50, 1, 150};

    int resFight = menu(player, monster);

    initHpByLevel(player);

    return 0;
}

/*
 *
 * Generator experience
 *  #include<math.h>
    long total = 0;
    int level;

    long tnl = 100;

    double factor = 0.95;

    int levels = 20;

    printf("%-10s|  %-13s|  %-13s\n", "Level", "Exp acquired", "Exp until next level");
    printf("-------------------------------------------\n");
    for (level = 1; level <= levels; level++)
    {
        printf("Level %2d  |  %-12ld |  %-12ld |\n", level, total, tnl);
        total += tnl;
        tnl = tnl * (1 + pow(factor, level));
    }

    return 0;
 *
 */