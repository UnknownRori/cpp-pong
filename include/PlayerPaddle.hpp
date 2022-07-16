#ifndef PLAYER_PADDLE_HPP
#define PLAYER_PADDLE_HPP

#include "SFML/Graphics.hpp"
#include "Paddle.hpp"

namespace Pong
{
    /**
     * @brief Player paddle
     *
     */
    class PlayerPaddle : public Paddle
    {
    public:
        bool isPlayer = true;

    public:
        // Create Playable paddle
        PlayerPaddle();

        // Do some housekeeping
        ~PlayerPaddle();

        void update(const sf::Vector2u &screenSize, const sf::Event &event);
    };
}

#endif