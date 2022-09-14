#include <SFML/Graphics.hpp>
#include <iostream>

const int W = 1920;
const int H = 1080;

const double PI = 3.141592653589793238462643383279502884;

const int C_Vertex = 1;

sf::VertexArray mlines(sf::Lines, 4);
sf::VertexArray mpline(sf::Lines, 2);
sf::VertexArray vertex(sf::Lines, 2);

const float Speed = 0.01;
const float Multip_map = 10;

float vertexs[C_Vertex][3] = { {1.0,1.0,0.0} };

float px = 0;
float py = 0;
float pz = 0;

float sx = 0;
float sy = 0;
float sz = 0;

float ppov = 90;

float pvx = 0;

float mdx, mdy;

sf::RectangleShape rectangle(sf::Vector2f(10, 10));


sf::Vector2f rotate_point(float x, float y, float xo, float yo, float a) {
    return sf::Vector2f(xo+((x-xo) * cos(a) - (y-yo) * sin(a)),yo+( (x - xo) * sin(a) + (y - yo) * cos(a)));
}


int main()
{
    std::cout << 1;
    mlines[0].position = sf::Vector2f(20, 20);
    mlines[1].position = sf::Vector2f(25, 50);
    mlines[2].position = sf::Vector2f(60, 40);
    mlines[3].position = sf::Vector2f(90, 60);

   
    mpline[0].color = sf::Color::Red;
    mpline[1].color = sf::Color::Red;

    sf::RenderWindow window(sf::VideoMode(W, H), "My window");
    sf::RenderWindow window2(sf::VideoMode(100, 100), "My window");
    while (window.isOpen())
    {
        mpline[0].position = sf::Vector2f(px, py);
        mpline[1].position = rotate_point(px + 10, py, px, py, pvx);
        sf::Event event;
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { window.close(); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){pvx-=0.01;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {pvx += 0.01; }
        mdx = sf::Mouse::getPosition(window).x - (W / 2);
        mdy = sf::Mouse::getPosition(window).y - (H / 2);
        if (mdx != 0 or mdy != 0) { sf::Mouse::setPosition(sf::Vector2i(W / 2, H / 2), window); }
        pvx += mdx/30;
        //std::cout << mdx << " " << mdy << sf::Mouse::getPosition().x << "\n";

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { px += cos(pvx) * Speed; py += sin(pvx) * Speed; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { px -= cos(pvx) * Speed; py -= sin(pvx) * Speed; }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { px += cos(pvx-(PI/2)) * Speed; py += sin(pvx-(PI / 2)) * Speed; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { px -= cos(pvx - (PI / 2)) * Speed; py -= sin(pvx-(PI / 2)) * Speed; }

        vertex[0].color = sf::Color::Green;
        vertex[1].position=sf::Vector2f(0.0,0.0);
        window.clear();
        for (int i = 0; i < C_Vertex; i++) {
            sx = vertexs[i][0] - px;
            sy = vertexs[i][1] - py;
            sz = vertexs[i][2] - pz;
            std::cout << atan2f(1 / sy, 1 / sx) <<" "<< 1/ sx << " " << 1/sy << " " << 1/sz << " \n";
            //vertex[0].position = sf::Vector2f(W/2*(atan2f(1 / sy, 1 / sx)-0.5), H/2);
            rectangle.setPosition(sf::Vector2f(W / 2 * (atan2f(1 / sy, 1 / sx)), H / 2));
            window.draw(rectangle);
        }

        window.display();

        

        window2.clear();
        window2.draw(mlines);
        window2.draw(mpline);
        window2.display();
    }

    return 0;
}