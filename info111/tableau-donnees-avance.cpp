#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-donnees-avance.hpp"

#include <iostream> // db

        // Auteur
        // Frederik Kockisch
        // Toutes les fonctions

int chercheIndice(vector<string> t, string valeur) {
    for(int i = 0; i < t.size(); i++) {
        if(t[i] == valeur) {
            return i;
        }
    } return -1;
}

// mine
bool inVec(vector<string> t, string s) {
    for(int i = 0; i < t.size(); i++) {
        if(t[i] == s) {
            return true;
        }
    } return false;
}

// b you wont believe why i struggled so hard on this damn.. next time dont init the vec at sizr 1 haha
vector<string> distinct(vector<vector<string>> data, int j) {
    vector<string> valeursDistinctes;
    for(int i = 0; i < data.size(); i++) {
        for(int k = 0; k < data[i].size(); k++) {
            if(k == j && !(inVec(valeursDistinctes, data[i][k]))) {
                // cerr << inVec(valeursDistinctes, data[i][k]) << " ";
                // cerr << data[i][k] << " ";
                valeursDistinctes.push_back(data[i][k]);
            }
        }
    } return valeursDistinctes;
}

// mine, look awy b
int conversionSingleInt(string t) {
    int resultat;
    istringstream(t) >> resultat;
    return resultat;
}
// samesame
int conversionSingleDouble(string t) {
    double resultat;
    istringstream(t) >> resultat;
    return resultat;
}

vector<double> conversionDouble(vector<string> t) {
    vector<double> resultat = vector<double>(t.size());
    for(int i = 0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}

vector<int> groupByInt(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    // hold on tight for this one.. we got 1 data matrix, then we got 1 vector with the data we 
    // want to sort out like indices and then j1 the col of the sorted out data from before
    // and then j2 the data as intstrings we need to add by indice.
    // just look at the header dawg 

    // bro nvm we good didnt take as long as i thought.. just used some o my own funcs if thats ok :)
    vector<int> intStrValues(valeurs.size());
    for(int i = 0; i < data.size(); i++) {
        for(int j = 0; j < data[i].size(); j++) {
            if(j == j2 && inVec(valeurs,data[i][j1]))
                // cerr << data[i][j2] << " - "; // db
                intStrValues[chercheIndice(valeurs,data[i][j1])] += conversionSingleInt(data[i][j2]);
                // cerr << intStrValues[chercheIndice(valeurs,data[i][1])] << " ";
        }
    } 
    // for(auto val:intStrValues) cerr << val << " ";
    return intStrValues;
}

vector<double> groupByDouble(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    vector<double> intStrValues(valeurs.size());
    for(int i = 0; i < data.size(); i++) {
        for(int j = 0; j < data[i].size(); j++) {
            if(j == j2 && inVec(valeurs,data[i][j1]))
                // cerr << data[i][j2] << " - "; // db
                intStrValues[chercheIndice(valeurs,data[i][j1])] += conversionSingleDouble(data[i][j2]);
                // cerr << intStrValues[chercheIndice(valeurs,data[i][1])] << " ";
        }
    } 
    // for(auto val:intStrValues) cerr << val << " ";
    return intStrValues;
}

template<class T>
vector<T> conversion(vector<string> t) {
    // Remplacez cette ligne et la suivante par le code adéquat
    throw runtime_error("Fonction conversion non implantée ligne 36");
}

template<class T>
vector<T> groupBy(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    // Remplacez cette ligne et la suivante par le code adéquat
    throw runtime_error("Fonction groupBy non implantée ligne 42");
}

// Force l'instanciation des templates
template vector<int> conversion<int>(vector<string> t);
template vector<double> conversion<double>(vector<string> t);
template vector<int> groupBy<int>(vector<vector<string>> data, vector<string> valeurs, int j1, int j2);
template vector<double> groupBy<double>(vector<vector<string>> data, vector<string> valeurs, int j1, int j2);

