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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "5f4d683cde09ba0ef1f7b7c464b7f77d", "grade": false, "grade_id": "cell-415f04d27b610548", "locked": true, "schema_version": 3, "solution": false, "task": false}}

# Partie 1 : création progresive d'une bibliothèque basique

Cette partie contient 5 exercices de difficulté croissante pour comprendre la lecture et l'écriture de données dans des fichiers et aboutir à une petite bibliothèque de traitement de données.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "7db46d90f91efbf724c1119299907fb6", "grade": false, "grade_id": "cell-387923937e852735", "locked": true, "schema_version": 3, "solution": false, "task": false}}

:::{admonition} Exercice 1 : Vive les mariés !

Dans ce premier exercice, nous ferons des statistiques simples sur un
jeu de données contenant les mariages par jour de la semaine à Paris,
entre 2010 et 2015.

<https://opendata.paris.fr/explore/dataset/statistiques-des-jours-des-mariages>

Pour simplifier, nous vous fournissons dans l'archive du projet un
fichier [donnees/statistiques-des-jours-des-mariages.txt](donnees/statistiques-des-jours-des-mariages.txt)
contenant ces données dans un format texte simple: chaque ligne contient
une année, un jour de la semaine (par exemple "Lundi") et le nombre de
mariages célébrés.

1.  Dans le dossier `donnees`, ouvrez le fichier
    [](donnees/statistiques-des-jours-des-mariages.txt). **Ne le modifiez pas :
    c'est le fichier que votre programme va analyser.** Regardez et
    comprenez les informations décrites par le fichier. Par exemple, la
    première ligne indique 542 mariages célébrés un mercredi en 2012.

2.  Ouvrez le fichier [](mariage-total.cpp) et complétez la fonction
    `main` qui calcule et affiche le nombre de total de mariages
    célébrés à Paris notés dans le fichier.
    **La bonne réponse est 114 148. Vérifiez que c'est ce que
    vous obtenez.**

4.  Ouvrez le fichier [](mariage-samedi.cpp) et complétez la fonction
    `main` qui calcule et affiche le nombre de mariages célébrés un
    samedi à Paris notés dans le fichier. **vous devez trouver 63508,
    vérifiez que c'est bien le cas**.

Commencez à comppléter le [rapport](rapport.md) et vérifier que la démonstration proposée fonctionne.

:::

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f4184be76e292d272079254743ae72de", "grade": false, "grade_id": "cell-be6a76526cf27ec1", "locked": true, "schema_version": 3, "solution": false, "task": false}}

:::{admonition} Exercice 2 : Les prénoms

Sur le même site, on trouve aussi les statistiques des prénoms donnés
aux enfants nés chaque année, entre 2004 et 2023 :

<https://opendata.paris.fr/explore/dataset/liste_des_prenoms/>

Complétez le programme [](prenoms.cpp) qui demande une année à
l'utilisateur puis qui utilise le fichier simplifié fourni dans
l'archive [](donnees/liste_des_prenoms.txt)
pour calculer l'ensemble des naissances de l'année ainsi que le prénom
le plus donné. Vous devez obtenir l'affichage suivant :

    Entrez une année entre 2006 et 2021 : 2015
    En 2015, il y a eu 31970 naissances
    Le prénom le plus donné a été : Adam (donné 356 fois)

**Remarque :** si votre programme ne fonctionne pas, vous pouvez
utiliser le fichier [](donnees/donnees-test.txt) pour effectuer des tests
sur un plus petit fichier.

:::

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f9959f862fdfa0ae3bd07d06085bcfcb", "grade": false, "grade_id": "cell-dbb93dc877428542", "locked": true, "schema_version": 3, "solution": false, "task": false}}

:::{admonition} Exercice 3 : premiers tableaux

**Cet exercice n'est pas nécessaire pour la suite, si vous êtes bloqués,
passez à l'exercice d'après !**

On souhaite effectuer **dans un même programme** différents calculs sur
le nombre de mariages. Pour cela, on va traiter les données à l'aide de
tableaux.

1.  Dans le fichier [](mariage-complet.cpp), compléter la fonction
    `litTableauAnnee`. La fonction doit lire le fichier **une seule
    fois** et renvoyer un tableau de 12 cases (une pour chaque année de
    2010 à 2022) qui contiendra dans chaque case le nombre total de
    mariages pour l'année (c'est-à-dire la somme de toutes les lignes du
    fichier qui concernent cette année). L'indice d'une année est :
    `annee - 2010` (0 correspond à 2010, 1 à 2011, etc).

    Testez votre fonction en appelant `testLitTableauAnnee` dans la
    fonction `main`.

2.  Complétez la fonction `litTableauJours`. La fonction doit lire le
    fichier **une seule fois** et renvoyer un tableau de 7 cases qui
    contiendra dans chaque case le nombre de mariages pour le jour
    donné. Vous pouvez utiliser la fonction `indiceJour` pour obtenir
    l'indice du tableau correspondant à un jour en chaîne de caractères.

    Testez votre fonction en appelant `testLitTableauJours` dans la
    fonction `main`.

3.  Complétez les fonctions `somme`, `moyenne` et `indiceMax` et lancez
    les tests correspondants (en plus des tests précédents) dans la
    fonction `main`.

4.  Enfin, complétez votre programme pour que la fonction `main` appelle
    l'ensemble des tests puis effectue les calculs suivants en utilisant
    les fonctions écrites précédemment :

    -   nombre de mariages au total sur toutes les années

    -   nombre de mariages en moyenne par an

    -   l'année où l'on a célébré le plus de mariages (et le nombre de
        mariages célébrés)

    -   le jour où l'on a célébré le plus de mariages (et le nombre de
        mariages célébrés)

    -   le pourcentage de mariages célébrés le samedi.

    L'affichage doit être le suivant

        Le nombre de total de mariages célébrés entre 2010 et 2022 est de 105664
        Le nombre de mariages célébrés en moyenne par an est de 8805
        L'année où l'on a célébré le plus de mariages est 2014 avec 9866 mariages
        Le jour de la semaine où l'on a célébré le plus de mariage est le Samedi avec 63508 mariages
        Le pourcentage de mariages célébrés le samedi est de 55.6365%


:::

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "209a760d84390cc983a4dd54dd863e5f", "grade": false, "grade_id": "cell-0a172bc3bc8b4738", "locked": true, "schema_version": 3, "solution": false, "task": false}}

:::{admonition} Exercice 4 : des fonctions génériques

On souhaite à présent pouvoir analyser différents fichiers de données
sans réécrire le même code plusieurs fois. Le but est d'obtenir une
mini-bibliothèque de fonctions réutilisables.

1.  Commencez par compléter la fonction `afficheTableau` du fichier
    [](prenoms-tableau.cpp) et vérifier en appelant la fonction de test
    depuis la fonction `main`.

    La fonction doit afficher les valeurs du tableau ligne par ligne en
    les séparant par un espace :

        M 2011 Bubulle 3 
        F 2012 Bichette 4 
        F 2011 Babouche 7 
        F 2011 Ziboulette 1

2.  Dans le fichier [](prenoms-tableau.cpp), complétez la fonction
    `litTableau` qui transforme un fichier dont on connaît le nombre de
    colonnes en un tableau de données à deux dimensions (de chaînes de
    caractères). Testez votre fonction avec la fonction de test
    proposée.

    **Aide 1 :** on ne connaît pas à l'avance le nombre de lignes du
    tableau. Stratégie : faire une boucle `while(fichier)`, lire la
    ligne avec une boucle for et l'ajouter au tableau avec `push_back`
    si la lecture a fonctionné.

    **Aide 2 :** Si les tests ne passent pas, essayez à partir du
    fichier plus simple [](donnees/donnees-test.txt) et affichez le résultat avec
    `afficheTableau` pour comprendre d'où vient l'erreur.

3.  Complétez la fonction `colonne` dont la documentation est donnée.
    Testez votre fonction avec la fonction de test proposée.

4.  Copiez les fonctions `somme` et `indiceMax` que vous avez déjà
    écrites. Dans la fonction `main`, utiliser les fonctions
    `litTableau`, `colonne`, `somme` ainsi que la fonction fournie
    `conversionInt` pour afficher le nombre total de naissances
    enregistrées (627418).

5.  Complétez la fonction `selectLignes` qui permet de sélectionner et
    renvoyer des lignes d'un tableau de données, en fonction d'un
    critère sur une colonne (par exemple, pour sélectionner les lignes
    contenant un prénom donné). Testez votre fonction avec la fonction
    de test proposée.

6.  Complétez la fonction `main` pour que, en plus des tests, le
    programme demande à l'utilisateur d'entrer un prénom et affiche :

    -   le nombre total de garçons et filles à qui on a donné ce prénom

    -   l'année où le prénom a été le plus donné, et le nombre de fois
        où il a été donné cette année là.

    Remarque : si un prénom est donné à la fois à des filles et des
    garçons, cela correspondra à des lignes différentes dans le tableau,
    par exemple `"M 2012 Camille 82"` et `"F 2012 Camille 245"`.

    Voilà des exemples d'exécution du programme pour comparer avec vos
    résultats :

        Nombre total de naissances : 627418
        Choisissez un prénom : Octave
        Le prénom Octave a été donné à 966 garçons entre 2006 et 2023
        L'année la plus forte est 2021 avec 82 enfants
        Le prénom Octave n'a été donné à aucune fille entre 2006 et 2023

        Nombre total de naissances : 627418
        Choisissez un prénom : Agathe
        Le prénom Agathe n'a été donné à aucun garçon entre 2006 et 2023
        Le prénom Agathe a été donné à 1613 filles entre 2006 et 2023
        L'année la plus forte est 2017 avec 111 enfants

        Nombre total de naissances : 627418
        Choisissez un prénom : Camille
        Le prénom Camille a été donné à 1293 garçons entre 2006 et 2023
        L'année la plus forte est 2019 avec 97 enfants
        Le prénom Camille a été donné à 3949 filles entre 2006 et 2023
        L'année la plus forte est 2006 avec 287 enfants

:::

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "b7dc770a298014c48018bbce0750a397", "grade": false, "grade_id": "cell-f51bd1c97cb1774d", "locked": true, "schema_version": 3, "solution": false, "task": false}}

:::{admonition} Exercice 5 : création de la bibliothèque

Pour éviter la duplication de code, nous allons maintenant regrouper
dans différents fichiers les fonctions que nous avons écrites
précédemment, afin de créer une bibliothèque et utiliser la compilation
séparée.

1.  Compléter les fichiers [](tableau-lecture.cpp) et
    [](tableau-donnees.cpp) (avec les fonctions déjà écrites à l'exercice
    précédent). La documentation se trouve dans les fichiers
    [](tableau-lecture.hpp) et [](tableau-donnees.hpp).

2.  Compléter les tests dans [](tableau-donnees-test.cpp).

3.  Pour compiler un programme dépendant de plusieurs fichiers, on doit
    compiler chaque fichier séparément. Pour automatiser les
    compilations, on utilise un fichier `Makefile` qui permet de
    sauvegarder les dépendances de fichiers et les lignes de
    compilations associées. Lancez la commande
    `make tableau-donnees-test` dans le terminal puis exécutez le
    fichier `tableau-donnees-test` créé pour tester vos fonctions. De
    même avec `tableau-lecture-test`.

4.  Complétez le fichier [](prenoms-tableau-2.cpp) en y recopiant la
    fonction main que vous aviez déjà écrite dans [](prenoms-tableau.cpp)
    (sans les tests). Compilez le fichier avec la commande
    `make prenoms-tableau-2` puis exécutez-le. Vous devez avoir le même
    résultat que celui que vous aviez obtenu avec `prenoms-tableau`

5.  Complétez les fonctions `creeTableauAnnee` et `creeTableauJours` du\
    fichier [](mariage-complet-2.cpp). Ces fonctions sont similaires à
    `litTableauAnnee` et `litTableauxJours` mais prennent cette fois
    **un tableau de données** en entrée et non plus un fichier.

    On utilisera les fonctions `selectLignes`, `colonne` et `somme` pour
    faire les calculs : pour chaque année du tableau `annees` (ou chaque
    jour), on fera un `selectLignes` puis une somme de colonnes sur le
    tableau `data`

    **Remarque :** cette méthode n'est pas très efficace ; dans les
    exercices suivants, on écrira des meilleures fonctions.

    Testez vos fonctions en appelant les fonctions de tests dans `main`
    puis complétez la fonction `main` en reprenant les calculs et
    affichage de [](mariage-complet.cpp).

    Comme précédemment, la compilation peut se faire avec
    `make mariage-complet-2`

:::

```{code-cell} ipython3

```
