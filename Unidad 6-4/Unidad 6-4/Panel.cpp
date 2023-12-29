#include "Panel.h"

// texto que muestra el puntaje
Panel::Panel() {
	fuente.loadFromFile("COOPBL.ttf");
	puntaje.setFont(fuente);
	puntaje.setCharacterSize(50);
	puntaje.setFillColor(sf::Color::White);
	puntaje.setPosition(50, 820);
	actualizar();
}
void Panel::actualizar() {
	puntos = 0;
	ptsString = ptsString.replace(10, 12, to_string(puntos));
	puntaje.setString(ptsString);
}
void Panel::setPuntos(int pun) {
	puntos += pun;
	ptsString = ptsString.replace(10, 12, to_string(puntos));
	puntaje.setString(ptsString);
}
void Panel::dibujar(RenderWindow* app) {
	app->draw(puntaje);
}
