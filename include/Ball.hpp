#ifndef BALL_HPP
#define BALL_HPP

#include "SFML/Graphics.hpp"
#include "Entity.hpp"
#include "Position.hpp"

namespace Pong
{
    class Ball : public Entity
    {
    private:
        sf::Vector2f m_reset_pos;
        sf::CircleShape m_shape;

    public:
        // Create ball entity with given starting position
        Ball(sf::Vector2f startingPos);

        // Do some housekeeping
        ~Ball();
    };
}

#endif