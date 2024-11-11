# C - Pong

Ce projet est une réimplémentation du jeu classique Pong en utilisant la bibliothèque MiniLibX (MLX). Le but de ce projet est de reproduire le gameplay original de Pong tout en respectant les contraintes de la MLX, qui offre des fonctionnalités graphiques de base.
Fonctionnalités
## Ce que fait MiniLibX

### MLX est une bibliothèque graphique minimale qui permet :
- L'ouverture d'une fenêtre,
- L'affichage de pixels individuels sur l'écran.

Cependant, elle ne fournit pas d'autres fonctionnalités avancées comme la gestion des images complexes, les sprites ou la manipulation avancée de textures.

## Ce que fait le jeu

### Avec ces outils limités, ce projet recrée :
- Les raquettes contrôlées par les joueurs, qui peuvent se déplacer de haut en bas,
- Le système de score qui compte les points lorsqu'un joueur manque la balle,
- Un écran de jeu dynamique entièrement dessiné en manipulant les pixels dans la fenêtre MLX.

## Installation

### Pour cloner et exécuter ce projet, assurez-vous d'avoir MLX installée.

    git clone https://github.com/votre-utilisateur/pong-mlx
    cd pong-mlx
    make
    ./pong

## Utilisation
- Joueur 1 : Contrôle avec les touches W et S.
- Joueur 2 : Contrôle avec les flèches Haut et Bas.
**La partie se termine lorsqu'un joueur atteint le nombre de points requis.**

## Dépendances

__MiniLibX : Assurez-vous que MLX est installé. Vous pouvez le trouver sur le dépôt officiel MiniLibX de 42.__

Notes

Le but de ce projet est de montrer comment créer un jeu simple en utilisant uniquement les outils graphiques limités fournis par MLX. Tous les éléments graphiques sont dessinés en manipulant les pixels directement, ce qui permet de se concentrer sur la logique de base du jeu et l'affichage minimaliste.
