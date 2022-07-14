#ifndef PADDLE_HPP
#define PADDLE_HPP

#include "SFML/Graphics.hpp"
#include "Entity.hpp"
#include "Position.hpp"

namespace Pong
{
    class Paddle : public Entity
    {
    public:
        bool isPlayer = false;

    protected:
        Pong::Position m_position = Pong::Position::NONE;
        sf::RectangleShape m_shape;

    public:
        // Create paddle entity with given starting position
        Paddle(sf::Vector2f startingPos);

        // Do some housekeeping
        virtual ~Paddle();

        // Get the Entity Size
        const sf::Vector2f getSize();

        // Get the current Entity position
        const sf::Vector2f getPos();

        // Move the entity to new given position
        void move(sf::Vector2f new_pos);
    };
}

#endif