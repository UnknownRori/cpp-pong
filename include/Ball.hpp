#ifndef BALL_HPP
#define BALL_HPP

#include "SFML/Graphics.hpp"
#include "Entity.hpp"
#include "Position.hpp"

namespace Pong
{
    class Ball : public Entity
    {
    public:
        sf::Vector2f m_reset_pos;

    protected:
        sf::CircleShape m_shape;

    public:
        // Create ball entity
        Ball();

        // Do some housekeeping
        ~Ball();

        void update(const sf::Vector2u &screenSize);

        void reset();

        void setPos(const sf::Vector2f &newPosition);

        void setSize(const float radius);

        const sf::CircleShape &getShape();
    };
}

#endif