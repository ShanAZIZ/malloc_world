#ifndef PLAYER
#define PLAYER
#endif

#define INVENTORY_LENGHT 10

// Structures
/**
 * Struct Player
 * TODO: Ecrire la docString
 * TODO: Le joueur ne pourra avoir que 3 armes
 * TODO: Le joueur ne pourra avoir que 1 armure
 * TODO: Les ressources du craft peuvent s'empiler
 * 
 */
typedef struct Player
{
    int xp;
    int level;
    int maxHp;
    int currentHp;
    int inventory[INVENTORY_LENGHT];
}Player;


// Fonctions
/**
 * A utiliser en debut de partie
 * permet d'initialiser un joueur avec les informations minimums 
 */
Player* initPlayer();
void appendWeaponToInventory(int stuffId);
void appendArmorToInventory(int stuffId);
void appendResourceToInventory(int stuffId);
void appendToInventory(int stuffId, Player*); // Utilisera les 3 fonctions ci dessus selon le stuffId

