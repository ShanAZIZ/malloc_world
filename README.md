# Malloc World README
*Groupe 5 - AL2*
## Description 

## Installation - Compilation

### En invite de commande : 

Pour compiler le projet utiliser la commande suivante en vous plaçant sur le repository :
```
gcc .\src\*.c -o .\bin\malloc_world.exe -I.\src\include
```
Pour executer le projet : 
1. Placer vous dans le répertoire contenant l'éxecutable du projet :
```
cd ./bin
```
2. Lancer la commande 
```
./malloc_world.exe
```

### Avec SDL : 

Pour compiler le projet utiliser la commande suivante en vous plaçant sur le repository :

```
gcc src/*.c -o bin/malloc_world_with_SDL -I src/include -I ext/SDL2/include -L ext/SDL2/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
```

Si vous le souhaitez, vous pouvez également utiliser le fichier CMakeLists.txt avec CMake ou 
dans un IDE tel que CLion.



