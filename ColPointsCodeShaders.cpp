#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    // create the window
    sf::Window window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);

    // activate the window
    window.setActive(true);

  
    
    // run the main loop
    bool running = true;
    while (running)
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                // end the program
                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {
                // adjust the viewport when the window is resized
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

        // clear the buffers
        

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
        //std::cout << "111";

        glBegin(GL_QUADS);

        glVertex3f(-50.f, -50.f, -50.f);
        glVertex3f(-50.f, 50.f, -50.f);
        glVertex3f(50.f, 50.f, -50.f);
        glVertex3f(50.f, -50.f, -50.f);

        glVertex3f(-50.f, -50.f, 50.f);
        glVertex3f(-50.f, 50.f, 50.f);
        glVertex3f(50.f, 50.f, 50.f);
        glVertex3f(50.f, -50.f, 50.f);

        glVertex3f(-50.f, -50.f, -50.f);
        glVertex3f(-50.f, 50.f, -50.f);
        glVertex3f(-50.f, 50.f, 50.f);
        glVertex3f(-50.f, -50.f, 50.f);

        glVertex3f(50.f, -50.f, -50.f);
        glVertex3f(50.f, 50.f, -50.f);
        glVertex3f(50.f, 50.f, 50.f);
        glVertex3f(50.f, -50.f, 50.f);

        glVertex3f(-50.f, -50.f, 50.f);
        glVertex3f(-50.f, -50.f, -50.f);
        glVertex3f(50.f, -50.f, -50.f);
        glVertex3f(50.f, -50.f, 50.f);

        glVertex3f(-50.f, 50.f, 50.f);
        glVertex3f(-50.f, 50.f, -50.f);
        glVertex3f(50.f, 50.f, -50.f);
        glVertex3f(50.f, 50.f, 50.f);
        
        glEnd();

        
        // draw...

        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }

    // release resources...

    return 0;
}