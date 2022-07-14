#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include <vector>
#include "SFML/Graphics.hpp"
#include "Entity.hpp"

namespace Pong
{
    class GameManager
    {
    public:
        GameManager(std::string &title, std::size_t &width, std::size_t &height);
        void start();
        void loop();

    private:
        void eventPollHandler();
        void screenUpdateHandler();
        void updateHandler();
        void reset();

        // Game Resource
        bool m_reset = false;
        sf::Event m_event;
        sf::WindowHandle m_window;
        std::vector<Pong::Entity> m_entityPoll;
    };
}

#endif