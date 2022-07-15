#include "Ball.hpp"

// Todo Properly implement ball logic

Pong::Ball::Ball()
{
    this->m_shape.setFillColor(sf::Color::White);
}
Pong::Ball::~Ball() {}

/**
 * @brief Get the ball shape
 *
 */
const sf::CircleShape &Pong::Ball::getShape()
{
    return this->m_shape;
}

void Pong::Ball::setPos(const sf::Vector2f &newPosition)
{
    this->m_shape.setPosition(newPosition);
}

void Pong::Ball::reset()
{
    this->m_shape.setPosition(this->m_reset_pos);
}

void Pong::Ball::update(const sf::Vector2u &screenSize)
{
    // TODO implement ball movement
}

void Pong::Ball::setSize(float radius)
{
    this->m_shape.setRadius(radius);
}