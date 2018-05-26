#include "koma.h"

QString to_string(Koma k)
{
    const QString names[14] = {
        "歩兵", "香車", "桂馬", "銀将", "角行", "飛車", "金将", "王将",
        "と金", "成香", "成桂", "成銀", "竜馬", "竜王"
    };
    return names[static_cast<size_t>(k)];
}


QString to_csa(Koma k)
{
    const QString names[14] = {
        "FU", "KY", "KE", "GI", "KA", "HI", "KI", "OU",
        "TO", "NY", "NK", "NG", "UM", "RY"
    };
    return names[static_cast<size_t>(k)];
}

