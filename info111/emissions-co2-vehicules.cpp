<<<<<<< HEAD
=======
// g++ emissions-co2-vehicules.cpp tableau-donnees.o tableau-lecture-csv.o tableau-donnees-avance.o -o emissions-co2-vehicules
>>>>>>> main
#include <stdexcept>
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-lecture-csv.hpp"
<<<<<<< HEAD
using namespace std;

        // Frederik Kockisch
=======

#include "tableau-donnees-avance.hpp"
using namespace std;

        // Frederik Kockisch

template <typename T>
int maxIndex(vector<T> tab) {
        int maxIndexi = 0;
        T maxElement = tab[0];
        for(int i = 0; i < tab.size(); i++) {
                if(tab[i] > maxElement) {
                        maxElement = tab[i];
                        maxIndexi = i;
                }
        } return maxIndexi;
}

int minIndex(vector<double> tab) {
        int minIndexi = 0;
        double minElement = tab[0];
        for(int i = 0; i < tab.size(); i++) {
                if(tab[i] < minElement && !tab[i] == 0) {
                        minElement = tab[i];
                        minIndexi = i;
                }
        } return minIndexi;
}

int main() {
        vector<vector<string>> csvVoitures = litTableauCSV("donnees/emissions-co2-vehicules-mars-2014.csv", 25);
        vector<string> consoMixte = colonne(csvVoitures, 13);
        vector<double> doubleConso = conversionDouble(consoMixte);
        
        int maxConsoIndex = maxIndex(doubleConso);
        int minConsoIndex = minIndex(doubleConso);
        
        // cerr << maxConsoIndex << endl;
        cout << "La voiture polluant le plus (2014) est une " << csvVoitures[maxConsoIndex][0] << " " << csvVoitures[maxConsoIndex][3] << endl;
        cout << "Elle consomme environ " << csvVoitures[maxConsoIndex][13] << " L/100km" << endl;

        // cerr << minConsoIndex << endl;
        cout << "La voiture polluant le moins (2014) est une " << csvVoitures[minConsoIndex][0] << " " << csvVoitures[minConsoIndex][3] << endl;
        cout << "Elle consomme environ " << csvVoitures[minConsoIndex][13] << " L/100km" << endl;
}
>>>>>>> main
