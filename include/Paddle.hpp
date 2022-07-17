#ifndef PADDLE_HPP
#define PADDLE_HPP

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Entity.hpp"
#include "Ball.hpp"
#include "PaddlePosition.hpp"

namespace Pong
{
    class Paddle : public Entity
    {
    protected:
        Pong::PaddlePosition m_position;
        sf::Vector2f m_baseSpeed = sf::Vector2f(0.0f, 0.25f);
        sf::RectangleShape m_shape;

    public:
        Paddle();

        // Do some housekeeping
        virtual ~Paddle();

        // Get the Entity Size
        const sf::Vector2f getSize();

        // Get the current Entity position
        const sf::Vector2f getPos();

        // Set the paddle into new position
        void setPos(const sf::Vector2f &newPosition);

        void setSize(const sf::Vector2f &newSize);

        virtual void collide(Pong::Ball &ball, sf::Sound &sound);

        // Get the paddle shape
        const sf::RectangleShape &getShape();

        void move(const sf::Vector2u &screenSize, const sf::Vector2f &offset);
    };
}

#endif