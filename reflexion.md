#### Réflexion pour le tp2

### 06/11/2020 première conceptualisation du logiciel

il va falloir :

* lire le stdin(fgets)
* séparer chaque ligne en section(strtok)
* sauver chaque donnée(struct? variable?)
* identifier la transaction
* valider les données
* 3 compteurs (1 par type) pour les valeurs invalides
* 3 compteurs (1 par type) pour la manifestation des erreur 
* 3 compteurs (1 par type) pour le cumul des erreur
* faire l'action découlant de la transaction
 
Les fonctions nécessaires :

* séparer les lignes et sauver les données
* identifier la transaction
* sauver les données dans la bonne structure (Union?)
* valider une structure
* détection d'erreurs pour actualiser les compteurs(1 par type?)
* calcul des moyennes d'erreurs des types
* identification des actions requises dépendant de la transaction
* affichage des sorties 

### 08/11/2020

* J'ai décidé de sauver les données dans un tableau 2d avant de le transformer en structure.
* L'identification et la validation de l'évenement se passera avec le tableau
* structure contenant les compteurs en variable globale? peut-être(je vais esseyer de trouver une autre solution)
* validation du nombre d'arguments donnés avant la création de la structure
* Une structure pour tous les types d'entrées? pas sur mais rend la création d'une fonction qui valide les entrée plus facile
* Pas sur de la taille initiale du tableau utilisé dans fgets, semble impossible de le faire variable. Je le mets à 300 pour le moment puisque un des énénement accepte un nombre potentiellement infini de "size_t".

