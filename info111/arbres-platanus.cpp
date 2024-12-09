#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;
#include <clocale>

/** Affiche le nombre d'arbres du genre Platanus, et le nombre d'espèces
 *  différentes pour ce genre Platanus, parmi les "arbres remarquables"
 **/
// Julien Cassou
// Degrès de confiance: 100% -compilation réussi -affiche bien le nombre d'arbres du genre Platanus, 
// et le nombre d'espèces différentes
int main() {
    setlocale(LC_ALL, "fr_FR.UTF-8"); // aide de Chat GPT pour l'affichage des "é" et "è" dans la consolle
    vector<vector<string>> t = litTableauCSV("donnees/arbresremarquablesparis.csv", 36);
    vector<string> C = colonne(t, 11);
    //nb de ligne contenant Platanus à la colonne 11 dans le fichier
    vector<vector<string>> p = selectLignes(t, 11, "Platanus");
    int nb_platanus = p[0].size();
    vector<string> especes = distinct(p, 12);
    cout << "Il y a " << nb_platanus << " arbres de genre Platanus et " << especes.size() << " espèces différentes." << endl;
}

