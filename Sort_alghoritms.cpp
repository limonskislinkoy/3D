#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <vector>
#include <iostream>


#define TWOPI 6.283185307


const int W = 2560;
const int H = 1440;


int main()
{

	sf::RenderWindow window(sf::VideoMode(W, H), "My window");


	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}


		window.clear(sf::Color::Black);


		window.display();
	}

	return 0;
}