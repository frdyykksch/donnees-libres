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

*Les paragraphes en italique comme celui-ci vous donnent des
indications sur le contenu attendu; ils sont à supprimer une fois
votre rapport rédigé.*

*Ce rapport pourra servir de support pour votre présentation orale.*

*Soyez objectifs et factuels! Vous ne serez pas évalué sur ce que vous
affirmez, mais sur la pertinence et la justesse de ce que vous
affirmez.*

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
  - Exercice 1 : Réalisé par Frederik Kockisch
  - Exercice 2 : Réalisé par Julien Cassou
  - Exercice 3 : Réalisé par Frederik Kockisch
  - Exercice 4 : Réalisé par Julien Cassou
  - Exercice 5 : Réalisé par Frederik Kockisch
- Partie 2 : 
  - Exercice 6 : Réalisé par Frederik Kockisch
- Partie 3 :
  - Exercice 7 : Réalisé par Julien Cassou
  - Exercice 8 : Réalisé par Julien Cassou / Frederik Kockisch
- Partie 4 :
  - Exercice 9 : Réalisé par Julien Cassou
  - Exercice 10 : Réalisé par Julien Cassou / Frederik Kockisch
  - Exercice 11 : Réalisé par Frederik Kockisch
  - Exercice 12 : Réalisé par Julien Cassou
    
:::

+++

## Démonstration

:::{consignes}

Soutenez ce que vous affirmez dans la section précédente au moyen de
quelques exemples **bien choisis**. Vous pouvez par exemple compiler
et lancer certains de vos programmes, lancer des tests, etc.

À titre d'inspiration, vous trouverez ci-dessous un début de
démonstration pour les premiers exercices.

Notez comment on lance une commande shell en la préfixant d'un point
d'exclamation (mais cela ne permet pas l'interaction avec
l'utilisateur).

Ne gardez que des exemples pertinents qui mettent en valeur votre
travail. Inutile de perdre du temps sur le premier programme si vous
avez fait les suivants plus compliqués; l'auditeur se doutera bien que
vous avez réussi à le faire.

:::

+++

### Partie 1

#### Exercice 1

```{code-cell}
! clang++ mariage-total.cpp -o mariage-total
```

```{code-cell}
! ./mariage-total
```

```{code-cell}
! clang++ mariage-samedi.cpp -o mariage-samedi
```

```{code-cell}
! ./mariage-samedi
```

#### Exercice 2

```{code-cell}
! clang++ prenoms.cpp -o prenoms
```

Executez le programme `./prenoms` dans un terminal pour tester (demande une année)

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

