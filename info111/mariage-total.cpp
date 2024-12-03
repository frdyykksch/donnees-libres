#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

        // Frederik Kockisch
        
int main() { // Frederik Kockisch
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

