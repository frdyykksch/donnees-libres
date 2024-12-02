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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "10c3c668ef98212f0082d5c1e550da05", "grade": false, "grade_id": "cell-415f04d27b610548", "locked": true, "schema_version": 3, "solution": false, "task": false}}

# Projet: données libres

## Introduction

L'objectif de ce projet est de créer des programmes de traitement de données en travaillant sur des données réelles. Le traitement de données est un aspect primordial du développement informatique actuel et il existe de nombreuses bibliothèques, architectures et algorithmes spécifiques, en particulier pour traiter les très grands volumes de données. Dans ce projet, nous verrons comment avec les simples connaissances acquises au cours de ce semestre, nous pouvons déjà aborder ces questions à notre niveau. 

## Contexte

De plus en plus d'organisations, gouvernementales ou autres, mettent
leurs données à la disposition du public, afin que celui-ci puisse se
les approprier, en trouver des utilisations nouvelles et créatives, et
aussi contrôler le fonctionnement de ces organisations sur la base de
faits concrets.

Par exemple tout un chacun peut maintenant, grâce aux [données mises en
ligne récemment par la RATP](https://data.ratp.fr/), implanter une
application adaptée à ses besoins spécifiques; par exemple qui déclenche
le réveil matin 25 minutes avant l'arrivée du RER, que celui-ci soit à
l'heure ou pas; ou d'un RER précédent en cas de gros retard annoncé sur
la ligne. D'autres données incluent le cadastre ou le [processus de
rédaction des lois à l'Assemblée
nationale](http://data.assemblee-nationale.fr/travaux-parlementaires/amendements),
etc. Le citoyen peut ainsi consulter les amendements aux projets de lois
auxquels son député a participé, et voir si ceux-ci sont conformes aux
engagements de campagne de ce dernier. Voir par exemple les actions de
l'association [Regards Citoyens](http://www.regardscitoyens.org/); et en
particulier cet
[article](https://www.regardscitoyens.org/gitlaw-how-the-law-factory-turns-the-french-parliamentary-process-into-300-version-controlled-open-data-visualizations/).

L'analyse de ce type de données a par exemple permis en janvier 2016 à
des journalistes de [mettre au jour le fait que des matchs de tennis de
l'ATP avaient été
truqués](https://www.buzzfeed.com/heidiblake/the-tennis-racket). Les
données ainsi que leurs analyses sont disponibles sur
<http://github.com/BuzzFeedNews/everything>. On y trouvera d'autres
analyses de données tels que les tremblements de terre reliés à
l'exploitation des gaz de schiste aux États-Unis, les mouvements des
donateurs de la campagne présidentielle américaine lorsqu'un candidat
sort de la course, ou une analyse du placement des enfants dans les
crèches.

Comme les données peuvent être de grande taille, en extraire des
informations intéressantes requiert la plupart du temps des traitements
automatisés. Ce projet est l'occasion de constater que vous avez dès à
présent les moyens de commencer à traiter automatiquement ce type de
données ou d'autres ! Par exemple des résultats d'expériences de
physique.

À noter: en d'autres occasions, la bonne approche serait d'utiliser des
bibliothèques existantes d'analyse de données et d'apprentissage
automatique; on peut par exemple penser à
[pandas](http://pandas.pydata.org/) et
[scikit-learn](http://scikit-learn.org/) (pour python). Pour des
traitements simples sur de petites données, un tableur suffirait.

Ici nous n'utiliserons que la bibliothèque standard de C++ (et
éventuellement la SFML / SDL pour les graphiques), quitte à réimplanter
des outils de base; en effet l'objectif pédagogique est avant tout de mettre en pratique
ce que vous avez appris dans le cours de programmation impérative et de mieux comprendre
comment fonctionnent ces outils.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "5602ea8cb305e5dbba9b4d242f948aef", "grade": false, "grade_id": "cell-f8a8c0cf61076ab1", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## Organisation du projet et difficulté des exercices

Ce projet est volontairement long afin que chacun puisse s'exprimer en
fonction de ses compétences, de son éventuelle expérience préalable et
de ses goûts. La progression dans le projet est pensée en terme
d'exercices à difficulté croissante.

La **Partie 1** est accessible à toutes et tous et **nécessaire** pour la suite du projet. Les **parties 2 et 3** sont **indépendantes**, commencez par celle que vous voulez. Elles sont cependant toutes les deux nécessaires pour réaliser la partie 4. 

* [Partie 1 : création progressive d'une bibliothèque basique](partie-1.md) (12 points)
* [Partie 2 : des requêtes plus difficiles](partie-2.md) (2 points)
* [Partie 3 : fichiers CSV](partie-3.md) (2 points)
* [Partie 4 : aller plus loin](partie-4.md) (4 points)

Voici le [barème détaillé](bareme.md)

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "da3a226619dcbedbaba1cfb18728c800", "grade": false, "grade_id": "cell-6d952c4decd8c708", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## Références

-   <http://opendata.paris.fr>

-   <http://data.gouv.fr>

-   <http://www.ideeslibres.org/>

```{code-cell} ipython3

```
