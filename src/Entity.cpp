#include "Log.hpp"
#include "Entity.hpp"

void Pong::Entity::update(const sf::Vector2u &screenSize)
{
    __DEBUG("Entity Update Event");
}

void Pong::Entity::reset()
{
    __DEBUG("Entity Reset");
}

Pong::Entity::~Entity()
{
    __DEBUG("Entity Destruction");
}

Pong::Entity::Entity()
{
    __DEBUG("Entity Construction");
}

void Pong::Entity::move()
{
    __DEBUG("Entity Move");
}

void Pong::Entity::setPos(const sf::Vector2f &moveOffset)
{
    __DEBUG("Entity set new position")
}