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

// compilation : g++ tableau-donnees-avance.cpp tableau-donnees.cpp tableau-lecture-csv.cpp cartes.cpp -o cartes
const double PI = 3.14159265359;

void draw_circle(RenderWindow& window, Point center, int r, Color color) {
    double dt = 1.0 / r;
    for (double t = 0; t <= 2*PI; t += dt) {
        draw_point(window, {center.x + r * cos(t), center.y + r * sin(t)}, color);
    }
}

vector<double> séparateur_coordonnées (vector<string> colonne) {
    vector<string> t;
    for (auto valeur : colonne) {
        string current = ""; 
        for (char value : valeur) {
            if (value != ',' && value != ' ') { 
                current += value;
            } else if (value == ',') { 
                t.push_back(current);
                current = ""; 
            }
        }
        if (!current.empty()) {
            t.push_back(current);
        }
    }

    for (auto valeiir : t) {
        cout << valeiir << " ";
    }
    cout << endl;

    vector<double> colonne2 = conversionDouble(t);
    // for (auto val : colonne2) {
    //     cout << val << " ";
    // }
    // cout << endl;

    // for (int i = 0; i < colonne2.size(); i++) {
    //     cout << colonne2[i] << endl;
    // }
    return colonne2;
}

int main() {
    // Lecture du fichier CSV
    vector<vector<string>> stations = litTableauCSV("donnees/velib-emplacement-des-stations.csv");
    
    // Création de la fenêtre avec fond
    RenderWindow window(VideoMode(1200, 954), "Carte des stations Vélib");
    Texture texture;
    if (!texture.loadFromFile("donnees/Paris_plan.png")) {
        cerr << "Erreur lors du chargement de l'image de fond" << endl;
        return -1;
    }
    Sprite background(texture);
    window.draw(background);

    //création de deux tableaux qui contiennent de manière distinctes, la colone position et la colonne capacité de la station
    vector<string> position_str = colonne(stations, 3);
    vector<string> capacité_str = colonne(stations, 2);
    
    
    vector<double> position = séparateur_coordonnées(position_str);
    vector<int> capacité = conversionInt(capacité_str);
    
    //mise à l'échelle   *1200 / 50
    for (int i = 0; i < position.size(); i += 2) {
        position[i] = (position[i] - 48) * 1200;
        position[i+1] = (position[i+1] - 2) * 954;

        // Dessiner un cercle pour chaque station
        draw_circle(window, {static_cast<int>(position[i]), static_cast<int>(position[i+1])}, capacité[i / 2], Color::Red);
    }
    
}







