#ifndef PADDLE_HPP
#define PADDLE_HPP

#include "SFML/Graphics.hpp"
#include "Entity.hpp"
#include "Position.hpp"

namespace Pong
{
    class Ball : public Entity
    {
    public:
        Ball(sf::Vector2f startingPos);
        ~Ball();

    private:
        sf::Vector2f m_reset_pos;
        sf::RectangleShape m_hitbox;
        sf::CircleShape m_shape;
    };
}

#endif