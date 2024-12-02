---
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
kernelspec:
  display_name: Python 3 (ipykernel)
  language: python
  name: python3
---

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "396e8c77d147f33aa4aeec946c34736f", "grade": false, "grade_id": "cell-415f04d27b610548", "locked": true, "schema_version": 3, "solution": false, "task": false}}

# Partie 2 : des requêtes plus difficiles

Dans cette partie, on va effectuer des manipulations de données plus compliquées, se rapprochant de ``vraies'' requêtes sur des bases de données (mais de façon beaucoup moins efficace !).

**Note :** cette partie est indépendante de la [partie 3](partie-3.md)

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "39b9cc72cc5afe78407608932ed0c224", "grade": false, "grade_id": "cell-f8a8c0cf61076ab1", "locked": true, "schema_version": 3, "solution": false, "task": false}}

:::{admonition} Exercice 6 

On cherche à effectuer des requêtes (c'est à dire des interrogations et
sélections de données) plus complexes sur les tableaux de données.

1.  Complétez les fonctions `chercheIndice` et `distinct` du fichier
    [](tableau-donnees-avance.cpp). La documentation se trouve dans
    [](tableau-donnees-avance.hpp) et les tests dans
    [](tableau-donnees-avance-test.cpp). Vous pouvez compiler le fichier
    avec la commande `make tableau-donnees-avance-test`.

    **Indication :** la fonction `distinct` permet de récupérer une
    colonne du tableau de données en supprimant les doublons : par
    exemple, on peut obtenir les années qui apparaissent dans le
    fichier, ou les prénoms différents, etc. Pour cela, on lira le
    tableau ligne par ligne, et on utilisera la fonction `chercheIndice`
    pour savoir si l'élément a déjà été ajouté au tableau à renvoyer.

2.  Complétez la fonction `conversionDouble` en vous inspirant du
    fonctionnement de `conversionInt` donné dans [](tableau-donnees.cpp),
    avec utilisation des string stream.

3.  On cherche à écrire une fonction classique des requêtes sur base de
    données : la fonction `groupBy`. L'idée est de calculer des sommes
    récapitulatives à partir d'une colonne, en regroupant selon des
    données qui se trouvent dans une autre colonne. Par exemple, sur le
    tableau suivant :
    
       . |   .  |    .       | .
      ---|------|------------|---
       M | 2011 | Bubulle    | 3
       F | 2012 | Bichette   | 4
       F | 2011 |  Babouche  | 7
       F | 2011 | Ziboulette | 1

    Si nous regroupons selon les années de la 2ème colonne, en sommant
    les valeurs de la dernière colonne, nous obtenons :

       .    | .  
      ------|----
       2011 | 11     
       2012 |  4      


    Complétez la fonction `groupByInt` de [](tableau-donnees-avance.cpp).
    En plus du tableau de données, cette fonction prend en paramètre :
      * les valeurs distinctes à prendre en compte pour le `groupBy`, par
        exemple `{ "2011", "2012" }` pour la somme regroupée ci dessus,
      * le numéro de la colonne d'où sont tirées les valeurs selon
        lesquelles doit se faire le regroupement, dans l'exemple ci dessus,
        le regroupement se fait selon les années qui sont dans la 2ème colonne,
        c'est à dire la colonne d'indice 1,
      * le numéro de colonne des valeurs à sommer, dans
        l'exemple ci dessus, il s'agit de la 4ème colonne, ayant pour indice 3.

    La fonction renvoie un tableau d'entier qui correspond aux sommes
    obtenues. Dans l'exemple ci dessus on obtient `{ 11, 4}`. Vous aurez besoin
    d'appeler la fonction `chercheIndice`.

    Testez votre fonction à l'aide de [](tableau-donnees-avance-test.cpp).
    Ensuite, compilez avec `make mariage-complet-3` le fichier
    [](mariage-complet-3.cpp) et vérifiez en l'exécutant que vous obtenez
    les mêmes résultats que dans `make mariage-complet-2`.

5.  En vous inspirant de l'utilisation de `distinct` et `groupBy` dans
    [](mariage-complet-3.cpp), répondez aux questions ci-dessous en
    complétant la fonction `main` de [](prenoms-tableau-avance.cpp) :

    -   Combien y-a-t il eu au total de naissances de garçons ? De
        filles ?

    -   Quelle année a-t-on eu le plus de naissances (garçons et filles
        confondus) ?

    -   Combien a-t-on de naissances en moyennes par an ?

    -   Combien y-a-t il de prénoms féminins différents ? Et masculins ?

    -   Quel est le prénom féminin le plus populaire ? masculin ?

    Pour toutes ces questions, il faudra utiliser une combinaison
    d'appels à `distinct` et / ou `groupByInt` avec parfois en plus une
    sélection `selectLignes` à effectuer. Voici les réponses que vous
    devez obtenir :

        Il y a eu 324276 naissance de garçons et 303142 naissances de filles
        L'année qui a eu le plus de naissance est : 2010 avec 33259 naissances
        En moyenne, naissent 31370 enfants par an
        Il y a eu 1466 prénoms de fille différents et 1365 prénoms de garçons
        Le prénom féminin le plus populaire est Louise avec 5175 naissances
        Le prénom masculin le plus populaire est Gabriel avec 6782 naissances

6.  Complétez la fonction `groupByDouble` et lancez les tests
    correspondants. La fonction est la même que `groupByInt` mais on
    doit maintenant fabriquer un tableau de `double`

7.  $\clubsuit$ Version avancée: éviter la duplication pour les
    fonctions `conversion` et `groupBy` en utilisant un template.

::::

```{code-cell}

```

