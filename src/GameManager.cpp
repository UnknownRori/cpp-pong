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
}

/**
 * @brief
 *
 * @param title
 * @param screenSize
 */
void Pong::GameManager::init(std::string &title, sf::Vector2u &screenSize)
{
    __LOG("GameManager init");
    this->m_window.setFramerateLimit(60);
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
            if (this->m_event.type == sf::Event::Closed)
                this->~GameManager();
        }

        this->m_window.display();
    }
}