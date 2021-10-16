#ifndef PLAYER
#define PLAYER
#endif

#define INVENTORY_TOTAL 10

/**
 * Struct Player
 * TODO: Le joueur ne pourra avoir que 3 armes
 * TODO: Le joueur ne pourra avoir que 1 armure
 * TODO: Les ressources du craft peuvent s'empiler
 */
typedef struct Player{
    int xp;
    int level;
    int maxHp;
    int currentHp;
    int inventory[INVENTORY_TOTAL]; // Sera au definitif un array de struct "item"
}player;

/**
 * Initialise un joueur de debut de partie
 * @return
 */
player* initPlayer();

/**
 * Ajoute un objet/arme/ressource dans l'inventaire d'un joueur
 * @param stuff_id
 * @param player
 */
void appendToInventory(int stuff_id, player* player);

