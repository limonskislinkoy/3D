#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>

const int NN = 100;
const int MM = 100;

const int winW = 1000;
const int winH = 1000;


std::vector<std::vector<int>> fire(NN, std::vector<int>(MM, 0));
std::vector<std::vector<int>> newfire(NN, std::vector<int>(MM, 0));
sf::RenderWindow window(sf::VideoMode(winW, winH), "Fire");

sf::Texture texture;
sf::Image image;
sf::Sprite sprite(texture);

sf::Shader shader;
sf::Clock clk;

void setRandomStartFire()
{
    for (int i = 0; i < MM; i++) {
        if (51>i and i>49 ) {
            fire[NN - 1][i] = std::rand() % 100;
        }
        else {
            fire[NN - 1][i] = 0;
        }
        //std::cout << fire[NN-1][i];
    }
}

sf::RectangleShape rectangle(sf::Vector2f(120, 50));
void DrawFire() {
    for (int i = 0; i < MM; i++) {
        for (int j = 0; j < NN; j++) {
            rectangle.setFillColor(sf::Color(fire[i][j],0,0));
            rectangle.setPosition(sf::Vector2f(10.0 * j, 10.0 * i));
            window.draw(rectangle);
        }
    }
    
}

void FireMove() {
    for (int y = 0; y < MM - 1; y++) {
        for (int x = 0; x < NN; x++) {
            newfire[y][x] = fire[y][x];
        }
    }


    //std::cout << "Addr newfire and fire:" << &newfire << "  " << &fire << std::endl;
    for (int y = 1; y < MM; y++) {
        for (int x = 0; x < NN; x++) {
            //if (fire[y][x] > 0) { std::cout << "Fire!"<<"\n"; }
            newfire[y-1][x] += fire[y][x]*0.5;
            //newfire[y-1][x] -= 10;
            if (x < NN - 1) {

                newfire[y][x + 1] += fire[y][x] * 0.5;
                //if (newfire[y][x + 1] > 0) { std::cout << "Yep!:" << x<<" "<<y << "\n"; std::cin >> fire[0][0]; }
                //newfire[y][x + 1] -= 10;
                if (newfire[y][x+1] < 0) {
                    newfire[y][x+1] = 0;
                }
            }
            if (x > 0) {
                newfire[y][x - 1] += fire[y][x] * 0.5;
                //newfire[y][x - 1] -= 10;
                
                if (newfire[y][x-1] < 0) {
                    newfire[y][x-1] = 0;
                }
            }
            

            if (newfire[y - 1][x] < 0){
                newfire[y - 1][x] = 0;
            }
            

            fire[y][x] = 0;
            

        }
    }

    for (int y = 0; y < MM - 1; y++) {
        for (int x = 0; x < NN; x++) {
            fire[y][x] = newfire[y][x];
        }
    }
}


void SmoothWindow() {
    float r=0, g=0, b=0;
    int count = 0;
    sf::Color color;
    texture.update(window);
    std::cout << texture.Pixels;
    std::cin >> r;
    image = texture.copyToImage();
    
    
    for (int y = 0; y < winH; y++) {
        for (int x = 0; x < winW; x++) {
            count = 0;
            if (y > 0) { color = image.getPixel(x, y - 1); r += color.r; g += color.g; b += color.b; count += 1; }
            if (y < 999) { color = image.getPixel(x, y +1); r += color.r; g += color.g; b += color.b; count += 1;}
            if (x > 0) { color = image.getPixel(x-1, y ); r += color.r; g += color.g; b += color.b; count += 1;}
            if (x < 999) { color = image.getPixel(x+1, y); r += color.r; g += color.g; b += color.b; count += 1;}

            r = r / count;
            g = g / count;
            b = b / count;
            color = sf::Color(r, g, b);

            image.setPixel(x, y, color);
        }
    }
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    window.clear(sf::Color::Black);
    window.draw(sprite);
    window.display();
    
}



int main()
{
    // create the window
    
    std::srand(std::time(nullptr));
    

    setRandomStartFire();
    texture.create(winW, winH);
    shader.loadFromFile("outshader.frag", sf::Shader::Fragment); // load the shader
    
    if (!shader.isAvailable()) {
        std::cout << "The shader is not available\n";
    }
    std::cout << "Ok" << "\n";
    // Set the resolution parameter (the resoltion is divided to make the fire smaller)
    shader.setUniform("resolution", sf::Vector2f(winW / 2, winH / 2));

  
    clk.restart(); // start the timer

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Set the others parameters who need to be updated every frames
        shader.setUniform("time", clk.getElapsedTime().asSeconds());

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        shader.setUniform("mouse", sf::Vector2f(mousePos.x, mousePos.y - winH / 2));

        // Draw the sprite with the shader on it
        window.clear();
        window.draw(sprite, &shader);
        window.display();
        //setRandomStartFire();
        //FireMove();
        //DrawFire();
        //                             //SmoothWindow();
        //window.display();
    }

    return 0;
}