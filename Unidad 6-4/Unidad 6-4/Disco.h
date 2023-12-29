#pragma once
#include "encabezados.h"
using namespace std;
using namespace sf;

class Disco {
	Sprite disco;
	Texture mat_disco;
	// Coordenadas de la posición del disco
	float discoX, discoY;
	// Velocidades en X y en Y del disco
	float velX, velY;
	// Tamaño del disco
	float alto = 100;
public:
	Disco();
	void dibujar(RenderWindow* app);
	void setPosition(float x, float y);
	void setVelocity(float vx, float vy);
	float getX();
	float getY();
	float getVelX();
	float getVelY();
};