#pragma once
#include "encabezados.h"
#include "Mira.h"
#include "Disco.h"
#include "Panel.h"
#include "Balazo.h"

using namespace std;
using namespace sf;

class Juego {
	RenderWindow* App;
	Mira* miraPlayer;
	Disco* disco;
	Balazo* balazo;
	Panel* panel;
	Event evt;
	Clock clock;
	bool gameOver = false;
	bool ganador = false;
	bool impacto = false;
	bool reinicio = true;
	bool dLanzado = false;
	bool dSano = true;
	Time tInicio, tPasado, tRoto;
	float acX = 0.0f;
	float acY = 0.0f;
	// Definir la aceleración de la gravedad (9.8 m/s^2) en pixeles/s^2 segun escala
	float gravedad = 9.8f / (0.00018f * 100); // 0.00018 m/pixel, escala = 1:100 
	// Definir el tiempo transcurrido entre frames 
	float deltaTime = 1.0f / 60.0f; // se ejecuta a 60 FPS
public:
	Juego();
	void loop();
	void avanzar();
	void procesarEventos();
	void actualizar();
	void dibujar();
};
