// g++ trafic-metro.cpp tableau-donnees.cpp tableau-donnees-avance.cpp tableau-lecture-csv.cpp -o trafic-metro
#include <stdexcept>
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
#include <clocale>

using namespace std;

    // Frederik Kockisch

vector<int> ctrTraficArr(vector<int> arrondissements, vector<int> trafic) {
    vector<int> result(20, 0);

    for(int i = 0; i < arrondissements.size(); i++) {
        int index = arrondissements[i] - 1;
        if(index >= 0 && index < 20) {
            result[index] += trafic[i];
        }
    }
    return result;
}

int main() { 
    vector<vector<string>> data = litTableauCSV("donnees/trafic-annuel-entrant-par-station-du-reseau-ferre-2021.csv", 11);
    vector<string> arrondissements = colonne(data, 10);
    vector<string> trafic = colonne(data, 3);

    // for(auto val: arrondissements) cerr << val << endl;

    vector<int> arrondissementsInt = conversionInt(arrondissements);
    vector<int> traficInt = conversionInt(trafic);
    vector<int> ctrTrafic = ctrTraficArr(arrondissementsInt, traficInt);

    // for(auto val: ctrTrafic) cerr << val << endl;

    int maxTrafic = indiceMax(ctrTrafic);
    cout << "En 2021, d'après les données de RATP, il y a eu le plus de trafic dans l'arrondissement " << maxTrafic + 1 << " avec " << ctrTrafic[maxTrafic] << " entrées annuelles." << endl;
}