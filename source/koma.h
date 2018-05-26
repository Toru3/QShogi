#ifndef KOMA_H
#define KOMA_H

#include <QString>

enum class Koma : unsigned char
{
    FU, KYO,  KEI,  GIN,  KAKU, HI, KIN, OU,
    TO, NKYO, NKEI, NGIN, UMA,  RYU
};

QString to_string(Koma k);
QString to_csa(Koma k);

#endif // KOMA_H
