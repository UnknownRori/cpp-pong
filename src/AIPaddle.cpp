#include "AIPaddle.hpp"
#include "Log.hpp"

Pong::AIPaddle::AIPaddle() {}
Pong::AIPaddle::~AIPaddle() {}

void Pong::AIPaddle::update(const sf::Vector2u &screenSize, const Pong::Ball &ball)
{
    if (this->getPos().y < ball.getPos().y)
    {
        this->move(screenSize, this->m_baseSpeed);
    }

    if (this->getPos().y > ball.getPos().y)
    {
        this->move(screenSize, sf::Vector2f(0, -this->m_baseSpeed.y));
    }
}