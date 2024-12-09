#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;
#include <clocale>

        // Julien Cassou


// compilation: g++ tableau-donnees.cpp tableau-donnees-avance.cpp tableau-lecture-csv.cpp arbres-hauteur.cpp -o arbres-hauteur
#include "tableau-donnees-avance.hpp"


    // hauteur =  8
    // genre = 11
    // espece = 12
    // nom = 15

/** Lit un tableau de donnée, et affiche le nom français, le genre et l'espèce de l'arbre le
 * plus haut de Paris **/
// Julien Cassou
// Degrès de confiance: 100% -compilation réussi -affiche bien l'arbre le plus haut de Paris
int main() {
    setlocale(LC_ALL, "fr_FR.UTF-8"); // aide de Chat GPT pour l'affichage des "é" et "ù" dans la consolle
    vector<vector<string>> t = litTableauCSV("donnees/arbresremarquablesparis.csv", 36);
    int hauteur_max = 0;
    int index_max = 0;
    vector<string> C = colonne(t, 8);
    vector<int> tableau_hauteur = conversionInt(C); 



    for (int i = 0; i < tableau_hauteur.size();  i++) {
        if (tableau_hauteur[i] > hauteur_max) {
            hauteur_max = tableau_hauteur[i];
            index_max = i;
        }
    }
    cout << "L'arbre le plus haut de Paris est un " << t[index_max][15] << " de " << hauteur_max << " mètres" << endl;
    cout << "C'est un " << t[index_max][12] << ", du genre " << t[index_max][11] << endl;
}