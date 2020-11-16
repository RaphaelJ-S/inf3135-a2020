# Travail pratique 1

## Description

Ce projet est réalisé pour le cours Construction et maintenance de logiciels (INF3135) de l'automne 2020 à l'université du québec à montréal (UQAM). Ce projet est le premier livrable du cours et est à remettre au plus tard le 22 novembre 2020. 

Le but du projet tp2 est de construire un logiciel qui prend les données venant de stdin (un fichier, une commande ou l'entrée manuelle) et afficher les information résultantes. Ce logiciel simule le fonctionnement d'une puce utilisée dans la détection de la COVID-19.

## Auteur

nom, prénom : Jacob-Simard, Raphaël

Code permanent : JACR26038907

## Fonctionnement

Il y a deux manière de faire fonctionner ce programme. 

* En tapant `./tp2` et en entrant les données manuellement. 

* En utilisant une pipe pour donner des données au logiciel avec, par exemple `cat data.txt | ./tp2`.

Dans les deux cas, le fichier "tp2" et ses dépendances doivent exister. Cela est réaliser avec la commande `make` ou `make tp2`

## Contenu du projet

* README.md : Le fichier contenant les informations à propos du projet et sa présentation.
* Makefile : Le fichier contenant les raccourcis pour des commandes. Les raccourcis sont : 

  1. `default` : Dépend de la commande `make tp2`.
  2. `make tp1` : Crée l'exécutable 'tp1' et ses dépendances.
  3. `make tp2` : Crée l'exécutable 'tp2' et ses dépendances.
  4. `make test-tp1a` : Exécute l'exécutable 'tp1'.
  5. `make test-tp1b` : Exécute l'exécutable 'tp1' avec liste.sh pour lister les fonctions valides.
  6. `make test-tp2` : Exécute l'exécutable 'tp2'.
  7. `make lib` : Crée le dossier ./data et y télécharge le dossier compressé contenant les fichiers 'tcv.o' et 'tcv.h'. Ensuite, décompresse le fichier télécharger dans le dossier courant.
  8. `make clean` : Efface les exécutables, les fichiers "tcv.o" et "tcv.h" et le dossier ./data.

* simple.c : Contient les fonction du tp1.
* simple.h : Contient les entetes du tp1.
* malib.c : Contient les fonctions du tp2.
* malic.h : Contient les entetes du tp2.
* tp1.c : Contient le main du tp1. 
* tp2.c : Contient le main du tp2.
* liste.sh : Exécute une commande de filtrage pour afficher les fonction qui ont passées les tests du tp1. 
* cp.txt : Contient le code permanent en majuscule.
* reflexion.md : Contient mes reflexions lors de l'écriture du tp2.
* tp2.yml: Contient des objets en notation YAML définissant les différents fichiers.

## Processus de réflexion et démarche

[reflexion](./reflexion.md)

## Références


1. [le site du cours](https://github.com/guyfrancoeur/INF3135_A2020)
2. [Le site cplusplus](https://www.cplusplus.com)
3. [Le site de GNU](https://www.gnu.org/software/make/manual/html_node/Introduction.html)

## Statut

Le projet est complété, les sorties et les calculation sont conformes aux exigences. Par contre, il y a toujours une petite fuite de mémoire.

## Autoévaluation

Je pense que j'ai bien répondu aux attentes formulées dans l'énoncé du TP2 :

* Le programme s'exécute avec les paramètres demandés.
* Les fichiers demandés sont présents.
* Les commandes make sont présentes.
* Le programme utilise les fonctions définies dans tcv.h.
* Les sorties sont conformes à l'énoncé.
* gitignore present.
