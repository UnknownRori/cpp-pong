#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "SFML/Graphics.hpp"

namespace Pong
{
    /**
     * @brief Base entity
     *
     */
    class Entity
    {
    protected:
        sf::Vector2f currentSpeed = sf::Vector2f(0, 0);
        sf::Vector2f baseSpeed = sf::Vector2f(0, 0);

    public:
        // ¯\_(ツ)_/¯
        Entity();

        // ¯\_(ツ)_/¯
        virtual ~Entity();

        // Do some update stuff
        virtual void update(const sf::Vector2u &screen_size);

        virtual void reset();

        virtual void setPos(const sf::Vector2f &newPosition);

        virtual void move();
    };
}

#endif