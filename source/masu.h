#ifndef MASU_H
#define MASU_H

#include "koma.h"

enum class Teban : unsigned char
{
    SENTE, GOTE
};

class Masu
{
public:
    Masu(){ isEmpty = true; }
    Masu(Koma k, Teban t)
    {
        isEmpty = false;
        koma = k;
        teban = t;
    }
    bool empty() const
    {
        return isEmpty;
    }
    Teban get_teban() const
    {
        return teban;
    }
    Koma get_koma() const
    {
        return koma;
    }
private:
    bool isEmpty;
    Koma koma;
    Teban teban;
};

#endif // MASU_H
