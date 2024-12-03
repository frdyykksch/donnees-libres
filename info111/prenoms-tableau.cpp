#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

        // Julien Cassou

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<vector<string>> tableauTest = {
    { "M", "2011", "Bubulle", "3"},
    { "F", "2012", "Bichette", "4"},
    { "F", "2011", "Babouche", "7"},
    { "F", "2011", "Ziboulette", "1"}
};

/** Affiche le contenu d'un tableau de chaînes à deux dimensions
 * @param tableau un tableau à deux dimensions
 **/
void afficheTableau(vector<vector<string>> tableau) {
    for (auto ligne : tableau) {
        for (auto element : ligne) {
            cout << element << " ";
        }
        cout << endl;
    }
}

void testAfficheTableau() {
    afficheTableau(tableauTest);
}


/** Construction d'un tableau 2D de chaines de caractères lu depuis un fichier
 * @param fichier le nom d'un fichier contenant un nombre fixe
  * de colonnes séparées par des espaces
 * @param nb_colonnes le nombre de colonnes du fichier
 * @return un tableau de chaines de caractères à deux dimensions
 **/
vector<vector<string>> litTableau(string nom_fichier, int nb_colonnes) {
    ifstream tableau(nom_fichier);
    vector<vector<string>> resultat; 
    string ligne;
    
    while (getline(tableau, ligne)) {
        istringstream la_ligne(ligne);
        vector<string> ligne_renvoyé;
        for (int i = 0; i < nb_colonnes; i++) {
            la_ligne >> ligne_renvoyé[i];
        }
        resultat.push_back(ligne_renvoyé);
    }
    return resultat;
}

/** Test de la fonction litTableau **/
void testLitTableau() {
    CHECK(litTableau("donnees/donnees-test.txt", 4) == tableauTest);
    vector<vector<string>> t = litTableau("donnees/liste_des_prenoms.txt", 4);
    CHECK(t.size() == 25465);
    CHECK(t[0][0] == "M");
    CHECK(t[3][2] == "Olivia");
    CHECK(t[5][3] == "71");
}

/** Extraction d'une colonne d'un tableau de données
 * @param t un tableau 2D de chaines de caractères
 * @param i un numéro de colonne
 * @return la colonne j, représentée par un vecteur de chaines de caractères
 **/
vector<string> colonne(vector<vector<string>> t, int i) {
    vector<string> j;
    for (int k = 0; k < t.size(); k++ ) {
        j.push_back(t[k][i]);    
    }
    return j;
}

/** Test de la fonction colonne **/
void testColonne() {
    CHECK(colonne(tableauTest, 0) == vector<string>({"M","F","F","F"}));
    CHECK(colonne(tableauTest, 1) == vector<string>({"2011","2012","2011","2011"}));
    CHECK(colonne(tableauTest, 2) == vector<string>({"Bubulle","Bichette","Babouche","Ziboulette"}));
    CHECK(colonne(tableauTest, 3) == vector<string>({"3","4","7","1"}));
}

/** Convertit un tableau de chaines de caractères en un tableau d'entiers
 * @param t, un vecteur de chaines de caractères
 * @return un vecteur d'entiers
 **/
vector<int> conversionInt(vector<string> t) {
    vector<int> resultat = vector<int>(t.size());
    for(int i =0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}

void testConversionInt() {
    CHECK(conversionInt({}) == vector<int>({}));
    CHECK(conversionInt({"1","2","3"}) == vector<int>({1,2,3}));
}

/** copier la fonction somme déjà écrite **/
int somme(vector<int> t) {
    int somme = 0;
    for(int i = 0; i < t.size(); i++) {
        somme += t[i];
    } return somme;
}

/** copier la fonction moyenne déjà écrite **/
int moyenne(vector<int> t) {
    int sommeTab = somme(t);
    return sommeTab / t.size();
}

/** copier la fonction indiceMax déjà écrite **/
int indiceMax(vector<int> t) {
    int greatestVal = 0;
    int greatestInd = 0;
    if(t.size() > 0) {
        for(int i = 0; i < t.size(); i++) {
            if(t[i] > greatestVal) {
                greatestVal = t[i];
                greatestInd = i;
            }
        } return greatestInd; }
    return -1;
}

/** Sélection des lignes d'un tableau de données
 * Sélectionne un ensemble de lignes en fonction d'un critère donné
 * @param t, un tableau contenant des lignes de données
 * @param j, l'indice de la colonne à vérifier
 * @param valeur, une chaine de caractères correspondant au critère
 * @return un tableau de données ne contenant que les lignes de t telles
 *  que la colonne j ait la valeur correspondant au critère
 **/
vector<vector<string>> selectLignes(vector<vector<string>> t, int j, string valeur) {
    vector<vector<string>> resultat;
    for (auto ligne : t) {
        if (ligne[j] == valeur) {
            resultat.push_back(ligne);
        }
    }
    return resultat;
}

/** Test de la fonction selectLignes **/
void testSelectLignes() {
    CHECK(selectLignes(tableauTest, 0, "M") == vector<vector<string>>({{ "M", "2011", "Bubulle", "3"}}));
    CHECK(selectLignes(tableauTest, 1, "2011") == vector<vector<string>>({{ "M", "2011", "Bubulle", "3"}, { "F", "2011", "Babouche", "7"}, { "F", "2011", "Ziboulette", "1"}}));
}

/** Lance les tests de litTableau, selectLignes et colonne puis
 * affiche le nombre total de naissances puis
 * demande à l'utilisateur un prénom et calcule et affiche
 * - le nombre de garçons et filles à qui l'on a donné ce prénom
 * - la meilleure année pour ce prénom pour les garçons et filles
 **/
int main() {
    testLitTableau();
    testColonne();
    testSelectLignes();
    string prénom;
    vector<vector<string>> t = litTableau("donnees/liste_des_prenoms.txt", 4);
    vector<int> naissances = conversionInt(colonne(t, 3));
    cout << "Nombre total de naissances : " << somme(naissances) << endl;
   
    //demande prénom
    string prenom;
    cout << "Choississez un prénom : ";
    cin >> prenom;  
    cout << prenom << endl;

    vector<vector<string>> lignes_Garcons = selectLignes(selectLignes(t, 0, "M"), 2, prenom);
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