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
        Paddle(sf::Vector2f startingPos);
        virtual ~Paddle();
        void update(sf::Vector2f &screen_size);
        void isCollide(Entity &entity);
        void collideEvent();

    private:
        Pong::Position m_position = Pong::Position::NONE;
        sf::RectangleShape m_shape;
    };
}

#endif