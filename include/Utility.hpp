#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "SFML/Graphics.hpp"

namespace Pong
{
    /**
     * @brief Simple function that do bounce stuff in y axis
     *
     * @param src
     */
    template <typename T>
    void bounce(T &src)
    {
        src = -src;
    }
}

#endif