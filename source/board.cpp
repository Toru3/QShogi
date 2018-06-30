#include "board.h"

Board::Board()
{
    set(1,1) = Masu(Koma::KYO,  Teban::GOTE);
    set(2,1) = Masu(Koma::KEI,  Teban::GOTE);
    set(3,1) = Masu(Koma::GIN,  Teban::GOTE);
    set(4,1) = Masu(Koma::KIN,  Teban::GOTE);
    set(5,1) = Masu(Koma::OU,   Teban::GOTE);
    set(6,1) = Masu(Koma::KIN,  Teban::GOTE);
    set(7,1) = Masu(Koma::GIN,  Teban::GOTE);
    set(8,1) = Masu(Koma::KEI,  Teban::GOTE);
    set(9,1) = Masu(Koma::KYO,  Teban::GOTE);
    set(2,2) = Masu(Koma::KAKU, Teban::GOTE);
    set(8,2) = Masu(Koma::HI,   Teban::GOTE);
    for(int i=1; i<=9; i++){
        set(i, 3) = Masu(Koma::FU, Teban::GOTE);
    }
    for(int i=1; i<=9; i++){
        set(i, 7) = Masu(Koma::FU, Teban::SENTE);
    }
    set(8,8) = Masu(Koma::KAKU, Teban::SENTE);
    set(2,8) = Masu(Koma::HI,   Teban::SENTE);
    set(1,9) = Masu(Koma::KYO,  Teban::SENTE);
    set(2,9) = Masu(Koma::KEI,  Teban::SENTE);
    set(3,9) = Masu(Koma::GIN,  Teban::SENTE);
    set(4,9) = Masu(Koma::KIN,  Teban::SENTE);
    set(5,9) = Masu(Koma::OU,   Teban::SENTE);
    set(6,9) = Masu(Koma::KIN,  Teban::SENTE);
    set(7,9) = Masu(Koma::GIN,  Teban::SENTE);
    set(8,9) = Masu(Koma::KEI,  Teban::SENTE);
    set(9,9) = Masu(Koma::KYO,  Teban::SENTE);
    for(int i=0; i<2; i++){
        for(int j=0; j<7; j++){
            mochiGoma[i][j]=0;
        }
    }
#if 0
    set(1,4) = Masu(Koma::TO,   Teban::GOTE);
    set(2,4) = Masu(Koma::NKYO, Teban::GOTE);
    set(3,4) = Masu(Koma::NKEI, Teban::GOTE);
    set(4,4) = Masu(Koma::NGIN, Teban::GOTE);
    set(5,4) = Masu(Koma::UMA,  Teban::GOTE);
    set(6,4) = Masu(Koma::RYU,  Teban::GOTE);
    set(1,6) = Masu(Koma::TO,   Teban::SENTE);
    set(2,6) = Masu(Koma::NKYO, Teban::SENTE);
    set(3,6) = Masu(Koma::NKEI, Teban::SENTE);
    set(4,6) = Masu(Koma::NGIN, Teban::SENTE);
    set(5,6) = Masu(Koma::UMA,  Teban::SENTE);
    set(6,6) = Masu(Koma::RYU,  Teban::SENTE);
    for(int i=0; i<2; i++){
        for(int j=0; j<7; j++){
            mochiGoma[i][j]=88;
        }
    }
#endif
}

bool move(int from_suji, int from_dan, int to_suji, int to_dan)
{
    if(from_suji==to_suji && from_dan==to_dan){ return false; }
    const Masu& from = (*this)(from_suji, from_dan);
    if(from.empty()){ return false; }
    const Masu& to = (*this)(to_suji, to_dan);
    if(!to.empty()){
        mochiGoma[1-static_cast<size_t>(to.get_teban())][static_cast<size_t>(to.get_koma())]++;
    }
    set(to_suji, to_dan) = from;
    set(from_suji, from_dan) = Masu();
    qDebug() << QStringLiteral("%1%2%3%4%5%6")
        .arg((from.get_teban()==Teban::SENTE ? "+" : "-"))
        .arg(from_suji).arg(from_dan)
        .arg(to_suji).arg(to_dan)
        .arg(to_csa(from.get_koma()));
    return true;
}
