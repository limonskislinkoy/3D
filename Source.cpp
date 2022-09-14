#include <SFML/Graphics.hpp>
#include <iostream>

const int W = 1920;
const int H = 1080;

int main()
{
    sf::Clock clk;
    clk.restart();
   
    sf::RenderWindow window(sf::VideoMode(W,H), "My window");
   
    
    sf::Texture tex;
    tex.create(W, H);
    sf::Sprite spr(tex);

    sf::Shader shader;
    shader.loadFromFile("outshader.frag", sf::Shader::Fragment); 

    if (!shader.isAvailable()) {
        std::cout << "The shader is not available\n";
    }

   
    while (window.isOpen())
    {
        shader.setUniform("iTime", clk.getElapsedTime().asSeconds());
       
        sf::Event event;
        while (window.pollEvent(event))
        {
        
            if (event.type == sf::Event::Closed)
                window.close();
        }

        shader.setUniform("uaresolution", sf::Vector2f(W, H));
        window.clear(sf::Color::Black);
        window.draw(spr, &shader);
        
        window.display();
    }

    return 0;
}