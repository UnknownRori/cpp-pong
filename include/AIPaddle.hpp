#ifndef AI_PADDLE_HPP
#define AI_PADDLE_HPP

#include "SFML/Graphics.hpp"
#include "Paddle.hpp"

namespace Pong
{
    /**
     * @brief Special paddle that controlled by ai
     *
     */
    class AIPlayer : public Paddle
    {
    public:
        // Create left paddle entity with given starting position
        AIPlayer(sf::Vector2f startingPos);

        // Do some housekeeping
        ~AIPlayer();
    };
}

#endif