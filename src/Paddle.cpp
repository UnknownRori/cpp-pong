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

bool Pong::Paddle::collide(Pong::Ball &ball)
{
    // Ball
    const auto ballSize = ball.getShape().getRadius();
    const auto ballPosition = ball.getShape().getPosition();

    // Paddle
    const auto paddlePosition = this->m_shape.getPosition();
    const auto paddleSize = this->m_shape.getSize();

    sf::Rect<float> paddleRect(paddlePosition, paddleSize);
    sf::Rect<float> ballRect(ballPosition, sf::Vector2f(ballSize, ballSize));

    if (paddleRect.intersects(ballRect))
        ball.collisionEvent();

    return false;
}

void Pong::Paddle::move(const sf::Vector2u &screenSize, const sf::Vector2f &offset)
{
    if (screenSize.x > this->getPos().x + this->getSize().x && 0 < this->getPos().x)
        this->m_shape.move(offset);
}