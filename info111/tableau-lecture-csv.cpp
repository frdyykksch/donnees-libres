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
    while (getline(fichier, ligne)) {
        istringstream la_ligne(ligne);
        vector<string> ligne_renvoye;
        string valeur;
        
        for (int i = 0; i < nb_colonnes && getline(la_ligne, valeur, ';'); i++) {
            ligne_renvoye.push_back(valeur);
        }
        
        if (ligne_renvoye.size() == nb_colonnes) {
            resultat.push_back(ligne_renvoye);
        }
    }

    for(size_t j = 0; j < resultat.size(); j++) {
        for(size_t i = 0; i < resultat[j].size(); i++) {
            cerr << resultat[j][i] << " ";
        }
        cerr << endl;
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