#include "Ball.hpp"

// Todo Properly implement ball logic

Pong::Ball::Ball() {}
Pong::Ball::~Ball() {}

/**
 * @brief Get the ball shape
 *
 */
const sf::CircleShape &Pong::Ball::getShape()
{
    return this->m_shape;
}