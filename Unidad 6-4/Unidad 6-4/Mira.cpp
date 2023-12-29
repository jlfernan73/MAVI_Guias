#include "Mira.h"

Mira::Mira() {
	miraX = 200;
	miraY = 100;
	anchoMira = 80;
	tex_mira.loadFromFile("crosshair.png");
	mira.setTexture(tex_mira);
	tex_mira.setSmooth(true);
	Vector2u obj_size = tex_mira.getSize();
	mira.setScale(static_cast<float>(anchoMira) / obj_size.x, static_cast<float>(anchoMira) / obj_size.y);
	mira.setOrigin(obj_size.x / static_cast<float>(2), obj_size.y / static_cast<float>(2));
	mira.setPosition(miraX, miraY);
}
void Mira::dibujar(RenderWindow* app) {
	app->draw(mira);
}
void Mira::mover(float x, float y) {
	//chequea que no salga del espacio de juego
	if (y > 800) {
		y = 800;
	}
	if (y < 0) {
		y = 0;
	}
	if (x > 1200) {
		x = 1200;
	}
	if (x < 0) {
		x = 0;
	}
	mira.setPosition(x, y);
}
