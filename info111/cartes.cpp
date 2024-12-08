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

        // Julien Cassou / Frederik Kockisch

// compilation : g++ tableau-donnees-avance.cpp tableau-donnees.cpp tableau-lecture-csv.cpp cartes.cpp -o cartes
const double PI = 3.14159265359;

// Fonctions SFML
void draw_circle(RenderWindow &w, Point center, int r, Color color) {
    CircleShape shape(r);
    shape.setPosition(center);
    shape.setOutlineThickness(1.f);
    shape.setOutlineColor(color);
    shape.setFillColor(Color::Transparent);
    w.draw(shape);
}
void draw_point(RenderWindow &w, Point pos, Color color) {
    Vertex p[] = { Vertex(pos, color) };
    w.draw(p, 1, sf::Points);
}

/* Fonction separe coordonnées
 * @param colonne coordonnées en string vector
 * @return coordonnées x,y separées en double
 */
vector<double> separateur_coordonnees(vector<string> colonne) {
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
    vector<double> colonne2 = conversionDouble(t);
    return colonne2;
}

int main() {
    // Lecture du fichier CSV
    vector<vector<string>> stations = litTableauCSV("donnees/velib-emplacement-des-stations.csv", 4);

    // Création de la fenêtre avec carte fond
    RenderWindow window(VideoMode(1536, 959), "Carte des stations Vélib");  
    Texture texture;
    texture.loadFromFile("donnees/paris-carte.png");
    Sprite background(texture);
    window.draw(background);

    // 2 tableaux qui contiennent de manière distinctes, la colonne position et la colonne capacite de la station
    vector<string> position_str = colonne(stations, 3);
    vector<string> capacite_str = colonne(stations, 2);

    vector<double> position = separateur_coordonnees(position_str);
    vector<int> capacite = conversionInt(capacite_str);
    
    // Mise à l'échelle
    for (int i = 0; i < position.size(); i += 2) {
        position[i] = (position[i] - 48) * 1535;
        position[i+1] = (position[i+1] - 2) * 959;
        // Dessiner un cercle pour chaque station
        draw_circle(window, {static_cast<float>(position[i]), static_cast<float>(position[i+1])}, capacite[i / 2], Color::Red);
    }

    window.display();

    // Add event loop to keep window open
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
    }


    return 0;
}