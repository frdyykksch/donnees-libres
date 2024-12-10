#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-donnees-avance.hpp"

#include <iostream> // db

        // Frederik Kockisch

/* 
 * Frederik Kockisch
 * Degré de confiance - 100% - Pas de bugs 
*/ 
int chercheIndice(vector<string> t, string valeur) {
    for(int i = 0; i < t.size(); i++) {
        if(t[i] == valeur) {
            return i;
        }
    } return -1;
}

/* FONCTION AJOUTÉE
 * Frederik Kockisch
 * Degré de confiance - 100% - Pas de bugs 
*/ 
/* Fonctions inVector
 * @param t un tableau de valeur string
 * @param s un string
 * @return true, si la valeur s est dans le tableau t, false sinon
*/ 
bool inVec(vector<string> t, string s) {
    for(int i = 0; i < t.size(); i++) {
        if(t[i] == s) {
            return true;
        }
    } return false;
}

/* 
 * Frederik Kockisch
 * Degré de confiance - 90% - Pas complètement testé 
*/ 
vector<string> distinct(vector<vector<string>> data, int j) {
    vector<string> valeursDistinctes;
    for(int i = 0; i < data.size(); i++) {
        for(int k = 0; k < data[i].size(); k++) {
            if(k == j && chercheIndice(valeursDistinctes, data[i][k]) == -1) {
                // cerr << inVec(valeursDistinctes, data[i][k]) << " ";
                // cerr << data[i][k] << " ";
                valeursDistinctes.push_back(data[i][k]);
            }
        }
    } return valeursDistinctes;
}

/* 
 * Frederik Kockisch
 * Degré de confiance - 90% - Pas complètement testé 
 * converti un string en double
*/ 
int conversionSingleDouble(string t) {
    double resultat;
    istringstream(t) >> resultat;
    return resultat;
}

/* 
 * Frederik Kockisch
 * Degré de confiance - 90% - Pas complètement testé 
 * converti un string en double
*/ 
vector<double> conversionDouble(vector<string> t) {
    vector<double> resultat(t.size());
    for(int i = 0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}

/* 
 * Frederik Kockisch
 * Degré de confiance - 100% - Pas de bugs
*/ 
vector<int> groupByInt(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    vector<int> intStrValues(valeurs.size());
    for(int i = 0; i < data.size(); i++) {
        for(int j = 0; j < data[i].size(); j++) {
            if(j == j2 && inVec(valeurs,data[i][j1]))
                // cerr << data[i][j2] << " - "; // db
                intStrValues[chercheIndice(valeurs,data[i][j1])] += stoi(data[i][j2]);
                // cerr << intStrValues[chercheIndice(valeurs,data[i][1])] << " ";
        }
    } 
    // for(auto val:intStrValues) cerr << val << " ";
    return intStrValues;
}

/* 
 * Frederik Kockisch
 * Degré de confiance - 100% - Pas de bugs
*/ 
vector<double> groupByDouble(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    vector<double> doubStrValues(valeurs.size());
    for(int i = 0; i < data.size(); i++) {
        for(int j = 0; j < data[i].size(); j++) {
            if(j == j2 && inVec(valeurs,data[i][j1]))
                // cerr << data[i][j2] << " - "; // db
                doubStrValues[chercheIndice(valeurs,data[i][j1])] += conversionSingleDouble(data[i][j2]);
                // cerr << intStrValues[chercheIndice(valeurs,data[i][1])] << " ";
        }
    } 
    // for(auto val:intStrValues) cerr << val << " ";
    return doubStrValues;
}

/* 
 * Frederik Kockisch
 * Degré de confiance - 100% - Pas de bugs
*/ 
template<class T>
vector<T> conversion(vector<string> t) {
    vector<T> resultat(t.size());
    for(int i = 0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}

/* 
 * Frederik Kockisch
 * Degré de confiance - 100% - Pas de bugs
*/ 
template<class T>
vector<T> groupBy(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    vector<T> strValues(valeurs.size(), T());
    for(int i = 0; i < data.size(); i++) {
        for(int j = 0; j < data[i].size(); j++) {
            if(j == j2 && inVec(valeurs, data[i][j1])) {
                int index = chercheIndice(valeurs, data[i][j1]);
                if (is_same<T, int>::value) { // aide par stackoverflow - https://stackoverflow.com/questions/992471/how-to-query-ift-int-with-template-class
                    strValues[index] += stoi(data[i][j2]);
                } else if (is_same<T, double>::value) {
                    strValues[index] += conversionSingleDouble(data[i][j2]);
                }
            }
        }
    }
    return strValues;
}

// Force l'instanciation des templates
template vector<int> conversion<int>(vector<string> t);
template vector<double> conversion<double>(vector<string> t);
template vector<int> groupBy<int>(vector<vector<string>> data, vector<string> valeurs, int j1, int j2);
template vector<double> groupBy<double>(vector<vector<string>> data, vector<string> valeurs, int j1, int j2);