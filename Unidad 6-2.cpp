#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>

int main() {
	// Definir radio del círculo
	const float radius = 50.0f;
	const float diameter = 2 * radius;
	// Definir la posición inicial del objeto 
	sf::Vector2f position(-1 * diameter, 300.0f);
	// Definir la velocidad del objeto en el eje x y su valor inicial 
	float speed = 50.0f;  // 50 pixeles/s
	// Definir la aceleración que se aplicará al presionar la flecha
	float acceleration = 50.0f;
	// Definir el tiempo transcurrido entre frames 
	float deltaTime = 1.0f / 60.0f; // se ejecuta a 60 FPS 

	// Definir el objeto 
	sf::CircleShape object(radius);
	object.setFillColor(sf::Color::Red);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Ejercicio 6-2: Space");
	window.setFramerateLimit(60);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					// Tecla flecha izquierda acelera hacia la izquierda (aceleracion negativa)
					if (event.key.code == sf::Keyboard::Left) {
						speed -= acceleration*deltaTime;
					}
					// Tecla flecha derecha acelera hacia la derecha (aceleración positiva)
					if (event.key.code == sf::Keyboard::Right) {
						speed += acceleration*deltaTime;
					}
					break;
			}
		}
		// Actualizar la posición del objeto en función de la velocidad 
		position.x += speed * deltaTime;

		// Chequea si se supera el borde derecho
		if (position.x > 800) {
			position.x = -1 * diameter;
		}
		// Chequea si se está por debajo del borde izquierdo
		if (position.x < -1*diameter) {
			position.x = 800;
		}

		// Mostrar todo en la ventana 
		window.clear();
		object.setPosition(position);
		window.draw(object);
		window.display();
	}
	return 0;
}

