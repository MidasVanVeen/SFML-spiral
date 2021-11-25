#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <math.h>

// main function
int main() {
    sf::RenderWindow window(sf::VideoMode(800,800), "drawing test");
    window.setFramerateLimit(60);

    // initiate variables
    float turnfraction = 0;
    float turnfractionincrease = 0.000005;
    int numPoints = 1000;
    int zoom = 200;

    // main loop
    while (window.isOpen()) {
        // check if closed
        sf::Event ev;
        while (window.pollEvent(ev)) {
            switch (ev.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (ev.key.code == sf::Keyboard::Space) {
                        turnfractionincrease = 0;
                    }
                    if (ev.key.code == sf::Keyboard::Hyphen) {
                        if (zoom > 0) {zoom-=10;}
                    }
                    if (ev.key.code == sf::Keyboard::Equal) {
                        zoom+=10;
                    }
                    break;
                case sf::Event::KeyReleased:
                    if (ev.key.code == sf::Keyboard::Space) {
                        turnfractionincrease = 0.000005;
                    }
                    break;
            }
        }
    
        // clear window
        window.clear(sf::Color(40,42,54));

        // render points
        for (int i = 0;i<numPoints;i++) {
            float dst = i / (numPoints - 1.f); // distance
            float angle = 2 * M_PI * turnfraction * i; // angle 
            float x = dst * cos(angle) * zoom + 400; // x coordinate
            float y = dst * sin(angle) * zoom + 400; // y coordinate

            // render points to screen
            sf::CircleShape point(4); // size: 4
            point.setPosition(x,y);
            point.setFillColor(sf::Color(181,152,225)); // set color
            window.draw(point); // draw
        }
        window.display(); // update window
        turnfraction += turnfractionincrease; // increase turnfraction
    }
    return 0;
}
