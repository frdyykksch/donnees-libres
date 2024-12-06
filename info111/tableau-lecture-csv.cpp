#include <stdexcept>
/** @file **/
#include <iostream>
#include <fstream>
#include <sstream>
#include "tableau-lecture-csv.hpp"

        // Julien Cassou

/** Construction d'un tableau 2D de chaînes lu depuis un fichier CSV
 * @param fichier le nom d'un fichier contenant un nombre fixe
  * de valeurs par ligne, séparées par des espaces
 * @param nb_colonnes le nombre de colonnes du fichier
 * @return un tableau de chaînes de caractères à deux dimensions
 **/
vector<vector<string>> litTableauCSV(string nom_fichier, int nb_colonnes) {
    vector<vector<string>> resultat;
    ifstream fichier(nom_fichier);
    string ligne;

    getline(fichier, ligne);
    while (fichier) {
        vector<string> ligne_renvoye;
        string valeur;
        
        for (int i = 0; i < nb_colonnes-1; i++) {
            getline(fichier, valeur, ';');
            ligne_renvoye.push_back(valeur);
        }
        getline(fichier, valeur, ';');
        
        if (fichier) {
            resultat.push_back(ligne_renvoye);
        }
    }
    return resultat;
}

vector<vector<string>> litTableauCSV(string nom_fichier) {
    vector<vector<string>> resultat;
    ifstream fichier(nom_fichier);
    string ligne;
    getline(fichier, ligne);
    while (getline(fichier, ligne)) {
        istringstream la_ligne(ligne);
        vector<string> ligne_renvoye;
        string valeur;

        while (getline(la_ligne, valeur, ';')) {
            ligne_renvoye.push_back(valeur);
        }
        resultat.push_back(ligne_renvoye);
    }
    return resultat;
}