---
jupytext:
  cell_metadata_filter: all,-autoscroll,-collapsed,-scrolled,-trusted,-ExecuteTime,-jp-MarkdownHeadingCollapsed,-user_expressions,-execution
  main_language: python
  notebook_metadata_filter: -all
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
---

Barème
======

Remarque: l'ensemble du barème ci-dessous s'applique **uniquement** si
l'enseignant juge que le travail présenté a été réalisé de façon honnête
individuellement ou en binôme. Il est légitime de dire « je n'ai pas
écrit cette ligne de code moi même », « je me suis fait aider mais je ne
comprends pas exactement ce qu'elle fait », mais seulement de façon
ponctuelle et exceptionnelle. Voilà des situations non légitimes et
leurs conséquences:

-   Le binôme s'est fait tellement "aider" (par des personnes réelles
    ou par une intelligence artificielle) que le code n'est plus le
    sien, mais il le reconnaît lors de la soutenance: la note est
    baissée au niveau de ce qu'ont vraiment réalisé les étudiants par
    eux-même (passant par exemple de "B" à "C", "D" ou "E" sur une
    partie ou l'ensemble du projet).

-   Le binôme présente un projet dont tout ou partie est plagiée
    d'autres auteurs (ou d'un système d'intelligence artificielle).
    Ce cas, beaucoup plus grave sera discuté au niveau de l'unité
    d'enseignement. Considéré comme de la fraude, cela peut
    avoir des conséquences graves sur l'ensemble des études des
    étudiants concernés.

+++

## Projet général -- 5 points


 Note          |  Description                                                                   
---------------|---------------------------------------------------------------------
 A (5 point)   | Le projet compile tout de suite. La présentation est bien menée et les parties présentées s'exécutent sans problème. Le code est écrit lisiblement et commenté quand c'est nécessaire. Le rapport est présent et complet. 
 B (4 points)  | Tous les éléments sont là mais de moindre qualité. Par exemple: la présentation est un peu confuse, il y a des bugs "non prévus" au moment de présenter, le code n'est pas toujours bien indenté, il manque certains éléments dans le rapport.
 C (2 points)  | Certains éléments sont complètement manquants, par exemple: pas de rapport du tout, ou alors il y a un rapport mais le code ne compile pas.
 D (1 point)   | Le code est écrit mais ne compile pas et il n'y a pas de rapport.
 E (0)         |  Pas de projet !

+++

## Début de la partie 1 : premières lectures -- 5 points

Exercices 1 à 4 : [](mariage-total.cpp), [](mariage-samedi.cpp), [](prenoms.cpp),
[](mariage-complet.cpp), [](prenoms-tableau.cpp)

**Remarque :** cette partie n'est pas nécessaire pour la suite, les étudiants qui ont fait directement la bibliothèque (et pour qui ça fonctionne) se font aussi attribuer les points

 Note          |  Description                                                                   
---------------|---------------------------------------------------------------------
 A (5 points)  | Les 5 fichiers des exercices compilent et s'exécutent sans erreur et contiennent les fonctions demandées. Les étudiants répondent aux questions posées sur le code et sont capables d'expliquer leurs choix d'implantation. (on accepte aussi que `prenoms-tableau.cpp` soit réalisé sans `prenoms.cpp`)
 B (4 points)  | Les fichiers `mariage-total.cpp`, `mariage-samedi.cpp`, `prenoms.cpp` compilent, s'exécutent et donnent les résultats attendus. Les 2 autres ont été réalisés en partie mais ne fonctionnent pas correctement. Ou alors tout a été fait mais les étudiants ne sont pas très clairs dans leurs réponses ou il y a des petits problèmes d'exécution.
 C (2 points)  | Il y a des problèmes sur les 3 premiers fichiers et le reste n'a pas été fait ou de façon très incomplète.
 D (1 point)   | Un seul des fichiers ou moins a été réalisé.
 E (0)         | Aucune réalisation pour cette partie.

+++

## Fin partie 1 : petite bibliothèque -- 2 points

Exercice 5 :  [](tableau-donnees.cpp),  [](tableau-donnees-test.cpp), [](tableau-lecture.cpp),
[](tableau-lecture-test.cpp), [](prenoms-tableau-2.cpp), [](mariage-complet-2.cpp)

 Note            |  Description                                             
-----------------|---------------------------------------------------------------------
 A (2 points)    | Tous les fichiers compilent et s'exécutent sans problème. Les tests de `tableau-donnees-test.cpp` et `tableau-lecture-test.cpp` passent et on obtient les résultats demandés. L'exécution de `prenoms-tableau-2.cpp`  et `mariage-complet-2.cpp`donne le résultat attendu.
  B (1 points)   |     Les fichiers `tableau-donnees.cpp` et `tableau-donnees-test.cpp` ainsi que `tableau-lecture.cpp` et `tableau-lecture-test.cpp` compilent et s'exécutent. Il peut y avoir quelques erreurs sur les tests au niveau des valeurs ainsi que sur `prenoms-tableau-2.cpp` et `mariage-complet-2.cpp`.
  D (1/2 points) |   Les fichier `tableau-donnees.cpp` et `tableau-donnees-test.cpp` ou `tableau-lecture.cpp` et `tableau-lecture-test.cpp` ont été écrit mais ne fonctionnent pas: erreur de compilation ou grosse erreur d'exécution type "Erreur de segmentation".
  E (0)          |  Aucune réalisation pour cette partie.

+++

## Partie 2 : requêtes plus difficiles -- 2 points

Exercice 6 (sans les $\clubsuit$) : [](tableau-donnees-avance.cpp), [](tableau-donnees-avance-test.cpp), [](mariage-complet-3.cpp), [](prenoms-tableau-avance.cpp)

 Note            |  Description                                             
-----------------|---------------------------------------------------------------------
 A (2 points)    | Tous les fichiers compilent et s'exécutent sans problème. Les tests de `tableau-donnees-avance-test.cpp` passent et on obtient les résultats demandés. L'exécution de `prenoms-tableau-avance.cpp` donne les bonne réponses.
 B (1.5 points)  | Les fichier `tableau-donnees-avance.cpp` et `tableau-donnees-avance-test.cpp` compilent et s'exécutent. Il peut y avoir quelques erreurs sur les tests au niveau des valeurs ainsi que sur `prenoms-tableau-avance.cpp`.
 C (1 point)     | Les fichiers `tableau-donnees-avance.cpp` et `tableau-donnees-avance-test.cpp` compilent et s'exécutent sauf peut-être le GroupBy. Il manque `prenoms-tableau-avance.cpp`
  D (1/2 points) | Les fichier `tableau-donnees-avance.cpp` et `tableau-donnees-avance-test.cpp` sont écrits mais ne fonctionnent pas: erreur de compilation ou grosse erreur d'exécution type "Erreur de segmentation" sur les fonctions autres que "groupBy"
  E (0)          | Aucune réalisation pour cette partie.

+++

## Partie 3 : fichiers CSV  -- 2 points

Exercices 7 et 8 sans les $\clubsuit$ : [](prenoms-csv.cpp), [](tableau-lecture-csv.cpp) [](tableau-lecture-csv-test.cpp)

 Note            |  Description                                             
-----------------|---------------------------------------------------------------------
  A (2 points)   |  Tous les fichiers compilent et s'exécutent sans problème. Les tests de `tableau-lecture-csv-test.cpp` passent et on obtient les résultats demandés.
  B (1.5 points) |  L'ensemble des fichiers a été réalisé mais avec de il y a des problèmes d'exécution / compilation sur certains d'entre eux (par exemple: les tests de la bibliothèque générique ne passent pas). 
  C (1 point)    |  Seul `prenom-csv.cpp` a été réalisé et fonctionne.
  D (1/2 points) |  Seul `prenom-csv.cpp` a été en partie réalisé avec quelques erreurs.
  E (0)          |  Aucune réalisation pour cette partie.

+++

## Partie 4 : applications -- 4 points

Exercices 9 à 15, questions $\clubsuit$ et autres idées

 Note            |  Description                                             
-----------------|---------------------------------------------------------------------
 A (4 points)    | Les étudiant-es ont réalisé un projet au delà des attentes. Ils et elles n'ont pas forcément réalisé "toutes" les suggestions $\clubsuit$ mais en ont fait certaines et ont travaillé sur de nombreuses applications et sur les questions "Aller plus loin".
 B (3 points)    | Au moins une question $\clubsuit$, les applications de l'exercice 9 et plusieurs autres.
 C (2 points)    | Les applications de l'exercice 9 + une question $\clubsuit$ ou d'autres applications
 D (1 point)     |  Une question $\clubsuit$ ou l'exercice 9
  E (0)          | Aucune réalisation pour cette partie.

```{code-cell}

```

