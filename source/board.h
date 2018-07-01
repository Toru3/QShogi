#ifndef BOARD_H
#define BOARD_H

#include "masu.h"
#include <array>
#include <QDebug>

class Board
{
public:
    Board();
    const Masu& operator()(int suji, int dan) const
    {
        Q_ASSERT(1<=suji && suji<=9);
        Q_ASSERT(1<=dan && dan<=9);
        return board[suji-1][dan-1];
    }
    unsigned char mochi(int teban, int kind) const
    {
        Q_ASSERT(teban==static_cast<int>(Teban::SENTE) || teban==static_cast<int>(Teban::GOTE));
        Q_ASSERT(0<=kind && kind<7);
        return mochiGoma[teban][kind];
    }
    bool move(int from_suji, int from_dan, int to_suji, int to_dan);

private:
    std::array<std::array<Masu,9>,9> board;
    std::array<std::array<unsigned char,7>,2> mochiGoma;
    Masu& set(int suji, int dan)
    {
        Q_ASSERT(1<=suji && suji<=9);
        Q_ASSERT(1<=dan && dan<=9);
        return board[suji-1][dan-1];
    }
    bool checkMove(int from_suji, int from_dan, int to_suji, int to_dan);
};

#endif // BOARD_H
