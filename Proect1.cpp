#include <SFML/Graphics.hpp>
#include <iostream>

const int W = 1920;
const int H = 1080;
const int Startx = 1100;
const int Starty = 540;

float px = Startx;
float py = Starty;

float lx = Startx-200;
float ly = Starty;
float lpx = Startx - 200;
float lpy = Starty;

double g_c = 0;
int g_pc = 0;

const double PI = 3.141592653589793238462643383279502884;
const int C_Lines = 100;
double Set_l[C_Lines][3] = {
                            {70.0,0.0,0.1},
                            {70.0,0.0,0.101},
                            {70.0,0.0,0.102},

                            
                            {70.0,0.0,0.103},
                            {70.0,0.0,0.104},

                            
                            {70.0,0.0,0.105},
                            {70.0,0.0,0.106}
                             
                           };

/*
 {100.0,0.0,1.0}  


*/

int main()
{
    sf::Clock clk;
    clk.restart();
   

    

 
    sf::Texture texture;
    texture.create(W, H);
    sf::Sprite sprite(texture);
    

    sf::RenderWindow window(sf::VideoMode(W,H), "My window");
    sf::VertexArray points(sf::Points, 1);
    sf::VertexArray lines(sf::Lines, 2*C_Lines);
    sf::VertexArray lpoints(sf::Points, 1);
    points[0].position = sf::Vector2f(px, py);
    while (window.isOpen())
    {
        
        g_c += 0.001;
        g_pc += 1;
        sf::Event event;
        window.clear();
        window.draw(sprite);
        while (window.pollEvent(event))
        {
        
            if (event.type == sf::Event::Closed)
                window.close(); 
        }

        //                                                                   Lissashu
        px += (sin(9*g_c))/1.0;
        py += (cos(20*g_c))/1.0;
        
        //window.clear(sf::Color::Black);
        points[0].position = sf::Vector2f(px, py);
        window.draw(points);

        //                                                                     HUINA
        lx = Startx - 500;
        ly = Starty;
        for (int i = 0; i < C_Lines; i++) {
            lines[2 * i].position = sf::Vector2f(lx, ly); lines[2 * i].color = sf::Color::Red;
            lx += Set_l[i][0] * cos(Set_l[i][1] + (g_c * Set_l[i][2]));
            ly += Set_l[i][0] * sin(Set_l[i][1] + (g_c * Set_l[i][2]));
            lines[2*i+1].position = sf::Vector2f(lx, ly); lines[2 * i+1].color = sf::Color::Red;
        }
        
        lpoints[0].position = sf::Vector2f(lx, ly);
        window.draw(lpoints);
        texture.update(window);
        window.draw(lines);// will be commented if you wish hide lines
        
        window.display();
    }

    return 0;
} 