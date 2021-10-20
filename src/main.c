/**
 * FILENAME: main.c
 * Made by: GROUPE 5 - AL2 
 * Projet: Malloc-World
 * Date de création: 09/10/2021
 * Dernière modification : 09/10/2021
 * Par: AZIZ Shana
 */

#include<stdio.h>
#include<stdlib.h>
#include "items/items.h"

int main(int argc, char const *argv[]) {
    item **test = createItemList();
    item *temp = getOneItem(test, 34);

    for (int i = 1; i < 35; i++) {
        printf("%p | %d | %s | %s | %d | %d | %d | %d\n", test[i], test[i]->value, test[i]->name,
               test[i]->type, test[i]->damage, test[i]->durability, test[i]->quantity,
               test[i]->protection);
    }
    printf("\n\n%p | %d | %s | %s | %d | %d | %d | %d", temp, temp->value, temp->name,
           temp->type, temp->damage, temp->durability, temp->quantity, temp->protection);
    printf("\n\n%p", &temp->name);
    return 0;
}