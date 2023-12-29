#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>

int main() {
	// Definir radio del círculo
	const float radius = 30.0f;
	const float diameter = 2 * radius;
	// Definir la posición inicial del objeto 
	sf::Vector2f position(400-radius, 0);
	// Definir la velocidad del objeto en el eje y y su valor inicial 
	float speed = 0.0f;  // la bola está quieta inicialmente
	// Definir la aceleración de la gravedad (9.8 m/s^2) en pixeles/s^2 segun escala
	float acceleration = 9.8f/(0.00018f*100); // 0.00018 m/pixel, escala = 1:100 
	// Definir el tiempo transcurrido entre frames 
	float deltaTime = 1.0f / 60.0f; // se ejecuta a 60 FPS
	bool released = false;

	// Definir el objeto 
	sf::CircleShape object(radius);
	object.setFillColor(sf::Color::Green);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Ejercicio 6-3: Bounce (Space: suelta la bola; Esc: reinicia)");
	window.setFramerateLimit(60);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				// Barra espaciadora para soltar la bola
				if (event.key.code == sf::Keyboard::Space) {
					released = true;
				}
				// Tecla Escape para reiniciar
				if (event.key.code == sf::Keyboard::Escape) {
					released = false;
					speed = 0.0f;
					position.y = 0;
				}
				break;
			}
		}
		// Calcular velocidad de la bola
		if (released) {
			speed += acceleration * deltaTime;
		}
		// Actualizar la posición de la bola en Y en función de la velocidad
		position.y += speed * deltaTime;
		// Chequea si llega a la base
		if (position.y > (600-diameter)) {
			position.y = (600-diameter);
			speed = -0.75f * speed; // rebota con una velocidad del 75%
		}
		// Mostrar en la ventana 
		window.clear();
		object.setPosition(position);
		window.draw(object);
		window.display();
	}
	return 0;
}

