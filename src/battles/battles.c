//
// Created by Audrey Divito on 15/11/2021.
//

#include "battles.h"

int hpEvolution[11] = {0, 100, 110, 130, 160, 200, 250, 300, 350, 425, 500};
int xpEvolution[11] = {0, 100, 195, 370, 687, 1246, 2210, 3834, 6511, 10830, 17655};

void initHpByLevel(Player* player) {
    player->current_hp = hpEvolution[player->level];
}

void updateXP(Player* player, Monster* monster) {
    player->current_xp += monster->xp;
    for(int i = 0; i < 11; i++) {
        if(player->current_xp >= xpEvolution[i] && player->current_xp < xpEvolution[++i]) {
            player->level = i;
            initHpByLevel(player);
        }
    }
}

Monster* battle(Player* player, Monster* monster, int round, int idWeapon) {
    if(round % 2 == 0) {
        monster->hp -= getOneItem(player->inventory->inventory_content, 0)->damage;
    } else {
        player->current_hp -= monster->att;
    }

    getOneItem(player->inventory->inventory_content, idWeapon)->durability -= 1;
    return monster;
}

int menu(Player* player, Monster* monster) {
    Monster* copyMonster = monster;
    int choice = 0;
    printf("Vous êtes arrivés sur une case Monstre. Voici ses caractéristiques :\n");
    printf("\tNom : %s\n", copyMonster->name);
    printf("\tHP : %d\n", copyMonster->hp);

    do {
        printf("Que voulez-vous faire ?\n1 - Combattre\n2 - Fuir\n");
        scanf("%d", &choice);
    } while(choice < 1 || choice > 2);

    if(choice == 1) {
        int i = 0;
        while(player->current_hp > 0 && copyMonster->hp > 0) {
            copyMonster = battle(player, copyMonster, i, 1);
            i += 1;
        }

        if(copyMonster->hp <= 0) {
            updateXP(player, copyMonster);
            printf("Vous avez gagné %d point d'xp. Vous êtes niveau %d.\n", player->current_xp, player->level);
            return 1;
        }

        // TODO case if the player lose the fight
        if(player->current_hp <= 0) {
            printf("Effacer la sauvegarde\n");
            return 2;
        }
    }
    return 0;
}