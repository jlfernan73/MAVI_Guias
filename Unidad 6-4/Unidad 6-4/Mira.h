#pragma once
#include "encabezados.h"
using namespace std;
using namespace sf;

class Mira {
	Sprite mira;
	Texture tex_mira;
	float miraX, miraY, anchoMira;
public:
	Mira();
	void dibujar(RenderWindow* app);
	void mover(float x, float y);
};
