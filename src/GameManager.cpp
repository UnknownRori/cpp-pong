#include <iostream>
#include "Log.hpp"
#include "GameManager.hpp"

Pong::GameManager::GameManager() {}

/**
 * @brief Destroy screen
 *
 */
Pong::GameManager::~GameManager()
{
    __LOG("Closing");
    this->m_window.close();
    exit(0);
}

/**
 * @brief Setting up the position, size of entity and the window
 *
 * @param title
 * @param screenSize
 */
void Pong::GameManager::init(std::string &title, sf::Vector2u &screenSize)
{
    __LOG("GameManager init");

    sf::Vector2f paddleSize = sf::Vector2f((screenSize.x / 20), (screenSize.y / 4.5));
    sf::Vector2f ballPosition = sf::Vector2f((screenSize.x / 2.6), (screenSize.y / 2.6));

    this->m_ball.setSize(screenSize.y / 50);
    this->m_ball.setPos(ballPosition);
    this->m_ball.m_reset_pos = ballPosition;

    this->m_player.setPos(sf::Vector2f(10, (screenSize.y / 2.8)));
    this->m_AI.setPos(sf::Vector2f((screenSize.x - (10 + paddleSize.x)), (screenSize.y / 2.8)));
    this->m_player.setSize(paddleSize);
    this->m_AI.setSize(paddleSize);

    this->m_window.setFramerateLimit(5);
    this->m_window.create(sf::VideoMode(screenSize.x, screenSize.y), title);

    this->loop();
}

/**
 * @brief Game loop
 *
 */
void Pong::GameManager::loop()
{
    __LOG("Start the loop");
    while (this->m_window.isOpen())
    {
        while (this->m_window.pollEvent(this->m_event))
        {
            this->eventPollHandler();
        }
        this->m_window.clear();

        this->screenUpdateHandler();
        this->updateHandler();

        this->m_window.display();
    }
}

void Pong::GameManager::eventPollHandler()
{
    switch (this->m_event.type)
    {
    case sf::Event::Closed:
        this->~GameManager();
        break;

    default:
        break;
    }
}

void Pong::GameManager::updateHandler()
{
    this->m_ball.update(this->m_window.getSize());
    this->m_AI.update(this->m_window.getSize());
    this->m_player.update(this->m_window.getSize());

    this->m_AI.collide(this->m_ball);
    this->m_player.collide(this->m_ball);
}

void Pong::GameManager::screenUpdateHandler()
{
    this->m_window.draw(this->m_ball.getShape());
    this->m_window.draw(this->m_player.getShape());
    this->m_window.draw(this->m_AI.getShape());
}