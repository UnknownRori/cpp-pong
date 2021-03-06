#include "Utility.hpp"
#include "Ball.hpp"
#include "Log.hpp"
#include <chrono>
#include <random>

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
    this->m_currentSpeed = this->m_resetSpeed;
    this->m_shape.setPosition(this->m_reset_pos);
}

void Pong::Ball::update(const sf::Vector2u &screenSize, Pong::Score &score)
{
    if (this->m_shape.getPosition().y > (screenSize.y - this->m_shape.getRadius()))
        Pong::bounce<float>(this->m_currentSpeed.y);

    if (this->m_shape.getPosition().y < 1)
        Pong::bounce<float>(this->m_currentSpeed.y);

    if (this->m_shape.getPosition().x < 1 || this->m_shape.getPosition().x > screenSize.x)
    {
        if (this->m_shape.getPosition().x < 1)
            score.ai++;
        else if (this->m_shape.getPosition().x > screenSize.x)
            score.player++;

        this->reset();
    }

    this->m_shape.move(this->m_currentSpeed);
}

void Pong::Ball::setSize(float radius)
{
    this->m_shape.setRadius(radius);
}

void Pong::Ball::collisionEvent(const Pong::PaddlePosition &pos)
{
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_real_distribution<float> dist(-0.65f, 0.65f);
    auto random = dist(engine);
    this->m_currentSpeed.y = random;
    this->m_currentSpeed.x = pos * this->m_baseSpeed.x;
}

const sf::Vector2f &Pong::Ball::getPos() const
{
    return this->m_shape.getPosition();
}