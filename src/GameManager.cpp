#include <iostream>
#include "Types.hpp"
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

    if (!this->m_font.loadFromFile("./asset/font/Poppins-Bold.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
        this->~GameManager();
    }

    if (!this->m_bounceSFX.loadFromFile("./asset/sound/bounce.wav"))
    {
        std::cout << "Failed to load bounce sfx" << std::endl;
        this->~GameManager();
    }

    this->m_soundBuffer.setBuffer(this->m_bounceSFX);

    this->m_clockDisplay.setPosition(sf::Vector2f(screenSize.x / 2, 0));
    this->m_clockDisplay.setFillColor(sf::Color::White);
    this->m_clockDisplay.setFont(this->m_font);

    this->m_playerScore.setPosition(sf::Vector2f(100, 0));
    this->m_playerScore.setFillColor(sf::Color::White);
    this->m_playerScore.setFont(this->m_font);
    this->m_playerScore.setString("0");

    this->m_aiScore.setPosition(sf::Vector2f(screenSize.x - 100, 0));
    this->m_aiScore.setFillColor(sf::Color::White);
    this->m_aiScore.setFont(this->m_font);
    this->m_aiScore.setString("0");

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

    this->m_clock.restart();

    while (this->m_window.isOpen())
    {
        while (this->m_window.pollEvent(this->m_event))
        {
            this->eventPollHandler();
        }
        this->m_time = this->m_clock.getElapsedTime();
        this->m_clockDisplay.setString(sf::String(std::to_string((i64)this->m_time.asSeconds())));

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
    this->m_ball.update(this->m_window.getSize(), this->m_score);
    this->m_AI.update(this->m_window.getSize(), this->m_ball);
    this->m_player.update(this->m_window.getSize(), this->m_event);

    this->m_AI.collide(this->m_ball, this->m_soundBuffer);
    this->m_player.collide(this->m_ball, this->m_soundBuffer);

    this->m_playerScore.setString(std::to_string(this->m_score.player));
    this->m_aiScore.setString(std::to_string(this->m_score.ai));
}

void Pong::GameManager::screenUpdateHandler()
{
    this->m_window.draw(this->m_ball.getShape());
    this->m_window.draw(this->m_player.getShape());
    this->m_window.draw(this->m_AI.getShape());
    this->m_window.draw(this->m_clockDisplay);
    this->m_window.draw(this->m_playerScore);
    this->m_window.draw(this->m_aiScore);
}