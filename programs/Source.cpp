/* 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


using namespace sf;

const int W = 2560;
const int H = 1440;
const int elements = W;
const float Wf = 2560.f;
const float Hf = 1440.f;


bool diagonal = true;
long long timer = 0;
std::vector<unsigned short int> errs;

RenderWindow window(VideoMode(W, H), "BackGround");

sf::Vertex line[] =
{
	sf::Vertex(sf::Vector2f(0,   0), sf::Color::Red, sf::Vector2f(0,  0)),
	sf::Vertex(sf::Vector2f(0, 0), sf::Color::Red, sf::Vector2f(0, 10)),
};
void checkerr(unsigned short int* a) {
	errs.clear();
	for (int i = 1; i < elements; i++) {
		if (a[i] < a[i - 1]) {

			errs.push_back(i);
			//std::cout << errs.size() << std::endl;
		}

	}

}


int dg(int i) {
	if (diagonal) {
		return i;
	}
	else {
		return elements - i - 1;
	}
}

void rsort(unsigned short int* a) {
	unsigned short int t;
	unsigned short int h;
	for (int i = 0; i < 100; i++) {
		t = rand() % W;
		h = rand() % W;
		if (t > h) { std::swap(t, h); }
		if (a[t] > a[h]) { std::swap(a[t], a[h]); break; }
		else {
			if (!errs.empty()) {
				if (a[errs[0]] < a[errs[0] - 1]) {
					std::swap(a[errs[0]], a[errs[0] - 1]); errs.erase(errs.begin());
				}
			}

		}
	}




}
int checksort(unsigned short int* a) {
	for (int i = 1; i < elements; i++) {
		if (a[i] < a[i - 1]) {
			std::cout << a[i - 1] << " " << a[i] << " " << i << std::endl;
			return false;
		}

	}
	return true;
}

void refresh_start(unsigned short int* a) {
	std::cout << diagonal;
	diagonal = not(diagonal);
	std::cout << diagonal;
	window.clear(Color::Black);
	for (int i = 0; i < W; i++) {
		a[i] = rand() % H;
		line[0] = Vector2f(dg(i), 0);
		line[1] = Vector2f(dg(i), Hf);
		line->color = sf::Color::Black;
		window.draw(line, 2, sf::Lines);

		line[0] = Vector2f(dg(i), a[i]);
		line[1] = Vector2f(dg(i), Hf);
		line->color = sf::Color::White;
		window.draw(line, 2, sf::Lines);
		//window.display();

		//std::cout << a[i] << std::endl;
	}
}

void refresh(unsigned short int* a) {
	diagonal = not(diagonal);
	window.clear(Color::Black);
	for (int i = 0; i < W; i++) {

		line[0] = Vertex(Vector2f(dg(i),0), Color::Red);
		line[1] = Vertex(Vector2f(dg(i),Hf), Color::Blue);
		window.draw(line, 2, sf::Lines);

		line[0] = Vertex(Vector2f(dg(i), Hf), (Color::Green));
		line[0].color = Color::Green;
		line[1] = Vertex(Vector2f(dg(i), -a[i]),( Color::Cyan));
		window.draw(line, 2, sf::Lines);
		window.display();

		//std::cout << a[i] << std::endl;
	}
}


int main()
{
	window.setVerticalSyncEnabled(false);
	unsigned short int a[W];

	window.setActive();

	refresh_start(a);


	while (window.isOpen())
	{	
		
		//window.clear(Color::Black);
		//window.setFramerateLimit(60);
		timer++;
		if (timer % 1000 == 0) {
			checkerr(a);
			//std::cout << checksort(a);
			if (checksort(a)) { refresh(a); }
		}

		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)

				window.close();
		}
		for (int i = 0; i < elements; i++) {
			line[0] = Vertex(Vector2f(dg(i), 0), Color::Black);
			line[1] = Vertex(Vector2f(dg(i), Hf), Color::Black);
			window.draw(line, 2, sf::Lines);

			line[0] = Vertex(Vector2f(dg(i), Hf), (Color::White));
			line[1] = Vertex(Vector2f(dg(i), a[i]), (Color::White));
			window.draw(line, 2, sf::Lines);

		}

		rsort(a);
		window.display();


	}

	return 0;
}
*/