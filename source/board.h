#ifndef BOARD_H
#define BOARD_H

#include "masu.h"
#include <array>

class Board
{
public:
    Board();
    const Masu& operator()(int suji, int dan) const
    {
        return board[suji-1][dan-1];
    }
    unsigned char mochi(int teban, int kind) const
    {
        return mochiGoma[teban][kind];
    }

private:
    std::array<std::array<Masu,9>,9> board;
    std::array<std::array<unsigned char,7>,2> mochiGoma;
    Masu& set(int suji, int dan)
    {
        return board[suji-1][dan-1];
    }
};

#endif // BOARD_H
