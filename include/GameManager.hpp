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
        GameManager();
        ~GameManager();
        void init(std::string &title, sf::Vector2u &screenSize);

    private:
        void loop();
        void eventPollHandler();
        void screenUpdateHandler();
        void updateHandler();
        void reset();

        // Game Resource
        bool m_reset = false;
        sf::Event m_event;
        sf::RenderWindow m_window;
        std::vector<Pong::Entity> m_entityPoll;
    };
}

#endif