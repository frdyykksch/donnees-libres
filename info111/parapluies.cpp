#include <stdexcept>
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
#include <clocale>

using namespace std;
// compilation: g++ tableau-donnees-avance.cpp tableau-donnees.cpp tableau-lecture-csv.cpp parapluies.cpp -o parapluies
   
   
    

/** Lit un fichier csv, et en extrait la gare en France où l'on a retrouvé le plus de 
 * parapluie entre 2018 et 2024
**/
// Julien Cassou
// Degrès de confiance: 100% -compilation réussi -programme affiche bien la gare où l'on a retrouvé le plus de 
// parapluie
int main() {
    setlocale(LC_ALL, "fr_FR.UTF-8"); // aide de Chat GPT pour l'affichage des "é" et "ù" dans la consolle
 
    vector<vector<string>> t = litTableauCSV("donnees/xobjets-trouves-restitution.csv", 7);
    vector<vector<string>> parapluie = selectLignes(t ,5 ,"Parapluies");
    
    vector<string> nom_station_parapluie = colonne(parapluie, 2);
    vector<string> nom_stations = {};
    for (auto value : nom_station_parapluie) {
        bool existeDeja = false;
        for (auto station : nom_stations) {
            if (station == value) {
                existeDeja = true;
                break;
            }
        }
        if (!existeDeja && !value.empty()) {
            nom_stations.push_back(value);
        }
    }
    string stations_max = "";
    int compteur_max = 0;


    for ( auto valeur : nom_stations ) {
        int compteur = 0;
        for (auto station : nom_station_parapluie) {
            if (valeur == station) {
                compteur += 1;
            }
        }
        if ( compteur > compteur_max) {
            compteur_max = compteur;
            stations_max = valeur;
        }
    }
    cout << "La gare où l'on a retrouvé le plus de parapluie en France entre 2018 et 2024 est : " << stations_max << endl;
}