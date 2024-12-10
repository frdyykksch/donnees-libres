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

# Rapport de projet *Données libres*

## Auteurs

- Kockisch, Frederik, frederik.kockisch@etu-upsaclay.fr, MI-3
- Cassou, Julien, julien.cassou@etu-upsaclay.fr, MI-4

## Résumé du travail effectué

- Partie 1 :
  - Exercice 1 : Réalisé, testé, documenté par Frederik Kockisch
  - Exercice 2 : Réalisé, testé, documenté par Julien Cassou
  - Exercice 3 : Réalisé, testé, documenté par Frederik Kockisch
  - Exercice 4 : Réalisé, testé, documenté par Julien Cassou
  - Exercice 5 : Réalisé, testé, documenté par Frederik Kockisch
- Partie 2 : 
  - Exercice 6 : Réalisé, testé, documenté par Frederik Kockisch
- Partie 3 :
  - Exercice 7 : Réalisé, testé, documenté par Julien Cassou
  - Exercice 8 : Réalisé, testé, documenté par Julien Cassou / Frederik Kockisch
- Partie 4 :
  - Exercice 9 : Réalisé, testé, documenté par Julien Cassou
  - Exercice 10 : Réalisé, testé, documenté par Julien Cassou / Frederik Kockisch
  - Exercice 11 : Réalisé, testé, documenté par Frederik Kockisch
  - Exercice 12 : Réalisé, testé, documenté par Julien Cassou
  - Exercice 13 : Réalisé, testé, documenté par Frederik Kockisch
  - Exercice 14 : Réalisé, testé, documenté par Frederik Kockisch / Julien Cassou
  - Exercice 15 : Réalisé, testé, documenté Frederik Kockisch

## Démonstration

### Partie 4

#### Exercice 10

```{code-cell}
! clang++ tableau-donnees-avance.cpp tableau-donnees.cpp tableau-lecture-csv.cpp cartes.cpp -o cartes -lsfml-graphics -lsfml-window -lsfml-system -I"/SFML/include"
```

```{code-cell}
! ./cartes
```

#### Exercice 12

```{code-cell}
! clang++ tableau-donnees-avance.cpp tableau-donnees.cpp tableau-lecture-csv.cpp parapluies.cpp -o parapluies
```

```{code-cell}
! ./parapluies
```

#### Exercice 15

```{code-cell}
! clang++ main.cpp tableau-donnees-avance.cpp tableau-donnees.cpp tableau-lecture-csv.cpp -o main -I/usr/include/python3.12 -I/usr/lib/python3/dist-packages/numpy/core/include -lpython3.12
```

```{code-cell}
! ./ex15-main
```
+++

### Tout exécuté et testé

```{code-cell}
! make clean
```

```{code-cell}
! make all
```

```{code-cell}
! make test
```

## Organisation du travail

Durant ce projet, nous avons décidé de répartir le travail de manière équitable afin d’avancer le plus rapidement possible, ce qui a porté ses fruits par la suite. Nous avons consacré au total environ 25 heures à la réalisation de ce projet, comprenant l’écriture du code ainsi que la résolution des bugs apparents. Le fait de centraliser notre travail sur un dépôt GitHub nous a permis de travailler de manière plus efficace et rapide, notamment grâce à l’aide ponctuelle de ChatGPT, de vidéos YouTube ou de Stackoverflow (référencé à chaque utilisation dans le programme).

## Prise de recul

La plupart des difficultés rencontrées durant la réalisation de ce projet étaient principalement causées par une utilisation maladroite de nos fonctions (mauvais paramètres) ou par des bugs dans nos programmes. 
Nous avons notamment pu approfondir notre utilisation de la bibliothèque SFML (et autres dans le projet libre), apprendre à créer nos propres fonctions pour résoudre des problèmes de manière autonome, implémenter celles-ci dans d'autres programmes et réaliser des tests de débogage.
À l'avenir, si nous devions refaire ce type de projet, il serait avantageux de ne pas accorder trop de temps à la résolution de bugs pour y revenir à la fin, afin de perdre le moins de temps possible.
