#include "Application.hpp"

int main()
{
    Pong::Application app("Pong", 800, 600);
    app.run();

    return EXIT_SUCCESS;
}