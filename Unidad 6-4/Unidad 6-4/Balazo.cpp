#include "Balazo.h"

Balazo::Balazo() {
	mat_balazo.loadFromFile("balazo.png");
	balazo.setTexture(mat_balazo);
	Vector2u balazo_size = mat_balazo.getSize();
	balazo.setScale(static_cast<float>(anchoBalazo) / balazo_size.x, static_cast<float>(anchoBalazo) / balazo_size.y);
	balazo.setOrigin(balazo_size.x / static_cast<float>(2), balazo_size.y / static_cast<float>(2));
}
void Balazo::setPos(float x, float y) {
	balazo.setPosition(x, y);
}
void Balazo::dibujar(RenderWindow* app) {
	app->draw(balazo);
}
