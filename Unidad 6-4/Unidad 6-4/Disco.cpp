#include "Disco.h"

Disco::Disco() {
	mat_disco.loadFromFile("disco.png");

	Vector2u disco_size = mat_disco.getSize();

	disco.setScale(alto / disco_size.y, alto / disco_size.y);

	disco.setOrigin(disco_size.x / 2.0f, disco_size.y / static_cast<float>(2));

	disco.setTexture(mat_disco);
}
void Disco::dibujar(RenderWindow* app) {
	disco.setPosition(discoX, discoY);
	app->draw(disco);
}
void Disco::setPosition(float x, float y) {
	discoX = x;
	discoY = y;
}
void Disco::setVelocity(float vx, float vy) {
	velX = vx;
	velY = vy;
}
float Disco::getX() {
	return discoX;
}
float Disco::getY() {
	return discoY;
}
float Disco::getVelX() {
	return velX;
}
float Disco::getVelY() {
	return velY;
}

