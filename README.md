# Travail pratique 1

## Description

Ce projet est réalisé pour le cours Construction et maintenance de logiciels (INF3135) de l'automne 2020 à l'université du québec à montréal (UQAM). Ce projet est le premier livrable du cours et est à remettre au plus tard le 14 octobre 2020. 

Le but du projet tp1 est de tester les fonctions d'un autre projet à l'aide de la librairie CUnit et d'identifier les fonctions qui fonctionnent selon les intervalles données.

## Auteur

nom, prénom : Jacob-Simard, Raphaël

Code permanent : JACR26038907

## Fonctionnement

Le projet tp1 a besoin de quelques fichiers pour fonctionner.

Pour commancer, il faut s'assurer d'avoir dans le dossier racine du projets les fichers 'tcv.o' et 'tcv.h' 

On peut entrer la commande `make lib` à la console pour télécharger ces fichiers dans un dossier ./data qui va être créer losque l'on entre la commande. Il faut ensuite décompresser le dossier obtenu et déplacer les fichers vers la racine du projet. 

le fichier 'tp1.c' devrait déjà être présent mais pas l'exécutable 'tp1', il faut donc compiler le fichier 'tp1.c'.

On entre donc la commande `make` ou `make tp1` à la console pour compiler le fichier code source 'tp1.c'.

L'exécutable 'tp1' devrait maintenant être à la racine du projet et on peut l'exécuter de quelques manières : 

* `make test`

* `./tp1`

Dans les deux cas, le résultat est le même et les résultats des tests sur les fonctions sont affichés.

On peut aussi afficher uniquement le nom des fonctions qui ont réussies en entrant la commande : 

* `./tp1 | ./liste.sh`

## Contenu du projet

* README.md : Le fichier contenant les informations à propos du projet et sa présentation.

* Makefile : Le fichier contenant les raccourcis pour des commandes. Les raccourcis sont : 

  1. `make` : Exécute la première commande du fichier, dans ce cas ci, 'make tp1'.
  2. `make tp1` : Compile le fichier code source 'tp1.c' et crée l'exécutable 'tp1'.
  3. `make test` : Exécute l'exécutable 'tp1'.
  4. `make lib` : Crée le dossier ./data et y télécharge le dossier compressé contenant les dossiers 'tcv.o' et 'tcv.h'.
  5. `make clean` : Efface l'exécutable 'tp1', les fichiers terminant par .o et .h et le dossier ./data.

* liste.sh : Exécute une commande de filtrage pour afficher les fonction qui ont passées les tests de 'tp1'.

* tp1.c : Fichier de code source du projet. Contient les tests à effectuer sur les fonctions données.

* cp.txt : Contient le code permanent en majuscule.

## Références

1. [le site du cours](https://github.com/guyfrancoeur/INF3135_A2020)

## Statut

Le projet est complété.

## Autoévaluation

Je pense que j'ai bien répondu aux attentes formulées dans l'énoncé du TP1 :

1. Les tests pour les intervalles de toutes les variantes des fonctions.
2. Le Makefile avec les raccourcis demandés.
3. L'exécutable 'liste.sh'.
4. Respect des contrainte sur le code source, les fichiers à utiliser, l'environnement de développement, Git et la manière de poser des question.
5. Les fichiers demandés sont tous présents dans la bonne branche du git.
6. README.md complété.

Bien que les tests ne soient probablement pas parfaits, je pense qu'ils répondent bien aux attentes du tp comme je les ai compris et je m'accorde une note de 90% au minimum.
