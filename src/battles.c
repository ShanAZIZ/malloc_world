/**
 * FILENAME: battles.c
 * Made by: GROUPE 5 - AL2
 * Projet: Malloc-World
 * Date de création: 09/10/2021
 * Dernière modification : 24/11/2021
 * Par: DI VITO Audrey
 */

#include "battles.h"

int hpEvolution[11] = {0, 100, 110, 130, 160, 200, 250, 300, 350, 425, 500};
int xpEvolution[11] = {0, 10, 15, 25, 30, 40, 50, 52, 58, 64, 70};

int armorChoice(Player* player) {
    int maxArmor = 0;

    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(player->inventory->inventoryContent[i]->protection > maxArmor) {
            maxArmor = player->inventory->inventoryContent[i]->protection;
        }
    }
    printf("Vous ferez le combat avec %d %% de protection.\n", maxArmor);
    return maxArmor;
}

void updateXP(Player* player, Monster* monster) {
    player->currentXp += monster->xp;
        if(player->currentXp >= xpEvolution[player->level]) {
            player->level += 1;
            player->currentHp = hpEvolution[player->level];
        }
}

int weaponChoice(Player* player) {
    int cpt = 0;
    int choice = 0;
    int posWeapon[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int playerHasWeapon = 0;

    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(strcmp(player->inventory->inventoryContent[i]->type, "Arme") == 0 && player->inventory->inventoryContent[i]->durability > 0) {
            posWeapon[cpt] = i;
            printf("Tapez %d pour prendre cette arme : %s %d %d\n", cpt, player->inventory->inventoryContent[i]->name, player->inventory->inventoryContent[i]->durability, player->inventory->inventoryContent[i]->damage);
            cpt += 1;
            playerHasWeapon = 1;
        }
    }
    if(playerHasWeapon) {
        do {
            scanf("%d", &choice);
            if(player->inventory->inventoryContent[posWeapon[choice]]->damage > 0 && player->inventory->inventoryContent[posWeapon[choice]]->durability > 0) {
                break;
            }
        } while (1);
        return posWeapon[choice];
    } else {
        return -1;
    }
}

Monster* battle(Player* player, Monster* monster, int idWeapon) {
    monster->hp -= player->inventory->inventoryContent[idWeapon]->damage;
    printf("%d\n", player->currentHp);
    player->inventory->inventoryContent[idWeapon]->durability -= 1;
    return monster;
}

int menu(Player* player, Monster* monster, Game* game, int posX, int posY) {
    int idWeapon = weaponChoice(player);
    int maxArmor = armorChoice(player);

    Monster* copyMonster = malloc(sizeof(Monster));
    *copyMonster = (Monster) {monster->id, monster->name, monster->hp, monster->att, monster->def, monster->xp};
    int choice = 0;
    printf("Vous êtes arrivés sur une case Monstre. Voici ses caractéristiques :\n");
    printf("\tNom : %s\n", copyMonster->name);
    printf("\tHP : %d\n", copyMonster->hp);

    int res = 0;

    do {
        if(idWeapon == -1) {
            printf("vous n'avez plus d'arme vous ne pouvez plus vous battre\n");
            printf("Que voulez-vous faire ?\n2 - Utiliser des potions\n3 - Fuir\n");
            scanf("%d", &choice);
            if (choice == 2 || choice == 3) {
                res = roundChoices(player, copyMonster, choice, idWeapon, maxArmor);
            }
        }
        else if(player->inventory->inventoryContent[idWeapon]->durability > 0 ){
            printf("Que voulez-vous faire ?\n1 - Combattre\n2 - Utiliser des potions\n3 - Fuir\n");
            scanf("%d", &choice);
            res = roundChoices(player, copyMonster, choice, idWeapon, maxArmor);
        }
        else {
            printf("Votre arme n'as plus de durabilite,\nVeuillez choisir une nouvelle arme \n");
            idWeapon = weaponChoice(player);
        }

        if(res == 1 || res == 2 || res == 3) {
            if(res == 1) {
                movePlayerAddTimer(game, posX, posY, 15);
            }
            else if(res == 2){
                printf("Effacer la sauvegarde\n");
                FILE* saveFile;
                saveFile = fopen("../resources/save.txt", "w");
                fclose(saveFile);
                freeGame(game);
                exit(1);
            }
            break;
        }
    } while(1);

    return res;
}

int roundChoices(Player* player, Monster* monster, int choice, int idWeapon, int maxArmor) {
    int random = 0;
    if(choice == 1) {
        if(player->currentHp > 0 && monster->hp > 0) {
            monster = battle(player, monster, idWeapon);
        }

        if(monster->hp <= 0) {
            updateXP(player, monster);
            printf("Vous avez gagné %d point d'xp. Vous êtes niveau %d.\n", player->currentXp, player->level);
            return 1;
        }

        if(player->currentHp <= 0) {
            return 2;
        }
    }

    if(choice == 2) {
        usingPotion(player);
    }

    if(choice == 3) {
        srand(time(NULL));
        random = rand() % 100;

        if(random < 30) {
            printf("Vous avez fuis.");
            return 3;
        }
    }

    player->currentHp -= (monster->att * (1 - (0.01 * maxArmor)));
    printf("HP monstre : %d\n", monster->hp);

    return 0;
}

void usingPotion(Player* player) {
    int posPotion[3] = {-1, -1, -1};
    int choice = 0;

    if(player->currentHp < hpEvolution[player->level]) {
        for(int i = 0; i < INVENTORY_SIZE; i++) {
            if(player->inventory->inventoryContent[i]->value == 15) {
                posPotion[0] = i;
            } else if(player->inventory->inventoryContent[i]->value == 26) {
                posPotion[1] = i;
            } else if(player->inventory->inventoryContent[i]->value == 34) {
                posPotion[2] = i;
            }
        }

        if(posPotion[0] != -1 || posPotion[1] != -1 || posPotion[2] != -1) {
            do {
                if(posPotion[0] != -1)
                    printf("Vous avez %d potions de niveau I. Appuyez sur 1 pour les utiliser.\n", player->inventory->inventoryContent[posPotion[0]]->quantity);

                if(posPotion[1] != -1)
                    printf("Vous avez %d potions de niveau II. Appuyez sur 2 pour les utiliser.\n", player->inventory->inventoryContent[posPotion[1]]->quantity);

                if(posPotion[2] != -1)
                    printf("Vous avez %d potions de niveau III. Appuyez sur 3 pour les utiliser.\n", player->inventory->inventoryContent[posPotion[2]]->quantity);
                scanf("%d", &choice);
            } while (choice < 1 || choice > 3);

            if(choice == 1) {
                player->currentHp += 30;
                player->inventory->inventoryContent[posPotion[choice - 1]]->quantity -= 1;
            } else if(choice == 2) {
                player->currentHp += 80;
                player->inventory->inventoryContent[posPotion[choice - 1]]->quantity -= 1;
            } else if(choice == 3) {
                player->currentHp += 200;
                player->inventory->inventoryContent[posPotion[choice - 1]]->quantity -= 1;
            }

            if(player->currentHp > hpEvolution[player->level]) {
                player->currentHp = hpEvolution[player->level];
            }
        }
    }
}

int getNextHp(Game *game){
    return hpEvolution[game->player->level];
}
int getNextXp(Game* game){
    return xpEvolution[game->player->level];
}