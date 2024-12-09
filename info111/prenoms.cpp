#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <clocale>

        // Julien Cassou

/** Calcule et affiche le prénom le plus utilisé une année donnée
 * ainsi que le nombre de naissances cette année là **/
// Julien Cassou
// Degrès de confiance: 
int main() { 
    setlocale(LC_ALL, "fr_FR.UTF-8"); // aide de Chat GPT pour l'affichage des "é" et "ù" dans la consolle
    int annee;
    cout << "Entrez une année entre 2004 et 2023 : ";
    cin >> annee;
    if (annee < 2004 || annee > 2023) {
        cerr << "L'année n'est pas entre 2004 et 2023" << endl;
        return 1;
    }
    cout << annee << endl;
    ifstream prénoms("donnees/liste_des_prenoms.txt");
    if (!prénoms) {
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
        return 1;
    }   
    
    string prénom, prénomMax, sexe;
    int annee_naissance, nombre, total_naissances = 0, nombreMax = 0;
    
    // Lecture du fichier ligne par ligne
    while (prénoms >> sexe >> annee_naissance >> prénom >> nombre) {
        if (annee_naissance == annee) {
            total_naissances += nombre;
            if (nombre > nombreMax) {
                nombreMax = nombre;
                prénomMax = prénom;
            }
        }
    }
    
    cout << "En " << annee << ", il y a eu " << total_naissances << " naissances" << endl;
    cout << "Le prénom le plus donné a été : " << prénomMax << " (donné " << nombreMax << " fois)" << endl;
    
    prénoms.close();
    return 0;
}   


