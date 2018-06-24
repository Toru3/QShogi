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
        return board[suji-1][dan-1];
    }
    unsigned char mochi(int teban, int kind) const
    {
        return mochiGoma[teban][kind];
    }
    bool move(int from_suji, int from_dan, int to_suji, int to_dan)
    {
        Masu t = (*this)(from_suji, from_dan);
        set(to_suji, to_dan) = t;
        set(from_suji, from_dan) = Masu();
        qDebug() << QStringLiteral("%1%2%3%4%5%6")
            .arg((t.get_teban()==Teban::SENTE ? "+" : "-"))
            .arg(from_suji).arg(from_dan)
            .arg(to_suji).arg(to_dan)
            .arg(to_csa(t.get_koma()));
        return true;
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
