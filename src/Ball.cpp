#include "Utility.hpp"
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
const sf::CircleShape &Pong::Ball::getShape() const
{
    return this->m_shape;
}

void Pong::Ball::setPos(const sf::Vector2f &newPosition)
{
    this->m_shape.setPosition(newPosition);
}

void Pong::Ball::reset()
{
    this->m_currentSpeed = this->m_baseSpeed;
    this->m_shape.setPosition(this->m_reset_pos);
}

void Pong::Ball::update(const sf::Vector2u &screenSize)
{
    if (this->m_shape.getPosition().y > (screenSize.y - this->m_shape.getRadius()))
        Pong::bounce<float>(this->m_currentSpeed.y);

    if (this->m_shape.getPosition().y < 1)
        Pong::bounce<float>(this->m_currentSpeed.y);

    if (this->m_shape.getPosition().x < 1 || this->m_shape.getPosition().x > screenSize.x)
        this->reset();

    this->m_shape.move(this->m_currentSpeed);
}

void Pong::Ball::setSize(float radius)
{
    this->m_shape.setRadius(radius);
}

void Pong::Ball::collisionEvent()
{
    this->m_currentSpeed.y = rand() % 3 - 1;
    Pong::bounce<float>(this->m_currentSpeed.y);
    Pong::bounce<float>(this->m_currentSpeed.x);
}