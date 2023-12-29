#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp> 
int main() {
	// Definir radio del círculo
	const float radius = 50.0f;
	const float diameter = 2 * radius;
	// Definir la posición inicial del objeto 
	sf::Vector2f position(-1 * diameter, 300.0f);
	// Definir la velocidad inicial del objeto en el eje x (movimiento rectilíneo uniforme) 
	float speed = 50.0f;  //en pixeles/s
	// Definir la velocidad maxima
	const float maxSpeed = 1600.0f;
	// Definir el el tiempo transcurrido (el juego se está ejecutando a 60 FPS)
	float deltaTime = 1.0f / 60.0f; 

	// Definir el objeto 
	sf::CircleShape object(radius);
	object.setFillColor(sf::Color::Blue);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Ejercicio 6-1: Fast & Furious");
	window.setFramerateLimit(60);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		// Actualizar la posición del objeto en función de la velocidad 
		position.x += speed * deltaTime;
		// Chequea si se supera el borde derecho
		if (position.x > 800) {
			position.x = -1 * diameter;
			speed *= 2; //duplica la velocidad
			//chequea si se alcanza la velocidad maxima
			if (speed > maxSpeed) {
				speed = maxSpeed;
			}
		}

		// Mostrar todo en la ventana 
		window.clear();
		object.setPosition(position);
		window.draw(object);
		window.display();
	}
	return 0;
}

