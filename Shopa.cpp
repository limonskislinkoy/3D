#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
	const float winW = 1366;
	const float winH = 768;

	sf::RenderWindow window(sf::VideoMode(winW, winH), "SFML Shader Example");
	window.setMouseCursorVisible(false); // hide the cursor

	// Create a texture and a sprite for the shader
	sf::Texture tex;
	tex.create(winW, winH);
	sf::Sprite spr(tex);

	sf::Shader shader;
	shader.loadFromFile("outshader.frag", sf::Shader::Fragment); // load the shader

	if (!shader.isAvailable()) {
		std::cout << "The shader is not available\n";
	}

	// Set the resolution parameter (the resoltion is divided to make the fire smaller)
	shader.setUniform("resolution", sf::Vector2f(winW, winH));

	// Use a timer to obtain the time elapsed
	sf::Clock clk;
	clk.restart(); // start the timer

	while (window.isOpen()) {
		// Event handling
		sf::Event event;

		while (window.pollEvent(event)) {
			// Exit the app when a key is pressed
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
			}
		}

		// Set the others parameters who need to be updated every frames
		shader.setUniform("time", clk.getElapsedTime().asSeconds());

		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		shader.setUniform("mouse", sf::Vector2f(mousePos.x, mousePos.y));

		// Draw the sprite with the shader on it
		window.clear();
		window.draw(spr, &shader);
		window.display();
	}

	return 0;
}