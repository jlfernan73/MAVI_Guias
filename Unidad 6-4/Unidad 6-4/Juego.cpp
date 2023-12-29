#include "Juego.h"
#include "disparo.h"


Juego::Juego() {
	App = new RenderWindow(sf::VideoMode(1200, 900, 32), "Unidad 6-4: Wild physics - Tiro al disco");
	App->setFramerateLimit(60);
	miraPlayer = new Mira();
	disco = new Disco;
	balazo = new Balazo;
	panel = new Panel;
}
void Juego::loop() {
	while (App->isOpen()) {
		avanzar();
		procesarEventos();
		actualizar();
		dibujar();
	}
}
void Juego::avanzar() {
	if (reinicio) {
		// se define la posición y velocidad nula inicial del disco
		disco->setPosition(50, 750);
		disco->setVelocity(0, 0);
		tInicio = clock.restart(); //se reinicia el tiempo
		reinicio = false;
		dSano = true;
	}
	// monitorea el tiempo transcurrido
	if (!reinicio) {
		tPasado = clock.getElapsedTime();
	}
	// a los 0,5 segundos se lanza el disco
	if (tPasado.asSeconds() > 0.5 && !dLanzado) {
		dLanzado = true;
		// se eligen dos valores aleatorios para la aceleración de lanzamiento en x y en y
		acX = (rand() % (10) + 10) * 2500.0f;
		acY = (rand() % (10) + 10) * 3000.0f;
		// se calculan y aplican las velocidades iniciales en x y en y
		disco->setVelocity(acX*deltaTime, acY*deltaTime);
	}
	// el disco lanzado viaja a velocidad constante en x pero acelerado hacia abajo en y por la gravedad
	if (dLanzado) {
		disco->setVelocity(disco->getVelX(), (disco->getVelY()-gravedad*deltaTime));
		disco->setPosition(disco->getX() + disco->getVelX()*deltaTime, disco->getY() - disco->getVelY()*deltaTime);
	}
}
void Juego::procesarEventos() {
	while (App->pollEvent(evt)) {
		switch (evt.type) {
		case sf::Event::Closed:
			App->close();
			break;
		case sf::Event::MouseButtonPressed:
			sf::Vector2i miraPos = sf::Mouse::getPosition(*App);
			//chequea si el disparo impacta en el disco
			if (dLanzado) {
				impacto = disparo(miraPos.x, miraPos.y, disco->getX(), disco->getY());
			}
			//acciones si hubo impacto en disco
			if (impacto && dLanzado && dSano) {
				balazo->setPos(disco->getX(), disco->getY());  // ubica el disco roto
				panel->setPuntos(1); // suma un punto
				dSano = false;  // disco roto
				tRoto = clock.getElapsedTime(); // tiempo del impacto
			}
			break;
		}
	}
}
void Juego::actualizar() {
	//posiciona la mira en el cursor si el juego está activo
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*App);
	miraPlayer->mover(mousePosition.x, mousePosition.y);
	//reinicia el lanzamiento si el disco sale de la pantalla
	if (disco->getX() > 1250 || disco->getY() > 800) {
		reinicio = true;
		dLanzado = false;
		impacto = false;
	}
}
void Juego::dibujar() {
	// dibuja todo lo relativo al juego
	App->clear();
	// dibuja el disco sólo si está sano
	if (dSano) {
		disco->dibujar(App);
	}
	panel->dibujar(App);
	// dibuja el disco roto por 0,5 segundos si hubo impacto
	if (impacto && (clock.getElapsedTime() - tRoto).asSeconds() < 0.5) {
		balazo->dibujar(App);
	}
	// dibuja la mira
	miraPlayer->dibujar(App);
	App->display();
}
