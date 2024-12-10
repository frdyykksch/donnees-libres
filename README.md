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
+++

## Auteurs

- Kockisch, Frederik, frederik.kockisch@etu-upsaclay.fr, MI-3
- Cassou, Julien, julien.cassou@etu-upsaclay.fr, MI-4

+++

## Résumé du travail effectué

:::{admonition} Consignes

Pour chaque exercice, décrivez brièvement l'avancement de votre projet.

Exemples de réponses : «non traitée», «réalisée, documentée, testée»,
«réalisée, sauf 2.3», «réalisée mais non testée», «réalisée sauf ...
pour lequel notre programme ne compile pas» ou «pour lequel les tests
de la fonction D ne passent pas».

Décrivez plus en détail les questions difficiles. Précisez et décrivez
les applications que vous avez réalisées, les difficultés rencontrées,
les choix d'implantation que vous avez fait, etc.

En plus du rapport, la documentation de chaque fonction dans le code
devra préciser son auteur et votre degré de confiance dans
l'implantation, ainsi que les éléments factuels motivant cette
confiance: présence de tests, bogues et limitations connus, etc.

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
    
:::

+++

## Démonstration
+++

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

:::{admonition} Consignes
Décrivez en quelques phrases comment vous vous êtes organisés pour
travailler sur le projet: nombre d'heures consacrées au projet,
répartition du travail dans le binôme, moyens mis en œuvre pour
collaborer, etc. Si vous avez bénéficié d'aide (en dehors de celle de
vos enseigants), précisez le.
:::

+++

## Prise de recul

:::{admonition} Consignes
Décrivez en quelques phrases les difficultés rencontrées, ce que vous
avez appris à l'occasion du projet, le cas échéant comment vous vous y
prendriez si vous aviez à le refaire.
:::

