#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/* 
 * Frederik Kockisch
 * Calcule et affiche le nombre de mariages un samedi entre 2010 et 2022
 * Degré de confiance - 100% - Pas de bugs
*/ 
int main() {
    ifstream fichier("donnees/statistiques-des-jours-des-mariages.txt");
    string jour;
    int mariages;
    int annee;
    int total = 0;
    while ( fichier >> annee >> jour >> mariages ) {
        if ( jour == "Samedi" ) {
            total += mariages;
        }
    }
    fichier.close();
    cout << total << endl;
}