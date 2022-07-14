#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <string>
#include "GameManager.hpp"

namespace Pong
{
    /**
     * @brief Main entry point
     *
     */
    class Application
    {
    private:
        // Application Enviroment
        std::string m_title;
        sf::Vector2u m_screenSize;
        Pong::GameManager m_game;

    public:
        // Initialize the application
        Application(std::string title, std::size_t width, std::size_t height);

        // Run the application
        void run();
    };
}

#endif