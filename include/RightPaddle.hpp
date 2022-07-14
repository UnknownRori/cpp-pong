#ifndef LEFT_PADDLE_HPP
#define LEFT_PADDLE_HPP

#include "SFML/Graphics.hpp"
#include "Paddle.hpp"

namespace Pong
{
    class RightPaddle : public Paddle
    {
    public:
        RightPaddle(sf::Vector2f startingPos);
        ~RightPaddle();

    private:
        Pong::Position m_position = Pong::Position::RIGHT;
        sf::RectangleShape m_shape;
    };
}

#endif