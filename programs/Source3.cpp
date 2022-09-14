//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <vector>
//
//#include <chrono>
//#include <thread>
//
//using namespace sf;
//
//const int W = 2560;
//const int H = 1440;
//const int elements = W;
//const float Wf = 2560.f;
//const float Hf = 1440.f;
//
//
//bool diagonal = false;
//long long timer = 0;
//std::vector<unsigned short int> errs;
//
//RenderWindow window(VideoMode(W, H), "SFML Works!");
//sf::Vertex line[] =
//{
//	sf::Vertex(sf::Vector2f(0, 0)),
//	sf::Vertex(sf::Vector2f(0, 0))
//};
//
//
//int dg(int i) {
//	if (diagonal) {
//		return i;
//	}
//	else {
//		return elements - i - 1;
//	}
//}
//
//void drawline(unsigned short int i, unsigned short int a) {
//	//if (!diagonal) { i= elements - i - 1; }
//	if (a == 0) {
//		std::cout << i << std::endl;
//	}
//
//	line[0] = Vertex(Vector2f(dg(i), 0), Color::Black);
//	line[1] = Vertex(Vector2f(dg(i), Hf), Color::Black);
//	window.draw(line, 2, sf::Lines);
//
//
//	line[0] = Vertex(Vector2f(dg(i), Hf), (Color::White));
//	line[1] = Vertex(Vector2f(dg(i), (Hf - a)), (Color::White));
//	window.draw(line, 2, sf::Lines);
//}
//
//
//void checkerr(unsigned short int* a) {
//	errs.clear();
//	for (int i = 1; i < elements; i++) {
//		if (a[i] < a[i - 1]) {
//
//			errs.push_back(i);
//			//std::cout << errs.size() << std::endl;
//		}
//
//	}
//
//}
//
//
//
//
//void rsort(unsigned short int* a) {
//	unsigned short int t;
//	unsigned short int h;
//	for (int i = 0; i < 50; i++) {
//
//		t = rand() % W;
//		h = rand() % W;
//		if (t > h) { std::swap(t, h); }
//		if (a[t] > a[h]) { std::swap(a[t], a[h]); break; }
//		else {
//			if (!errs.empty()) {
//				if (a[errs[0]] < a[errs[0] - 1]) {
//					std::swap(a[errs[0]], a[errs[0] - 1]); errs.erase(errs.begin());
//				}
//			}
//
//		}
//	}
//
//	if (a[t] < a[h]) {
//		drawline(t, a[t]);
//		drawline(h, a[h]);
//	}
//
//
//
//
//}
//int checksort(unsigned short int* a) {
//	for (int i = 1; i < elements; i++) {
//		if (a[i] < a[i - 1]) {
//			std::cout << a[i - 1] << " " << a[i] << " " << i << std::endl;
//			return false;
//		}
//
//	}
//	return true;
//}
//
//
//void refresh(unsigned short int* a, int start = 0) {
//	diagonal = not(diagonal);
//	for (int i = 0; i < W; i++) {
//		if (start == 1) {
//			a[i] = rand() % H;
//		}
//		drawline(i, a[i]);
//		window.display();
//		drawline(i, a[i]);
//		window.display();
//		//if (i>500){ std::this_thread::sleep_for(std::chrono::seconds(3)); }
//
//	}
//
//}
//
//
//int main()
//{
//
//	sf::Texture texture;
//	Vector2u x;
//	x = window.getSize();
//	texture.create(x.x, x.y);
//	Sprite sprite(texture);
//
//	window.setVerticalSyncEnabled(false);
//	unsigned short int a[W];
//
//	//window.setActive();
//
//	refresh(a, 1);
//	std::this_thread::sleep_for(std::chrono::seconds(3));
//
//	//window.setFramerateLimit(60);
//
//
//	while (window.isOpen())
//	{
//		timer++;
//
//		if (timer % 1000 == 0) {
//			checkerr(a);
//			//std::cout << checksort(a);
//			if (checksort(a)) { refresh(a, 1); }
//		}
//
//		Event event;
//		while (window.pollEvent(event))
//		{
//
//			if (event.type == Event::Closed)
//
//				window.close();
//		}
//
//		rsort(a);
//		texture.update(window);
//		window.display();
//		window.draw(sprite);
//
//
//	}
//	return 0;
//}
