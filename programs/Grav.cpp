 

#include <SFML/Graphics.hpp>
#include <iostream>


const int W = 2560;
const int H = 1440;
const int MAX_OBJ = 1000;
const float Air_str = 0.9;
float GRAV_STRANGE = 80;

const float Mass_zero = 100000;
//const int G = 6.67408 * pow(10,-11);


int g_id = 0;


class Obj
{

    public:

        int id = -1;
        int type = -1;
        float x = -1;
        float y = -1;

        float mass = -1;

        float vx = -1;
        float vy = -1;

        float ax = -1;
        float ay = -1;

        float fx = -1;
        float fy = -1;

        bool moveable = 1;

        void grav_on_tick();
        void on_tick();
};

Obj g_mas[MAX_OBJ];


void Obj::grav_on_tick() {
    float xo, yo, lx, ly, angle, f;
    for (int i = 0; i < g_id; i++) {
        if (i!=id){ 
            xo = g_mas[i].x;
            yo = g_mas[i].y;
            lx = xo - x ;
            ly = yo - y ;
            
            if ((lx * lx + ly * ly) > 1700){
                angle = atan2(ly, lx);

                f = sqrt((g_mas[i].mass * mass) / (lx * lx + ly * ly))/ GRAV_STRANGE;
                fx += f * cos(angle);
                fy += f * sin(angle);
            }

        }
    }
}

void Obj::on_tick() {
    fx = 0;
    fy = 0;
    grav_on_tick();
    
    fx *= Air_str;
    fy *= Air_str;

    ax = fx / mass;
    ay = fy / mass;

    vx += ax;
    vy += ay;
    if(moveable ==1){
        x += vx;
        y += vy;
    }

}







void create_obj(int xid, int xtype, int xx, int xy, int xmass, int xvx, int xvy, int xax, int xay, int xfx, int xfy, int xmoveable) {
    Obj obj;
    obj.id = xid;
    obj.type = xtype;
    obj.x = xx;
    obj.y = xy;
    obj.mass = xmass;

    obj.vx = xvx;
    obj.vy = xvy;

    obj.ax = xax;
    obj.ay = xay;

    obj.fx = xfx;
    obj.fy = xfy;

    obj.moveable = xmoveable;

    
    g_mas[xid] = obj;
    g_id++;
}


int main()
{
    create_obj(g_id, 0, W/2, H/2, Mass_zero, 0, 0, 0, 0, 0, 0, 0);
    

   // sf::Font font;
    //font.loadFromFile("arial.ttf");


    //sf::Text text;
    //text.setFont(font);
   //text.setCharacterSize(24);
   // text.setFillColor(sf::Color::White);
   
    sf::RenderWindow window(sf::VideoMode(W, H), "My window");
    sf::CircleShape circle(10.f);
    circle.setFillColor(sf::Color(100, 250, 50));

    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(10.f, 10.f)),
        sf::Vertex(sf::Vector2f(150.f, 150.f))
    };

    window.setActive(true);
    //sf::Clock clock;

    while (window.isOpen())
    {
        //g_mas[0].mass *= 1.0001;

        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i position = sf::Mouse::getPosition();
                create_obj(g_id, 0, position.x,position.y, 1, 0, 0, 0, 0, 0, 0, 1);
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                Obj g_mas[MAX_OBJ];
                g_id = 0;
                create_obj(g_id, 0, W / 2, H / 2, Mass_zero, 0, 0, 0, 0, 0, 0, 0);
            }

            if (event.type == sf::Event::MouseWheelMoved)
            {
                std::cout << GRAV_STRANGE<<std::endl;
                if (event.mouseWheel.delta < 0) { GRAV_STRANGE *= 1.1; }
                else {  GRAV_STRANGE *= 0.9; }

                if (GRAV_STRANGE < 0.0001) {GRAV_STRANGE = 0.0001;}
                 
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) { std::cout <<" Grav: " << GRAV_STRANGE << "   mass: " << g_mas[0].mass << std::endl; }
        }

        window.clear(sf::Color::Black);
        //text.setString(std::to_string(g_id));
        //text.setPosition(10, 10);
        //window.draw(text);

        //text.setString(std::to_string(GRAV_STRANGE));
       // text.setPosition(50, 50);
        //window.draw(text);

        for (int i = 0; i < g_id; i++) {
            g_mas[i].on_tick();
            if (g_mas[i].type == 0) {
                
                circle.setPosition(g_mas[i].x, g_mas[i].y);
                window.draw(circle);
                //line[0] = sf::Vertex(sf::Vector2f(g_mas[i].x, g_mas[i].y));
                //line[1] = sf::Vertex(sf::Vector2f(g_mas[i].x+g_mas[i].vx, g_mas[i].y + g_mas[i].vy));
                //ñwindow.draw(line, 2, sf::Lines);
            }
            //std::cout << g_mas[i].id << std::endl;
        }
        window.display();
    }

    return 0;
}