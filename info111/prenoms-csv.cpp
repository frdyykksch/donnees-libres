#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

        // Julien Cassou

/** Calcule et affiche le prénom le plus donné une année donnée
 * ainsi que le nombre de naissance cette année là **/
// Julien Cassou
// Degrès de confiance: 100% -compilation réussi -programme qui fonctionne 
int main() {
    int annee;
    cout << "Entrez une année entre 2004 et 2023 :" << endl;
    cin >> annee;
    
    if (annee < 2004 || annee > 2023) {
        cerr << "L'année n'est pas entre 2004 et 2023" << endl;
        return 1;
    }
    
    ifstream prenoms("donnees/liste_des_prenoms.csv");
    
    int total_naissances = 0;
    int nombreMax = 0;
    string prenomMax = "";
    
    string ligne;
    getline(prenoms, ligne);
    while (getline(prenoms, ligne)) {
        istringstream ligne_actuelle(ligne);
        string nombre_str, MF, annee_naissance, prenom, total;
        int nombre, annee_naissance_int;

        getline(ligne_actuelle, nombre_str, ';');

        // cout << nombre_str << endl;
        
        nombre = stoi(nombre_str);

        getline(ligne_actuelle, MF, ';');
        getline(ligne_actuelle, annee_naissance, ';');

        // cout << annee_naissance << endl;
        
        annee_naissance_int = stoi(annee_naissance);
        
        getline(ligne_actuelle, prenom, ';');
        getline(ligne_actuelle, total);
        if (annee_naissance_int == annee) {
            total_naissances += nombre;
            if (nombre > nombreMax) {
                nombreMax = nombre;
                prenomMax = prenom;
            }   
        }
    }
    cout << "En " << annee << ", il y a eu " << total_naissances << " naissances" << endl;
    cout << "Le prénom le plus donné a été : " << prenomMax << " (donné " << nombreMax << " fois)" << endl;
    
}  