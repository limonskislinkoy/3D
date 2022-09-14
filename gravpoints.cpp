

#include <SFML/Graphics.hpp>
#include <iostream>


const int W = 1366;
const int H = 768;
const int MAX_OBJ = 1000;
const float Air_str = 1;
float GRAV_STRANGE = 2;

const float Mass_zero = 100000;
//const int G = 6.67408 * pow(10,-11);


int g_id = 0;

bool PAUSE = false;

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
    int  pozitive = 1;

    void grav_on_tick();
    void on_tick();
};

Obj g_mas[MAX_OBJ];


void Obj::grav_on_tick() {
    float xo, yo, lx, ly, angle, f, l;
    for (int i = 0; i < g_id; i++) {
        if (i != id) {
            xo = g_mas[i].x;
            yo = g_mas[i].y;
            lx = xo - x;
            ly = yo - y;
            l = (lx * lx + ly * ly);
            if ( l> 100) {
                angle = atan2(ly, lx);

                f = sqrt((g_mas[i].mass * mass) / l) / GRAV_STRANGE;
                //f = ((g_mas[i].mass * mass) / (lx * lx + ly * ly)) / GRAV_STRANGE;

                if (pozitive == g_mas[i].pozitive) { f *= -1; } // off -> f*=1;
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
    if (moveable == 1) {
        x += vx;
        y += vy;
    }

}







void create_obj(int xid, int xtype, int xx, int xy, int xmass, int xvx, int xvy, int xax, int xay, int xfx, int xfy, int xmoveable, int xpozitive) {
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
    obj.pozitive = xpozitive;

    g_mas[xid] = obj;
    g_id++;
}


int main()
{
    create_obj(g_id, 0, W / 2, H / 2, Mass_zero, 0, 0, 0, 0, 0, 0, 0, 1);


    // sf::Font font;
     //font.loadFromFile("arial.ttf");


     //sf::Text text;
     //text.setFont(font);
    //text.setCharacterSize(24);
    // text.setFillColor(sf::Color::White);

    sf::RenderWindow window(sf::VideoMode(W, H), "My window");
    //sf::CircleShape circle(10.f);
    //circle.setFillColor(sf::Color(100, 250, 50));

    sf::VertexArray points(sf::Lines, 2);
    points[0].position = sf::Vector2f(0,0);
    points[1].position = sf::Vector2f(0,0);

    window.setActive(true);
    //sf::Clock clock;
    int a,r,g,b;
    div_t divr;


    sf::Texture texture;
    texture.setSmooth(true);
    sf::Vector2u x;
    x = window.getSize();
    texture.create(x.x, x.y);
    sf::Sprite sprite(texture);



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
                create_obj(g_id, 0, position.x, position.y, 1, 0, 0, 0, 0, 0, 0, 1,-1);
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                window.clear();
                Obj g_mas[MAX_OBJ];
                g_id = 0;
                create_obj(g_id, 0, W / 2, H / 2, Mass_zero, 0, 0, 0, 0, 0, 0, 0,1);
            }

            if (event.type == sf::Event::MouseWheelMoved)
            {
                std::cout << GRAV_STRANGE << std::endl;
                if (event.mouseWheel.delta < 0) { GRAV_STRANGE *= 1.3; }
                else { GRAV_STRANGE *= 0.7; }

                if (GRAV_STRANGE < 0.0001) { GRAV_STRANGE = 0.0001; }

            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) { std::cout << " Grav: " << GRAV_STRANGE << "   mass: " << g_mas[0].mass << std::endl; }


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { PAUSE = true; }
        }

        //window.clear(sf::Color::Black);
        //text.setString(std::to_string(g_id));
        //text.setPosition(10, 10);
        //window.draw(text);

        //text.setString(std::to_string(GRAV_STRANGE));
       // text.setPosition(50, 50);
        //window.draw(text);

        for (int i = 0; i < g_id; i++) {

            //point.color = sf::Color::Black;
            //point.position = sf::Vector2f(g_mas[i].x, g_mas[i].y);
            //window.draw(&point, 1, sf::Points);
            a = (i*100)%765;
            divr = div(a, 255);
            if (divr.quot == 0) { r = a % 255; } else { r = 0;}
            if (divr.quot == 1) { g = a % 255; } else { g = 0; }
            if (divr.quot == 2) { b = a % 255; } else { b = 0; }

            points[1].position = sf::Vector2f(g_mas[i].x, g_mas[i].y);

            points[0].color = sf::Color(r, g, b);
            points[1].color = sf::Color(r, g, b);

            g_mas[i].on_tick();



            if (g_mas[i].type == 0) {

                points[0].position =sf::Vector2f(g_mas[i].x, g_mas[i].y);
                
               
                window.draw(points);
                //line[0] = sf::Vertex(sf::Vector2f(g_mas[i].x, g_mas[i].y));
                //line[1] = sf::Vertex(sf::Vector2f(g_mas[i].x+g_mas[i].vx, g_mas[i].y + g_mas[i].vy));
                //ñwindow.draw(line, 2, sf::Lines);
            }
            //std::cout << g_mas[i].id << std::endl;
        }
        texture.update(window);
        //sprite.setColor(sf::Color(0, 0, 0, 10));
        window.display();
        window.draw(sprite);
        

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