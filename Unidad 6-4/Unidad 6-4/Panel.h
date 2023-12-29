#pragma once
#include "encabezados.h"
using namespace std;
using namespace sf;

class Panel {
	Font fuente;
	Text puntaje;
	string ptsString = "Puntaje:  ";
	int puntos;
public:
	Panel();
	void actualizar();
	void setPuntos(int pun);
	void dibujar(RenderWindow* app);
};