#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

void draw_circle (RenderWindow& w, Point center, int r, Color color) {
	double dt = 1 / r;
	for ( double t = 0; t <= 2*pi; t += dt ) {
        draw_point(w, {center.x + r * cos(t), center.y + r * sin(t)}, Color:: color);
}  