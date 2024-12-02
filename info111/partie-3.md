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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "619038ada72c8b591babd27ca9066f30", "grade": false, "grade_id": "cell-415f04d27b610548", "locked": true, "schema_version": 3, "solution": false, "task": false}}

# Partie 3 : fichiers CSV

Dans cette partie, on va traiter les fichiers tels qu'ils sont réellement distribués, en utilisant le format CSV (Comma Separated Values). C'est un format
texte répandu pour représenter des données tabulaires. D'ailleurs, vous
pouvez charger ce type de fichier directement dans un tableur, par
exemple pour vérifier à la main que vos résultats sont corrects.

Ouvrez le fichier [](donnees/donnees-test.csv) sur le serveur Jupyter (ici) et sélectionnez en haut le point virgule ";" comme `Délimiteur` pour voir apparaitre les données sous forme d'un tableur.

Fermez le fichier, puis ouvrez le en ouvrant le dossier `donnees` puis clique droit sur le fichier et `Òuvrir avec : Editeur`. Vous voyez maintenant le même fichier directement tel qu'il est sauvegardé au format texte (et tel que vous allez le lire avec C++)

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "7c8114db42e98dd2bc8a9e2253a924f2", "grade": false, "grade_id": "cell-f8a8c0cf61076ab1", "locked": true, "schema_version": 3, "solution": false, "task": false}}

:::{admonition} Exercice 7 : un premier fichier CSV

L'objectif est de reprendre l'exercice 2, mais en partant du fichier de
données tel qu'il est fourni par [opendata.paris.fr](opendata.paris.fr):
[](donnees/liste_des_prenoms.csv)

Chaque ligne de texte représente une ligne du tableau, et les cellules
sont séparées par des point-virgules. La première ligne d'un fichier CSV
est une ligne d'entête qui correspond au nom des colonnes du tableau.

1.  Consulter et essayer le programme `getline-exemple` dans [](getline-exemple.cpp). Il utilise la fonction `getline`, dont la documentation
    est donnée dans [](getline.hpp)


    Vous constaterez que cette fonction *modifie* la chaîne de caractère
    'resultat' passée en argument ! De fait, le symbole '&' indique que
    'resultat' est passé *par référence*. Vous verrez les détails au
    second semestre.

    **Attention !** Vous remarquez que le fichier csv contient deux
    colonnes avec des nombres "Nombre prénoms déclarés" et "Nombre total
    cumule par annee". Ces nombres sont les mêmes presque tout le temps
    (mais pas tout le temps !) et surtout on comprend mal à quoi
    correspond la différence. On se basera sur le nombre en dernière
    colonne pour nos calculs. Vous voyez ainsi que les données réelles
    sont rarement parfaites et parfaitement formatées !

2.  À l'aide de la fonction `getline`, implanter le programme
    [](prenoms-csv.cpp) et qui fait le même calcul que [](prenoms.cpp) mais
    à partir du fichier CSV.

    **Remarque :** pour vos tests et le debuggage, vous pouvez utiliser
    le fichier [](donnees/donnees-test.csv) qui utilise le même format
    mais avec moins de données.

:::

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "06d85039536752cee4fd4cd222c91a7a", "grade": false, "grade_id": "cell-769ecf309b89159a", "locked": true, "schema_version": 3, "solution": false, "task": false}}

:::{admonition} Exercice 8 : généralisation

L'objectif de cet exercice est d'ajouter à notre bibliothèque des
fonctionnalités génériques pour les fichiers CSV. On implantera les
fonctions dans [](tableau-lecture-csv.cpp) . Des tests sont fournis dans
[](tableau-lecture-csv-test.cpp)

1.  Complétez la fonction `litTableauCSV(string nom_fichier, int nb_colonnes)` du fichier
    [](tableau-lecture-csv.cpp) dont la documentation est donnée dans
    [](tableau-lecture-csv.hpp) et lancez les tests correspondant dans
    [](tableau-lecture-csv-test.cpp)


    Si vous êtes vraiment bloqués, vous pouvez copier-coller
    l'implantation fournie dans le fichier
    [](en_cas_d_urgence_briser_la_glace.cpp). On vous demandera tout de
    même de savoir expliquer comment elle marche!

3.  $\clubsuit$ Même chose, mais sans avoir besoin de spécifier le
    nombre de colonnes


:::

```{code-cell}

```

