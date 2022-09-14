#include "SFML/Graphics.hpp"
#include <iostream>


const int W = 1000;
const int H = 1000;
const int Startx = W/2;
const int Starty = H/2;

float px = Startx;
float py = Starty;

float lx = Startx - 200;
float ly = Starty;
float lpx = Startx - 200;
float lpy = Starty;

double g_c = 0;
int g_pc = 0;

const double PI = 3.141592653589793238462643383279502884;
const int C_Lines = 100;
double Set_l[C_Lines][3] = {
                            {170.0,0.0,0.01*10},
                            {70.0,0.0,0.21*11},
                            {170.0,0.0,0.01 * 12}
                      
                   
                            
                            


};

/*
 {100.0,0.0,1.0}


*/

void RESET() {

}

int main()
{
    sf::Clock clk;
    clk.restart();


    double a = 1.0;
    double b = 1.0;
    double f = 0;
    double mx, my, levela=1, levelb = 1;


    sf::Texture texture;
    texture.create(W, H);
    sf::Sprite sprite(texture);


    sf::RenderWindow window(sf::VideoMode(W, H), "Lissashu");
    sf::VertexArray points(sf::Points, 1);
    sf::VertexArray lines(sf::Lines, 2 * C_Lines);
    sf::VertexArray lpoints(sf::Points, 1);
    points[0].position = sf::Vector2f(px, py);

   

    sf::RectangleShape linea(sf::Vector2f(600, 2));
    linea.rotate(90);

    sf::RectangleShape lineb(sf::Vector2f(600, 2));
    lineb.rotate(90);

    sf::CircleShape circlea(200);
    circlea.setRadius(10);
    circlea.setPointCount(100);

    sf::CircleShape circleb(200);
    circleb.setRadius(10);
    circleb.setPointCount(100);
    bool mouseclicked = false;

    sf::Font font;
    font.loadFromFile("arial.ttf");
   
    sf::Text texta;
    texta.setFont(font);
    texta.setString("A");
    texta.setCharacterSize(24);
    texta.setFillColor(sf::Color::Red);
    texta.setStyle(sf::Text::Bold);
    texta.setPosition(43, 170);
    //window.draw(texta);

    sf::Text textb;
  
    textb.setFont(font);
    textb.setString("B");
    textb.setCharacterSize(24);
    textb.setFillColor(sf::Color::Blue);
    textb.setStyle(sf::Text::Bold);
    textb.setPosition(W - 57, 170);
    //window.draw(textb);




    sf::Text textda;
 
    textda.setFont(font);
    textda.setString("10");
    textda.setCharacterSize(20);
    textda.setFillColor(sf::Color::Red);
    textda.setStyle(sf::Text::Bold);
    textda.setPosition(20, 200);
   

    sf::Text textoa;
    
    textoa.setFont(font);
    textoa.setString("0");
    textoa.setCharacterSize(20);
    textoa.setFillColor(sf::Color::Red);
    textoa.setStyle(sf::Text::Bold);
    textoa.setPosition(20, 500);
 

    sf::Text textmda;
    
    textmda.setFont(font);
    textmda.setString("-10");
    textmda.setCharacterSize(20);
    textmda.setFillColor(sf::Color::Red);
    textmda.setStyle(sf::Text::Bold);
    textmda.setPosition(20, 800);
   






    sf::Text textdb;
   
    textdb.setFont(font);
    textdb.setString("10");
    textdb.setCharacterSize(24);
    textdb.setFillColor(sf::Color::Blue);
    textdb.setStyle(sf::Text::Bold);
    textdb.setPosition(W-42,H/2-290);
   

    sf::Text textob;
    
    textob.setFont(font);
    textob.setString("0");
    textob.setCharacterSize(24);
    textob.setFillColor(sf::Color::Blue);
    textob.setStyle(sf::Text::Bold);
    textob.setPosition(W - 42, H/2);
   

    sf::Text textmdb;
    
    textmdb.setFont(font);
    textmdb.setString("-10");
    textmdb.setCharacterSize(24);
    textmdb.setFillColor(sf::Color::Blue);
    textmdb.setStyle(sf::Text::Bold);
    textmdb.setPosition(W - 42, H/2+300);

    sf::Text textreset;

    textreset.setFont(font);
    textreset.setString(L"Для рестарта нажмите левую кнопку мыши");
    textreset.setCharacterSize(24);
    textreset.setFillColor(sf::Color::White);
    textreset.setStyle(sf::Text::Bold);
    textreset.setPosition(W/2-24*12,70);
    

    sf::Text textPUNK;
    textPUNK.setFont(font);
    textPUNK.setString(L"Я ПАНК");
    textPUNK.setCharacterSize(16);
    textPUNK.setFillColor(sf::Color::Black);
    textPUNK.setStyle(sf::Text::Bold);
    textPUNK.setPosition(W/2, H/2);

   
    while (window.isOpen())
    {

        //std::cout << "ok" << std::endl;

        setlocale(LC_ALL, "");
        //std::cout << sizeof(lpoints) << std::endl;
        g_c += PI/5000;
        g_pc += 1;
        sf::Event event;
        window.clear();
        window.draw(sprite);

        //                                                                   Lissashu
        //if (g_c >= () * PI*2) { a += 0.01; g_c = 0; window.clear(); texture.update(window); }
        //std::cout << g_c << std::endl;
        px = Startx+ 300*(sin(levela * g_c+f)) ;
        py = Starty+ 300*(cos(levelb * g_c)) ;

        //window.clear(sf::Color::Black);
        points[0].position = sf::Vector2f(px, py);
        window.draw(points);

        /*//                                                                     
        lx = Startx - 500;
        ly = Starty;
        for (int i = 0; i < C_Lines; i++) {
            lines[2 * i].position = sf::Vector2f(lx, ly); lines[2 * i].color = sf::Color::Red;
            lx += Set_l[i][0] * cos(Set_l[i][1] + (g_c * Set_l[i][2]));
            ly += Set_l[i][0] * sin(Set_l[i][1] + (g_c * Set_l[i][2]));
            lines[2 * i + 1].position = sf::Vector2f(lx, ly); lines[2 * i + 1].color = sf::Color::Red;
        }

        
        window.draw(lines);// will be commented if you wish hide lines*/
        lpoints[0].position = sf::Vector2f(lx, ly);
        if(g_c== PI / 5000){
            window.draw(texta);
            window.draw(textb);

            window.draw(textda);
            window.draw(textoa);
            window.draw(textmda);

            window.draw(textdb);
            window.draw(textob);
            window.draw(textmdb);

            window.draw(textreset);
            window.draw(textPUNK);

        }
        
        texture.update(window);
        

        linea.setPosition(50, 200);
        window.draw(linea);

        linea.setPosition(W - 50, 200);
        window.draw(linea);


        circlea.setPosition(50 - 10, 500 - (30 * levela));
        window.draw(circlea);

        circleb.setPosition(W - 50 - 10, 500 - (30 * levelb));
        window.draw(circleb);

        

           




        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) { mouseclicked = true; 
            
            mx = sf::Mouse::getPosition(window).x;
            my = sf::Mouse::getPosition(window).y;

            if (abs(500 - mx) < 40 && abs(my-40)<40) {
                window.clear();
                texture.update(window);
                g_c = 0;
            }

            }
            if (event.type == sf::Event::MouseButtonReleased) { mouseclicked = false; 
            mx = sf::Mouse::getPosition(window).x;
            my = sf::Mouse::getPosition(window).y;

            if (abs(mx - 50) < 20) {
                levela = (500 - my) / 30.0;
                if (levela > 10) { levela = 10; }
                if (levela < -10) { levela = -10; }
                //std::cout << "Коофициент а =" << levela << " Коофициент б =" << levelb << std::endl;

            }

            if (abs(mx - (W - 50)) < 20) {
                levelb = (500 - my) / 30;
                if (levelb > 10) { levelb = 10; }
                if (levelb < -10) { levelb = -10; }
                //std::cout << "Коофициент а =" << levela << " Коофициент б =" << levelb << std::endl;
            }
            window.clear();
            
            texture.update(window);
            g_c = 0;
            }

            
            
            
        }
        if (mouseclicked)
        {
            g_c = 0;
            //std::cout << "mouse x: " << event.mouseButton.x << std::endl;
            // std::cout << "mouse y: " << event.mouseButton.y << std::endl;
            mx= sf::Mouse::getPosition(window).x;
            my = sf::Mouse::getPosition(window).y;

            if (abs(mx - 50) < 20) {
                levela = (500 - my) / 30.0;
                if (levela > 10) { levela = 10; }
                if (levela < -10) { levela = -10; }

            }

            if (abs(mx - (W - 50)) < 20) {
                levelb = (500 - my) / 30;
                if (levelb > 10) { levelb = 10; }
                if (levelb < -10) { levelb = -10; }
            }
        }
        window.display();
    }

    return 0;
}