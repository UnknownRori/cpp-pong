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
        Paddle();

        // Do some housekeeping
        virtual ~Paddle();

        virtual void move();

        // Get the Entity Size
        const sf::Vector2f getSize();

        // Get the current Entity position
        const sf::Vector2f getPos();

        // Set the paddle into new position
        void setPos(const sf::Vector2f &newPosition);

        void setSize(const sf::Vector2f &newSize);

        // Get the paddle shape
        const sf::RectangleShape &getShape();
    };
}

#endif