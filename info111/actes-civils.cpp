#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;

/** Affiche l'année avec le plus de naissances et l'année avec le plus de mariages
 **/
int main() {
    vector<vector<string>> stats = litTableauCSV("donnees/statistiques_de_creation_d_actes_d_etat_civil_par_arrondissement.csv");
    //Naissances
    vector<vector<string>> naissances = selectLignes(stats, 0, "Naissances");
    
    vector<string> annees;
    for (int i = 2004; i < 2024; i++) {
        annees.push_back("i");
    }
    vector<int> total_par_annee_naissances = groupByInt(naissances, annees, 1, 3);
    int valeur_max = 0;
    int annee_naissance = 0; 
    for (int j = 0; j < total_par_annee_naissances.size(); j++) {
        if (total_par_annee_naissances[j] > valeur_max) {
            valeur_max = total_par_annee_naissances[j];
            annee_naissance = 2004 + j;
        }
    }
    cout << "L'année durant laquelle il y a le plus grand nombres de déclaration de naissances est" << annee_naissance << endl;
    //Mariages
    vector<vector<string>> mariages = selectLignes(stats, 0, "Mariages");
    vector<int> total_par_annee_mariages = groupByInt(mariages, annees, 1, 3);
    int valeur_max2 = 0;
    int annee_mariage = 0; 
    for (int k = 0; k < total_par_annee_mariages.size(); k++) {
        if (total_par_annee_mariages[k] > valeur_max2) {
            valeur_max2 = total_par_annee_mariages[k];
            annee_mariage = 2004 + k;
        }
    }
    cout << "L'année durant laquelle à été déclaré le plus de mariage est" << annee_mariage << endl;


}