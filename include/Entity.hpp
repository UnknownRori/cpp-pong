#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "SFML/Graphics.hpp"

namespace Pong
{
    class Entity
    {
    public:
        Entity();
        virtual ~Entity();
        virtual void update(sf::Vector2f &screen_size);
        virtual void isCollide(Entity &entity);
        virtual void collideEvent();
    };
}

#endif