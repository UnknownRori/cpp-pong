#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include <array>
#include "SFML/Graphics.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"
#include "Score.hpp"

namespace Pong
{
    class GameManager
    {
    private:
        // SFML Event Poll
        sf::Event m_event;

        // SFML Window
        sf::RenderWindow m_window;

        // This is where to store the entity
        std::array<Pong::Paddle, 2> m_paddle;
        Pong::Ball m_ball;

        // This is where to store the score
        Pong::Score score;

    public:
        // ¯\_(ツ)_/¯
        GameManager();

        // Do some housekeeping
        ~GameManager();

        // Initialize the window
        void init(std::string &title, sf::Vector2u &screenSize);

    private:
        // Main Game loop
        void loop();

        // This is where to define the control
        void eventPollHandler();

        // This is where to draw the entity
        void screenUpdateHandler(Pong::Entity &entity);

        // This is where to run update method on entity
        void updateHandler(Pong::Entity &entity);

        // This is for reseting the game
        void reset();
    };
}

#endif