#include "Log.hpp"
#include "Entity.hpp"

bool Pong::Entity::isCollide(Pong::Entity &entity)
{
    __ERROR("Entity Collide Dectetor Event");
    return false;
}

void Pong::Entity::update(sf::Vector2f &screenSize)
{
    __ERROR("Entity Update Event");
}
void Pong::Entity::collideEvent()
{
    __ERROR("Entity Collide Event");
}
void Pong::Entity::reset()
{
    __ERROR("Entity Reset");
}
Pong::Entity::~Entity()
{
    __DEBUG("Entity Destruction");
}
Pong::Entity::Entity()
{
    __DEBUG("Entity Construction");
}