#pragma once
#include "encabezados.h"
using namespace std;
using namespace sf;

class Balazo {
	Sprite balazo;
	Texture mat_balazo;
	// Tama�o del disco despedazado por el balazo
	int anchoBalazo = 150;
public:
	Balazo();
	void setPos(float x, float y);
	void dibujar(RenderWindow* app);
};