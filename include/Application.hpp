#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <string>
#include "GameManager.hpp"

namespace Pong
{
    class Application
    {
    public:
        Application(std::string title, std::size_t width, std::size_t height);
        void run();

    private:
        // Application Enviroment
        std::string m_title;
        sf::Vector2u m_screenSize;
        Pong::GameManager m_game;
    };
}

#endif