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
//RenderWindow window(VideoMode(500, 200), "SFML Works!");
//
//int main()
//{
//	
//	CircleShape circle(50.f);
//	circle.setFillColor(Color(230, 0, 230)); // закрашиваем наш круг 
//	circle.setOutlineThickness(15.f); // устанавливаем толщину контура круга
//	circle.setOutlineColor(Color(80, 220, 50)); // устанавливаем цвет контура
//	circle.move(16, 15); // перемещаем наш круг для корректного отображения в окне
//	//window.draw(circle); // отрисовка круга
//
//	sf::Texture texture;
//	texture.create(500, 200);
//	Sprite sprite(texture);
//	while (window.isOpen())
//	{
//		
//
//		
//		
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
//		texture.update(window);
//		window.display();
//		
//		window.draw(sprite);
//	
//
//	}
//
//	return 0;
//}
