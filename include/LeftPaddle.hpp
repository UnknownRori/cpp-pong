#ifndef Right_PADDLE_HPP
#define Right_PADDLE_HPP

#include "SFML/Graphics.hpp"
#include "Paddle.hpp"

namespace Pong
{
    class LeftPaddle : public Paddle
    {
    public:
        LeftPaddle(sf::Vector2f startingPos);
        ~LeftPaddle();

    private:
        Pong::Position m_position = Pong::Position::RIGHT;
        sf::RectangleShape m_shape;
    };
}

#endif