#include "Log.hpp"
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
Pong::Paddle::Paddle()
{
    this->m_shape.setOutlineColor(sf::Color::White);
    this->m_shape.setSize(sf::Vector2f(20, 100));
}

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
void Pong::Paddle::move()
{
    __DEBUG("Paddle Move");
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

void Pong::Paddle::setSize(const sf::Vector2f &newSize)
{
    this->m_shape.setSize(newSize);
}