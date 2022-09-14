#include <SFML/Graphics.hpp>
#include <iostream>

#define PI 3.14159265

/*

{-1,200,1,0 },   // lemon = 4
{0,100,-1,0 },
{1,50,-1,0 },
{2,10,1,0 }















*/

















const int W = 2560;
const int H = 1440;


 float Acceleration = 0.001;
 float Trs = 360.0;
//settings
const int Number_lines = 4;
long Number_v = Number_lines * 2;
long long Number_points = 10000000;
int settings[Number_lines][4] = { 
    
    {-1,200,1,PI },
    {0,100,-2,0 },
    {1,50,-3,0 },
    {2,10,-4,0 }
};
int g_id = 0;

sf::VertexArray line(sf::Lines, 2);
sf::Clock clock1;
sf::RenderWindow window(sf::VideoMode(W, H), "My window");
sf::Vertex point[1];


class Rline {
public:
    int fromid = 0;
    long id = 0;
    float lenght = 0;
    float speed = 0;
    float angle = 0;
    sf::Vector2f startpoint;
    sf::Vector2f endpoint;
    void on_tick();
};

Rline g_mas[Number_lines];

void Rline::on_tick() {
    int n = id * 2;
    if (id == 0) { startpoint = sf::Vector2f(W / 2, H / 2); }
    else { startpoint = g_mas[fromid].endpoint; }
    
    angle += speed *  Acceleration;
    if (angle > PI * 2) { angle = fmod(angle, PI * 2); }
    //angle += speed * clock1.getElapsedTime().asMicroseconds() * Acceleration;
    if (id == 0) { std::cout << angle << std::endl; }
    

    endpoint = sf::Vector2f(startpoint.x + lenght * cos(angle) , startpoint.y + lenght * sin(angle));
    line[n] = sf::Vertex((startpoint), (sf::Color::White));
    line[n+1] = sf::Vertex((endpoint), (sf::Color::White));
}



void create_rline(int xfromid,float xlenght,float xspeed,float xangle) {
    Rline rline;
    rline.fromid = xfromid;
    rline.id = xfromid + 1;
    rline.lenght = xlenght;
    rline.speed = xspeed;
    rline.angle = xangle;

    

    g_mas[g_id] = rline;
    g_id++;

   

}






int main()
{
    bool PAUSE = false;
   
    for (int i = 0; i < Number_lines; i++) {
        create_rline(settings[i][0], settings[i][1], settings[i][2], settings[i][3]);
    }
    long long count_frames=0;
  
    
    
    window.setActive(true);
 
    while (window.isOpen())
    {
        count_frames++;
        clock1.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { PAUSE = true; }

            if (event.type == sf::Event::MouseWheelMoved)
            {
                std::cout << Acceleration << std::endl;
                if (event.mouseWheel.delta > 0) { Acceleration *= 1.3; }
                else { Acceleration *= 0.7; }

                if (Acceleration < 0) { Acceleration = 0; }

            }


        }
        for(int i = 0 ; i< Number_lines; i++)
        {
            g_mas[i].on_tick();
        }

        point[0].position = line[(Number_lines-1)*2+1].position;
        point[0].color = sf::Color::White;
        

        //window.clear(sf::Color::Black);
        window.draw(line);
        window.draw(point,1,sf::Points);
        window.display();

        while (PAUSE)
        {
            sf::Event event;
            while (window.pollEvent(event))
            {

                if (event.type == sf::Event::Closed)
                    window.close();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { PAUSE = false; }
            }
            window.display();
        }
    }

    return 0;
}