//
// Created by Audrey Divito on 15/11/2021.
//

#include "battles.h"

int hpEvolution[11] = {0, 100, 110, 130, 160, 200, 250, 300, 350, 425, 500};
int xpEvolution[11] = {0, 10, 15, 25, 30, 40, 50, 52, 58, 64, 70};

int armorChoice(Player* player) {
    int maxArmor = 0;

    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(player->inventory->inventory_content[i]->protection > maxArmor) {
            maxArmor = player->inventory->inventory_content[i]->protection;
        }
    }
    printf("Vous ferez le combat avec %d %% de protection.\n", maxArmor);
    return maxArmor;
}

void updateXP(Player* player, Monster* monster) {
    player->current_xp += monster->xp;
        if(player->current_xp >= xpEvolution[player->level]) {
            player->level += 1;
            player->current_hp = hpEvolution[player->level];
        }
}

int weaponChoice(Player* player) {
    int cpt = 0;
    int choice = 0;
    int posWeapon[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(strcmp(player->inventory->inventory_content[i]->type, "Arme") == 0 && player->inventory->inventory_content[i]->durability > 0) {
            posWeapon[cpt] = i;
            printf("Tapez %d pour prendre cette arme : %s %d %d\n", cpt, player->inventory->inventory_content[i]->name, player->inventory->inventory_content[i]->durability, player->inventory->inventory_content[i]->damage);
            cpt += 1;
        }
    }

    do {
        scanf("%d", &choice);
        if(player->inventory->inventory_content[posWeapon[choice]]->damage > 0 && player->inventory->inventory_content[posWeapon[choice]]->durability > 0) {
            break;
        }
    } while (1);

    return posWeapon[choice];
}

Monster* battle(Player* player, Monster* monster, int idWeapon) {
    monster->hp -= player->inventory->inventory_content[idWeapon]->damage;
    printf("%d\n", player->current_hp);
    player->inventory->inventory_content[idWeapon]->durability -= 1;
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
        printf("Que voulez-vous faire ?\n1 - Combattre\n2 - Utiliser des potions\n3 - Fuir\n");
        scanf("%d", &choice);
        res = roundChoices(player, copyMonster, choice, idWeapon, maxArmor);
        if(res == 1 || res == 2 || res == 3) {
            if(res == 1) {
                movePlayerAddTimer(game, posX, posY, 15);
            }
            else if(res == 2){
                printf("Effacer la sauvegarde\n");
                FILE* save_file;
                save_file = fopen("save.txt", "w");
                fclose(save_file);
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
        if(player->current_hp > 0 && monster->hp > 0) {
            monster = battle(player, monster, idWeapon);
        }

        if(monster->hp <= 0) {
            updateXP(player, monster);
            printf("Vous avez gagné %d point d'xp. Vous êtes niveau %d.\n", player->current_xp, player->level);
            return 1;
        }
        
        if(player->current_hp <= 0) {
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

    player->current_hp -= (monster->att * (1 - (0.01 * maxArmor)));
    printf("HP monstre : %d\n", monster->hp);

    return 0;
}

void usingPotion(Player* player) {
    int posPotion[3] = {-1, -1, -1};
    int choice = 0;

    if(player->current_hp < hpEvolution[player->level]) {
        for(int i = 0; i < INVENTORY_SIZE; i++) {
            if(player->inventory->inventory_content[i]->value == 15) {
                posPotion[0] = i;
            } else if(player->inventory->inventory_content[i]->value == 26) {
                posPotion[1] = i;
            } else if(player->inventory->inventory_content[i]->value == 34) {
                posPotion[2] = i;
            }
        }

        if(posPotion[0] != -1 || posPotion[1] != -1 || posPotion[2] != -1) {
            do {
                if(posPotion[0] != -1)
                    printf("Vous avez %d potions de niveau I. Appuyez sur 1 pour les utiliser.\n", player->inventory->inventory_content[posPotion[0]]->quantity);

                if(posPotion[1] != -1)
                    printf("Vous avez %d potions de niveau II. Appuyez sur 2 pour les utiliser.\n", player->inventory->inventory_content[posPotion[1]]->quantity);

                if(posPotion[2] != -1)
                    printf("Vous avez %d potions de niveau III. Appuyez sur 3 pour les utiliser.\n", player->inventory->inventory_content[posPotion[2]]->quantity);
                scanf("%d", &choice);
            } while (choice < 1 || choice > 3);

            if(choice == 1) {
                player->current_hp += 30;
                player->inventory->inventory_content[posPotion[choice - 1]]->quantity -= 1;
            } else if(choice == 2) {
                player->current_hp += 80;
                player->inventory->inventory_content[posPotion[choice - 1]]->quantity -= 1;
            } else if(choice == 3) {
                player->current_hp += 200;
                player->inventory->inventory_content[posPotion[choice - 1]]->quantity -= 1;
            }

            if(player->current_hp > hpEvolution[player->level]) {
                player->current_hp = hpEvolution[player->level];
            }
        }
    }
}