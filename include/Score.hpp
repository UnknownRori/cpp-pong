#ifndef SCORE_HPP
#define SCORE_HPP

#include <cstddef>

namespace Pong
{
    struct Score
    {
        std::size_t player;
        std::size_t ai;

        // TODO Put these on implementation file
        Score() : player(0), ai(0) {}

        // reset the score
        void reset();
    };
}

#endif