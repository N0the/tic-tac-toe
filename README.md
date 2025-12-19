# Projet Tic Tac Toe - LEEDER Julien

Implémentation d'un jeu de morpion en C++ (standard C++ 20) avec deux modes de jeu :
- Joueur contre joueur
- Joueur contre IA intelligente

Vous retrouverez les explications de ce projet de morpion détaillées en quatre points

## Librairies et système d'exploitation

Ce morpion a été réalisé à l'aide de C++, avec les librairies `<cstdlib>` et `<ctime>` pour la génération de nombres aléatoires.

**Système d'exploitation testé** : Uniquement sur Windows 11.

## Organisation du code

Voici globalement l'organisation de mon code :

main.cpp : Point d'entrée du programme. Initialise les joueurs, le plateau et lance le jeu selon le mode choisi.

Player.hpp / Player.cpp : Définissent la structure Player et la fonction create_player() pour initialiser un joueur.

Board.hpp / Board.cpp : Gèrent le plateau de jeu avec createBoard() et draw_game_board(), deux fonctions qui permettent à la fois de créer un tableau 3*3 affichant les positions de manière numérique (de 1 à 9) mais également d'afficher le tableau avec des | pour délimiter les différentes cases.

Mode.hpp / Mode.cpp : Contiennent la fonction ModeJeu() pour choisir le mode de jeu, entre joueur contre joueur ou un affrontement contre l'IA...

Checker.hpp / Checker.cpp : Contiennent tous les différents "checks" réalisés pendant la partie (si la valeur entrée est bien une position du tableau, si le tableau est rempli, s'il y a une égalité ou une victoire) mais également le "check" pour l'IA améliorée ! (Pour savoir s'il y a un coup qui peut faire gagner et obtenir la position de ce coup)

Gameplay.hpp / Gameplay.cpp : Contiennent la logique de déroulement du jeu avec GamePlayMode1() pour le joueur contre joueur et GamePlayMode2() pour le joueur contre IA.

Il est à noter que tous les fichiers sont à la racine, étant donné que ce projet est assez "simple", mais qu'il faudrait bien entendu créer des sous-dossiers dans la source pour des projets de plus grande envergure.

## Améliorations

Pour ce qui est des améliorations, j'ai décidé de partir sur celle de l'IA, afin qu'elle soit capable de jouer aléatoirement tous ses coups, sauf quand il y a une possibilité de victoire pour le player ou quand elle peut gagner. J'ai donc créé une fonction qui permet de balayer le tableau tout en ajoutant un symbole à chaque case, afin de simuler une victoire, et de retourner la position du tableau si c'est le cas (Fonction CheckerWinningMove dans le fichier Checker.cpp) et de jouer le coup à la position du tableau retourné. Cela lui permet donc au final, de bloquer et de valider des victoires, ou alors de jouer aléatoirement sur les cases disponibles du tableau, le cas échéant.

## Problèmes rencontrés

Ce qui m'a le plus posé problème sur ce projet ? Je dirai l'amélioration de l'IA, je savais très bien dans l'idée ce qu'il fallait faire en termes de structure, mais j'avais pas mal de difficultés à le retranscrire en code. Il m'a fallu pas mal de temps et d'itérations (que ce soit au niveau des données affichées, ou même de données de retour) afin d'arriver à cette fonction coeur de l'amélioration.

Sinon mis à part ça, je ne pense pas avoir rencontré d'autres problèmes notables dans l'avancement du projet, ça a été surtout plusieurs phases de tests et de corrections de petites erreurs (comme des décalages entre la position affichée et celle dans le code, les conditions de victoire qui ne fonctionnaient pas à cause d'une itération en plus dans une boucle ou encore des boucles while qui ne sortaient jamais).