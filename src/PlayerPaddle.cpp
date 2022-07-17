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

void Pong::PlayerPaddle::collide(Pong::Ball &ball, sf::Sound &sound)
{
    // Ball
    const auto ballSize = ball.getShape().getRadius();
    const auto ballPosition = ball.getShape().getPosition();

    // Paddle
    const auto paddlePosition = this->m_shape.getPosition();
    const auto paddleSize = this->m_shape.getSize();

    sf::Rect<float> paddleRect(paddlePosition, paddleSize);
    sf::Rect<float> ballRect(ballPosition, sf::Vector2f(ballSize, ballSize));

    if (paddleRect.intersects(ballRect) && !ball.m_isCurrentlyCollide)
    {
        ball.m_isCurrentlyCollide = true;
        ball.collisionEvent(this->m_position);
        sound.play();
    }
    else if (!paddleRect.intersects(ballRect))
    {
        ball.m_isCurrentlyCollide = false;
    }
}