#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-lecture.hpp"
using namespace std;

/**
 * Demande à l'utilisateur un prénom et calcule
 * - le nombre de garçons et filles à qui l'on a donné ce prénom
 * - la meilleure année pour ce prénom pour les garçons et filles
 **/
int main() {
    vector<vector<string>> t = litTableau("donnees/liste_des_prenoms.txt", 4);
    string prénom;
    vector<int> naissances = conversionInt(colonne(t, 3));

    cout << "Nombre total de naissances : " << somme(naissances) << endl;
   
    //demande prénom
    string prenom;
    cout << "Choississez un prénom : ";
    cin >> prenom;  
    cout << prenom << endl;

    vector<vector<string>> lignes_Garcons = selectLignes(selectLignes(t, 0, "M"), 2, prenom);
    cerr << lignes_Garcons[0][0] << endl;
    vector<vector<string>> lignes_Filles = selectLignes(selectLignes(t, 0, "F"), 2, prenom);
    

    //affiche nombre de garçons 
    if (lignes_Garcons.size() == 0) {
        cout << "Le prénom " << prenom << " n'a été donné à aucun garçon entre 2006 et 2023" << endl;
    } else {
        vector<int> naissances_garcons = conversionInt(colonne(lignes_Garcons, 3));
        int total_garcons = somme(naissances_garcons);

        vector<string> annees_garcons = colonne(lignes_Garcons, 1);
        int idx_max_garcons = indiceMax(naissances_garcons);
        
        cout << "Le prénom " << prenom << " a été donné à " << total_garcons << " garçons entre 2006 et 2023" << endl;
        cout << "L'année la plus forte pour les garçons est " << annees_garcons[idx_max_garcons] << " avec " << naissances_garcons[idx_max_garcons] << " naissances" << endl;
    }

    if (lignes_Filles.size() == 0) {
        cout << "Le prénom " << prenom << " n'a été donné à aucune fille entre 2006 et 2023" << endl;
    } else {
        vector<int> naissances_filles = conversionInt(colonne(lignes_Filles, 3));
        int total_filles = somme(naissances_filles);
        
        vector<string> annees_filles = colonne(lignes_Filles, 1);
        int idx_max_filles = indiceMax(naissances_filles);
        
        cout << "Le prénom " << prenom << " a été donné à " << total_filles << " filles entre 2006 et 2023" << endl;
        cout << "L'année la plus forte est " << annees_filles[idx_max_filles] << " avec " << naissances_filles[idx_max_filles] << " naissances" << endl;
    }
}