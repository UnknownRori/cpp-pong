#include "PlayerPaddle.hpp"

// TODO Implement proper logic

Pong::PlayerPaddle::PlayerPaddle() {}
Pong::PlayerPaddle::~PlayerPaddle() {}

void Pong::PlayerPaddle::update(const sf::Vector2u &screenSize, const sf::Event &event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->move(screenSize, this->m_baseSpeed);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->move(screenSize, sf::Vector2f(0, -this->m_baseSpeed.y));
    }
}