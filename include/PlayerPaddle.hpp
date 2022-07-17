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
        Pong::PaddlePosition m_position = Pong::PaddlePosition::LEFT;

    public:
        // Create Playable paddle
        PlayerPaddle();

        // Do some housekeeping
        ~PlayerPaddle();

        void update(const sf::Vector2u &screenSize, const sf::Event &event);

        void collide(Pong::Ball &ball, sf::Sound &sound);
    };
}

#endif