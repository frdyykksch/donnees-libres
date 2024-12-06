// g++ emissions-co2-vehicules.cpp tableau-donnees.o tableau-lecture-csv.o tableau-donnees-avance.o -o emissions-co2-vehicules
#include <stdexcept>
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-lecture-csv.hpp"

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

int minIndex(vector<T> tab) {
        int minIndexi = 0;
}

int main() {
        vector<vector<string>> csvVoitures = litTableauCSV("donnees/emissions-co2-vehicules-mars-2014.csv", 25);
        vector<string> consoMixte = colonne(csvVoitures, 13);
        vector<double> doubleConso = conversionDouble(consoMixte);

        int maxConsoIndex = maxIndex(doubleConso);
        
        // cerr << maxConsoIndex << endl;
        cout << "La voiture polluant le plus (2014) est une " << csvVoitures[maxConsoIndex][0] << " " << csvVoitures[maxConsoIndex][3] << endl;
        cout << "Elle consomme environ " << csvVoitures[maxConsoIndex][13] << "L/100km" << endl;
}