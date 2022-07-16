#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "Ball.hpp"
#include "PlayerPaddle.hpp"
#include "AIPaddle.hpp"
#include "Score.hpp"

namespace Pong
{
    class GameManager
    {
    public:
        sf::Sound m_soundBuffer;

    private:
        // SFML Event Poll
        sf::Event m_event;

        // SFML Sound
        sf::SoundBuffer m_bounceSFX;

        // SFML Window
        sf::RenderWindow m_window;

        // This is where to store the entity
        Pong::PlayerPaddle m_player;
        Pong::AIPaddle m_AI;
        Pong::Ball m_ball;

        // This is where to store the score
        Pong::Score m_score;

        // Counter
        sf::Clock m_clock;
        sf::Time m_time;

        // Text
        sf::Font m_font;
        sf::Text m_clockDisplay;
        sf::Text m_playerScore;
        sf::Text m_aiScore;

    public:
        // ¯\_(ツ)_/¯
        GameManager();

        // Do some housekeeping
        ~GameManager();

        // Initialize the window
        void init(std::string &title, sf::Vector2u &screenSize);

    private:
        // Main Game loop
        void loop();

        // This is where to define the control
        void eventPollHandler();

        // This is where to draw the entity
        void screenUpdateHandler();

        // This is where to run update method on entity
        void updateHandler();

        // This is for reseting the game
        void reset();
    };
}

#endif