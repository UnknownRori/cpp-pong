#ifndef AI_PADDLE_HPP
#define AI_PADDLE_HPP

#include "SFML/Graphics.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"

namespace Pong
{
    /**
     * @brief Special paddle that controlled by ai
     *
     */
    class AIPaddle : public Paddle
    {
    public:
        // Create special paddle
        AIPaddle();

        // Do some housekeeping
        ~AIPaddle();

        void update(const sf::Vector2u &screenSize, const Pong::Ball &ball);
    };
}

#endif