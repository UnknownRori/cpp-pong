#include "Paddle.hpp"

/**
 * @brief Do some house keeping
 *
 */
Pong::Paddle::~Paddle() {}

/**
 * @brief Construct Paddle object with given starting position
 *
 * @param startingPos
 */
Pong::Paddle::Paddle() {}

/**
 * @brief Get the position of the paddle
 *
 * @return const sf::Vector2f
 */
const sf::Vector2f Pong::Paddle::getPos()
{
    return this->m_shape.getPosition();
}

/**
 * @brief Get the size of the paddle
 *
 * @return const sf::Vector2f
 */
const sf::Vector2f Pong::Paddle::getSize()
{
    return this->m_shape.getSize();
}

/**
 * @brief Get the shape of the paddle
 *
 * @return const sf::RectangleShape&
 */
const sf::RectangleShape &Pong::Paddle::getShape()
{
    return this->m_shape;
}

/**
 * @brief Move the paddle using passed offset vector
 *
 * @param moveOffset
 */
void Pong::Paddle::move(const sf::Vector2f &moveOffset)
{
    this->m_shape.move(moveOffset);
}

/**
 * @brief Set the Paddle into new position
 *
 * @param newPosition
 */
void Pong::Paddle::setPos(const sf::Vector2f &newPosition)
{
    this->m_shape.setPosition(newPosition);
}