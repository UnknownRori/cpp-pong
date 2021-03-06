#ifndef BALL_HPP
#define BALL_HPP

#include "SFML/Graphics.hpp"
#include "Entity.hpp"
#include "Score.hpp"
#include "PaddlePosition.hpp"

namespace Pong
{
    class Ball : public Entity
    {
    public:
        sf::Vector2f m_reset_pos;
        bool m_isCurrentlyCollide = false;

    protected:
        sf::Vector2f m_currentSpeed = sf::Vector2f(-0.25, 0);
        sf::Vector2f m_resetSpeed = sf::Vector2f(-0.25, 0);
        sf::Vector2f m_baseSpeed = sf::Vector2f(0.25, 0);
        sf::CircleShape m_shape;

    public:
        // Create ball entity
        Ball();

        // Do some housekeeping
        ~Ball();

        void update(const sf::Vector2u &screenSize, Pong::Score &score);

        void reset();

        void setPos(const sf::Vector2f &newPosition);

        void setSize(const float radius);

        const sf::Vector2f &getPos() const;

        void collisionEvent(const Pong::PaddlePosition &pos);

        const sf::CircleShape &getShape() const;
    };
}

#endif