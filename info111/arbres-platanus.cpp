#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;

/** Affiche le nombre d'arbres du genre Platanus, et le nombre d'espèces
 *  différentes pour ce genre Platanus, parmi les "arbres remarquables"
 **/
int main() {
    vector<vector<string>> t = litTableauCSV("donnees/arbresremarquablesparis.csv", 36);
    vector<string> C = colonne(t, 11);
    //nb de ligne contenant Platanus à la colonne 11 dans le fichier
    vector<vector<string>> p = selectLignes(t, 11, "Platanus");
    int nb_platanus = p[0].size();
    vector<string> especes = distinct(p, 12);
    cout << "Il y a " << nb_platanus << "arbres de genre Platanus et" << especes.size() << "espèces différentes" << endl;
}

