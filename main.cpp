#include "SFML/Graphics.hpp"

int main()
{
    // Create window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML try");

    while (window.isOpen())
    {
        // SFML Event
        sf::Event event;

        while (window.pollEvent(event))
        {
            // Allow close window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update the window
        window.display();
    }

    return 0;
}