#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <vector>
#include <iostream>


#define TWOPI 6.283185307


const int W = 2560;
const int H = 1440;

short SineWave(double time, double freq, double amp) {
    short result;
    double tpc = 44100 / freq; // ticks per cycle
    double cycles = time / tpc;
    double rad = TWOPI * cycles;
    short amplitude = 32767 * amp;
    result = amplitude * sin(rad);
    return result;
}


int main()
{
    
    sf::RenderWindow window(sf::VideoMode(W, H), "Sorted");

    sf::SoundBuffer buffer;
    std::vector<sf::Int16> samples;

    for (int i = 0; i < 44100; i++) {
        samples.push_back(SineWave(i, 440, 0.1 ));
    }

    buffer.loadFromSamples(&samples[0], samples.size(), 1, 44100);
    sf::Sound sound;
    sound.setBuffer(buffer);
    //sound.play();
    std::cout << "Ok \n";
    

    int array_num[W];

    for (int i = 0; i < W; i++) {
        array_num[i] = std::rand()%H;
        //std::cout << array_num[i] << "\n";
    }

    
    
    
    sf::RectangleShape rectangle;

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

        window.clear(sf::Color::Black);
        for (int i = 0; i < W; i++) {
            rectangle.setPosition(i, H);
            rectangle.setSize(sf::Vector2f(1.0, -array_num[i]));
            window.draw(rectangle);
        }

        window.display();


    }

    return 0;
}