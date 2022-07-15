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
        bool isPlayer = false;

    public:
        // Create left paddle entity with given starting position
        PlayerPaddle(sf::Vector2f startingPos);

        // Do some housekeeping
        ~PlayerPaddle();
    };
}

#endif