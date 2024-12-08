#include <stdexcept>
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
// #include <SFML/Graphics.hpp>
// #include "lib/primitives.hpp"
// #include <cmath>
using namespace std;
//using namespace sf;

// const double PI = 3.14159265359;

// void draw_circle(RenderWindow& window, Point center, int r, Color color) {
//     double dt = 1.0 / r;
//     for (double t = 0; t <= 2*PI; t += dt) {
//         draw_point(window, {center.x + r * cos(t), center.y + r * sin(t)}, color);
//     }
// }

int main() {
    // Lecture du fichier CSV
    vector<vector<string>> stations = litTableauCSV("donnees/velib-emplacement-des-stations.csv");
    
    // // Création de la fenêtre avec fond
    // RenderWindow window(VideoMode(1200, 954), "Carte des stations Vélib");
    // Texture texture;
    // if (!texture.loadFromFile("donnees/Paris_plan.png")) {
    //     cerr << "Erreur lors du chargement de l'image de fond" << endl;
    //     return -1;
    // }
    // Sprite background(texture);
    // window.draw(background);

    //création de deux tableaux qui contiennent de manière distinctes, la colone position et la colonne capacité de la station
    vector<string> position_str = colonne(stations, 3);
    vector<string> capacité_str = colonne(stations, 2);
    
    
    vector<double> position = conversionDouble(position_str);
    vector<int> capacité = conversionInt(capacité_str);
    
    cout << "Positions brutes : " << endl;
    for (const string& pos : position_str) {
        cout << pos << endl;
    }
    
    // Il faudrait parser la chaîne pour séparer latitude et longitude
    vector<pair<double, double>> positions;
    for (const string& pos : position_str) {
        size_t virgule = pos.find(',');
        if (virgule != string::npos) {
            double lat = stod(pos.substr(0, virgule));
            double lon = stod(pos.substr(virgule + 1));
            positions.push_back({lat, lon});
        }
    }
    
    // Affichage des coordonnées parsées
    cout << "\nPositions parsées (lat, lon) : " << endl;
    for (const auto& pos : positions) {
        cout << pos.first << ", " << pos.second << endl;
    }

    // //Affichage des positions
    // for (const double& pos : position) {
    //     cout << pos << " ";
    // }
    // cout << endl;
}


// test pour la création d'un vecteur qui sépare les coordonnées

// int main() {
//     int n = 0;
//     vector<string> colonne = {"2.90930 , 8.9038403", "2.39403 , 8.39203"};
//     vector<string> t = {""}; // Initialiser un vecteur de chaînes

//     for (auto valeur : colonne) {
//         for (char value : valeur) {
//             if (value != ',') {
//                 t[n] += value;
//             } else {
//                 n += 1;
//                 t.push_back(""); // Préparer une nouvelle entrée
//             }
//         }
//     }

//     for (auto valeiir : t) {
//         cout << valeiir << " ";
//     }
//     cout << endl;

//     return 0; // Indiquer que le programme s'est bien terminé




