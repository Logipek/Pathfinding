# Projet de Fin de Module : Algorithme de Pathfinding

## Introduction

Ce projet a pour objectif d'implémenter un algorithme permettant de trouver le plus court chemin dans un graphe. Ce projet fait partie de l'évaluation de la première année de Coda, et se concentre sur la lecture de fichiers, l'analyse de graphes, et l'utilisation d'algorithmes de pathfinding tels que BFS, Dijkstra ou A*.

---

## Fonctionnalités

1. **Lecture de fichiers de graphe :** 
   Le programme peut lire des fichiers contenant la représentation d'un graphe sous un format spécifique (cf. [Format de fichier graphe](#format-du-fichier-graphe)).
   
2. **Initialisation du graphe :** 
   Le programme extrait les nœuds et les liens du fichier pour initialiser un graphe en mémoire.

3. **Affichage des informations du graphe :**
   - Nombre de nœuds
   - Nombre de liens
   - Nœud de départ et de fin
   - Affichage du chemin le plus court trouvé

4. **Algorithme de Pathfinding :**
   Implémentation d'un algorithme de pathfinding pour trouver le plus court chemin entre un nœud de départ et un nœud d'arrivée.

5. **Gestion des erreurs :**
   Le programme gère des erreurs telles que les fichiers non trouvés, les graphes mal formatés, et l'absence de chemin valide.

---

## Prérequis

- **Langage :** C
- **Compilateur :** GCC ou tout autre compilateur compatible C
- **Outils :** Makefile pour la compilation

---

## Instructions d'installation

1. Cloner ce dépôt GitHub :
    ```bash
    git clone https://github.com/ton-utilisateur/nom-du-repo.git
    cd nom-du-repo
    ```

2. Compiler le projet avec la commande `make` :
    ```bash
    make
    ```

   Cela générera un exécutable nommé `pathfinding`.

---

## Utilisation

Pour exécuter le programme, utilisez la commande suivante :

```bash
./pathfinding <nom_fichier_graphe>
