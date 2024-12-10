#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-donnees.hpp"

        // Julien Cassou

void afficheTableau(vector<vector<string>> tableau) {
    for(int i = 0; i < tableau.size(); i++) {
        for(int j = 0; j < tableau[i].size(); j++) {
            cout << tableau[i][j] << " ";
        } cout << endl;
    }
}

int moyenne(vector<int> t) {
    int sommeTab = somme(t);
    return sommeTab / t.size();
}

int somme(vector<int> t) {
    int somme = 0;
    for(int i = 0; i < t.size(); i++) {
        somme += t[i];
    } return somme;
}

int indiceMax(vector<int> t) {
    int greatestVal = 0;
    int greatestInd = 0;
    if(t.size() > 0) {
        for(int i = 0; i < t.size(); i++) {
            if(t[i] > greatestVal) {
                greatestVal = t[i];
                greatestInd = i;
            }
        } return greatestInd; }
    return -1;
}

vector<string> colonne(vector<vector<string>> t, int i) {
    vector<string> j;
    for (int k = 0; k < t.size(); k++ ) {
        j.push_back(t[k][i]);
    }
    return j;
}

vector<int> conversionInt(vector<string> t) {
    vector<int> resultat = vector<int>(t.size());
    for(int i = 0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}

vector<vector<string>> selectLignes(vector<vector<string>> t, int j, string valeur) {
    vector<vector<string>> resultat;
    for (auto ligne : t) {
        if (ligne[j] == valeur) {
            resultat.push_back(ligne);
        }
    }
    return resultat;
}

