#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-lecture.hpp"
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
using namespace std;

        // Frederik Kockisch

/**
 * Calcule et affiche :
 * - le nombre total de naissances de garçons et de naissances de filles
 * - l'année qui a eu le plus de naissances (garçons et filles confondus), avec leur nombre
 * - le nombre de naissances en moyenne par an
 * - les nombres de prénoms féminins et masculins différents
 * - le prénom masculin et le prénom féminin le plus populaire
 **/
int main() {
    vector<vector<string>> data = litTableau("donnees/liste_des_prenoms.txt", 4);

    // M
    vector<vector<string>> dataM = selectLignes(data, 0, "M");
    vector<string> naissancesM = colonne(dataM, 3);
    vector<int> naissancesMInt = conversionInt(naissancesM);
    // F
    vector<vector<string>> dataF = selectLignes(data, 0, "F");
    vector<string> naissancesF = colonne(dataF, 3);
    vector<int> naissancesFInt = conversionInt(naissancesF);

    cout << "Il y a eu " << somme(naissancesMInt)
        << " naissances de garçons et " << somme(naissancesFInt) << " de filles" << endl;
    
    vector<string> years;
    for(int i = 2004; i <= 2022; i++) {
        years.push_back(to_string(i));
    }
    vector<int> unsortedYears = groupBy<int>(data, years, 1, 3);
    for(auto val: unsortedYears) cerr << val << endl;
    int maxYear = indiceMax(unsortedYears);
    cout << "L'année qui a eu le plus de naissances est "
        << maxYear + 2004 << " avec " << unsortedYears[maxYear] << " naissances" << endl;
    cout << "En moyenne naissent " << moyenne(unsortedYears) << " enfants par an" << endl;
    
    vector<string> prenomsUniquesM = distinct(dataM, 2);
    vector<string> prenomsUniquesF = distinct(dataF, 2);
    cout << "Il y a eu " << prenomsUniquesF.size() << " prénoms de fille différents et " 
         << prenomsUniquesM.size() << " prénoms de garçons" << endl;
    
    vector<string> prenomsUniquesGarcons = distinct(dataM, 2);
    vector<int> naissancesParPrenomM = groupBy<int>(dataM, prenomsUniquesGarcons, 2, 3);
    int indexMaxM = indiceMax(naissancesParPrenomM);
    
    vector<string> prenomsUniquesFilles = distinct(dataF, 2);
    vector<int> naissancesParPrenomF = groupBy<int>(dataF, prenomsUniquesFilles, 2, 3);
    int indexMaxF = indiceMax(naissancesParPrenomF);
    
    cout << "Le prénom féminin le plus populaire est " << prenomsUniquesFilles[indexMaxF] 
         << " avec " << naissancesParPrenomF[indexMaxF] << " naissances" << endl;
    cout << "Le prénom masculin le plus populaire est " << prenomsUniquesGarcons[indexMaxM] 
         << " avec " << naissancesParPrenomM[indexMaxM] << " naissances" << endl;
}

