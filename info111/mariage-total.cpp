#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

        // Frederik Kockisch
        
/* 
 * Frederik Kockisch
 * Mariages total du fichier donné
 * Degré de confiance - 100% - Pas de bugs
*/ 

int main() {
    ifstream fichier("donnees/statistiques-des-jours-des-mariages.txt");
    string jour;
    int mariages;
    int annee;
    int total = 0;
    while ( fichier >> annee >> jour >> mariages ) {
        total += mariages;        
    }
    fichier.close();
    cout << total << endl;
}

