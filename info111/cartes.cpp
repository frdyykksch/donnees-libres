#include <stdexcept>
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
#include <SFML/Graphics.hpp>
#include "lib/primitives.hpp"
#include <cmath>
using namespace std;
using namespace sf;

const double PI = 3.14159265359;

void draw_circle(RenderWindow& window, Point center, int r, Color color) {
    double dt = 1.0 / r;
    for (double t = 0; t <= 2*PI; t += dt) {
        draw_point(window, {center.x + r * cos(t), center.y + r * sin(t)}, color);
    }
}
// CHAT GPT: separe les x des y
vector<string> separerCoordonnees(string coordonnees) {
    vector<string> resultat;
    string temp = "";
    
    // Parcourir la chaîne
    for(char c : coordonnees) {
        if(c == ',') {
            // Enlever les espaces et ajouter la première coordonnée
            while(!temp.empty() && temp.back() == ' ') temp.pop_back();
            resultat.push_back(temp);
            temp = "";
        } else {
            // Ignorer les espaces au début
            if(!(temp.empty() && c == ' ')) {
                temp += c;
            }
        }
    }
    // Ajouter la deuxième coordonnée
    while(!temp.empty() && temp.back() == ' ') temp.pop_back();
    resultat.push_back(temp);
    
    return resultat;
}
// CHAT GPT SUITE

//Problème, ça créer un tableau sous la forme :
// ["48.835092787824", "2.35346813513", "48.856614", "2.3522219"]
// au lieu de :
// [[x1, y1], [x2, y2], ...]

vector<string> separerCoordonneesDansTableau(vector<string> tableau) {
    vector<string> nouveauTableau;
    
    for(const string& coordonnees : tableau) {
        // Séparer chaque coordonnée
        string temp = "";
        bool premiereCoordAjoutee = false;
        
        for(char c : coordonnees) {
            if(c == ',') {
                // Enlever les espaces et ajouter la première coordonnée
                while(!temp.empty() && temp.back() == ' ') temp.pop_back();
                nouveauTableau.push_back(temp);
                temp = "";
                premiereCoordAjoutee = true;
            } else {
                // Ignorer les espaces au début
                if(!(temp.empty() && c == ' ')) {
                    temp += c;
                }
            }
        }
        // Ajouter la deuxième coordonnée
        while(!temp.empty() && temp.back() == ' ') temp.pop_back();
        nouveauTableau.push_back(temp);
    }
    
    return nouveauTableau;
}
int main() {
    // Lecture du fichier CSV
    vector<vector<string>> stations = litTableauCSV("donnees/velib-emplacement-des-stations.csv");
    
    RenderWindow window(VideoMode(800, 600), "Carte des stations Vélib");
    window.clear(Color::White);


    //création de deux tableaux qui contiennent de manière distinctes, la colone position et la colonne capacité de la station
    vector<string> position_str = colonne(stations, 3);
    vector<string> capacité_str = colonne(stations, 2);
    
    

    
}
    vector<double> position = conversionDouble(separerCoordonnees(position_str));
    vector<int> capacité = conversionInt(capacité_str);




//// CHAT GPT ça

//     // Trouver les bornes des coordonnées pour la mise à l'échelle
//     double min_lat = stod(stations[0][2]), max_lat = stod(stations[0][2]);
//     double min_lon = stod(stations[0][3]), max_lon = stod(stations[0][3]);
    
//     for (const auto station : stations) {
//         double lat = stod(station[2]);
//         double lon = stod(station[3]);
//         min_lat = min(min_lat, lat);
//         max_lat = max(max_lat, lat);
//         min_lon = min(min_lon, lon);
//         max_lon = max(max_lon, lon);
//     }






//     // Dessiner chaque station
//     for (const auto& station : stations) {
//         double lat = stod(station[2]);
//         double lon = stod(station[3]);
//         int capacity = stoi(station[4]);
        
//         // Conversion des coordonnées géographiques en pixels
//         int x = (lon - min_lon) * 800 / (max_lon - min_lon);
//         int y = 600 - (lat - min_lat) * 600 / (max_lat - min_lat);
        
//         // Rayon proportionnel à la capacité (ajuster le facteur selon besoin)
//         int radius = 1 + capacity / 10;
        
//         draw_circle(window, {x, y}, radius, Color::Blue);
//     }

//     window.display();

//     Event event;
//     while (window.isOpen()) {
//         while (window.pollEvent(event)) {
//             if (event.type == Event::Closed)
//                 window.close();
//         }
//     }

//     return 0;
// }
