#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"

using namespace std;
#include <SFML/Graphics.hpp>
#include "lib/primitives.hpp"

int main() {
<<<<<<< HEAD
=======
<<<<<<< HEAD
    RenderWindow w(VideoMode(750, 750));
	draw_point(w, {center.x + r * cos(t), center.y + r * sin(t)}, Color:: color);
}




=======
>>>>>>> 7b44ba366e90582192999730b3638725703bebe8
    // Crée une fenêtre de taille 640x480
    RenderWindow window(VideoMode(640, 480), "Ma super fenêtre");

    // Remplit la fenêtre de blanc
    window.clear(Color::White);

    // Affiche un point de couleur rouge
    draw_point(window, {120, 5}, Color::Red);

    // Actualise la fenêtre
    window.display();

    // Attend 10 secondes
    sleep(seconds(10));

    return 0;
<<<<<<< HEAD
}
=======
}

>>>>>>> 920de422332d64e9fa439204918c57eb3bd268e4
>>>>>>> 7b44ba366e90582192999730b3638725703bebe8
