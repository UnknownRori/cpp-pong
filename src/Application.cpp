#include "Application.hpp"

/**
 * @brief Construct a new Pong::Application::Application object
 *
 * @param title
 * @param width
 * @param height
 */
Pong::Application::Application(std::string title, std::size_t width, std::size_t height)
    : m_title(title)
{
    this->m_screenSize.x = width;
    this->m_screenSize.y = height;
}

/**
 * @brief Run the application
 *
 */
void Pong::Application::run()
{
    this->m_game.init(this->m_title, this->m_screenSize);
}