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
    public:
        // ¯\_(ツ)_/¯
        Entity();

        // ¯\_(ツ)_/¯
        virtual ~Entity();

        // Do some update stuff
        virtual void update(sf::Vector2f &screen_size);

        // Check if the thing is collide or not
        virtual bool isCollide(Entity &entity);

        // Logic for the collide stuff
        virtual void collideEvent();

        virtual void reset();

        virtual void setPos(const sf::Vector2f &newPosition);

        virtual void move(const sf::Vector2f &moveOffset);
    };
}

#endif