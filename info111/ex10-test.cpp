// g++ -c ex10-test.cpp -I"SFML/include"
// g++ ex10-test.o tableau-lecture-csv.cpp -o ex10-test -lsfml-graphics -lsfml-window -lsfml-system
#include <SFML/Graphics.hpp>
#include "tableau-lecture-csv.hpp"

using namespace sf;
using namespace std;

int main() {
    // Configuration du contexte
    ContextSettings settings;
    settings.antialiasingLevel = 0;  // Désactive l'antialiasing
    
    // Création de la fenêtre avec les paramètres
    RenderWindow window(VideoMode(800, 600), "Carte des stations Vélib", Style::Default, settings);
    window.setFramerateLimit(60);  // Limite les FPS au lieu d'utiliser la sync verticale
    
    // Cercle de test au milieu
    CircleShape testCircle(50); // Rayon de 50 pixels
    testCircle.setPosition(400 - 50, 300 - 50); // Centre de la fenêtre (800/2, 600/2) moins le rayon
    testCircle.setFillColor(Color::Red);
    
    // Lecture du fichier CSV
    vector<vector<string>> stations = litTableauCSV("donnees/velib-emplacement-des-stations.csv");
    
    // Création des cercles pour chaque station
    vector<CircleShape> stationShapes;
    
    // Pour chaque station
    for (const auto& station : stations) {
        try {
            if (station.size() >= 5) {
                float lat = stof(station[2]);
                float lon = stof(station[3]);
                int capacite = stoi(station[4]);
                
                if (capacite <= 0) continue;
                
                // Ajout de debug pour voir les coordonnées
                // cout << "lat: " << lat << ", lon: " << lon << ", capacite: " << capacite << endl;
                
                CircleShape circle;
                circle.setRadius(5); // Taille fixe pour tester
                
                // Ajustement de l'échelle pour Paris
                // Paris est environ: lat 48.8-48.9, lon 2.2-2.4
                float x = (lon - 2.2) * 2000; // Échelle ajustée
                float y = (48.9 - lat) * 2000; // Inversé pour l'axe Y
                
                circle.setPosition(x, y);
                circle.setFillColor(Color(255, 0, 0, 128));
                
                stationShapes.push_back(circle);
            }
        } catch (const std::exception& e) {
            continue;
        }
    }
    
    // Boucle principale
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        
        window.clear(Color::White);
        
        // Dessiner le cercle de test
        window.draw(testCircle);
        
        // Dessiner toutes les stations
        for (const auto& shape : stationShapes) {
            window.draw(shape);
        }
        
        window.display();
    }
    
    return 0;
}