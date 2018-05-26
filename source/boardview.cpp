#include "boardview.h"

BoardView::BoardView(QWidget *parent) : QGraphicsView(parent)
{
    mGameBoard.load("image/ban/ban_kaya_a.png");
    mGrid.load("image/masu/masu_dot_xy.png");
    const QString koma[14] = {
        "fu", "kyo",  "kei",  "gin",  "kaku", "hi", "kin", "ou",
        "to", "nkyo", "nkeu", "ngin", "uma",  "ryu"
    };
    for(int i=0; i<2; i++){
        for(int j=0; j<14; j++){
            QString path("image/koma/koma_kinki/");
            path += i==0 ? "S" : "G";
            path += koma[j];
            path += ".png";
            komas[i][j].load(path);
        }
    }
}

void BoardView::paintEvent(QPaintEvent *)
{
    QPainter qPainter(viewport());
    drawBoardGrid(qPainter);
    drawKoma(qPainter);
}

void BoardView::setAlpha(int alpha)
{
    const int width = mGameBoard.width();
    const int height = mGameBoard.height();
    for(int x=0; x<width; x++){
        for(int y=0; y<height; y++){
            QColor color(mGameBoard.pixel(x, y));
            color.setAlpha(alpha);
            mGameBoard.setPixel(x, y, color.rgba());
        }
    }
}

void BoardView::drawBoardGrid(QPainter& qPainter)
{
    constexpr int komaHeight = 48;
    constexpr int mochiGomaKinds = 7;
    constexpr int komaDaiHeiht = komaHeight*mochiGomaKinds+3*(mochiGomaKinds-1);
    int offset_x = 0;
    QRect gMochiGomaRect(0, 0, 45, komaDaiHeiht);
    qPainter.drawImage(gMochiGomaRect, mGameBoard);
    offset_x += 48;

    QRect rect(offset_x, 0, mGameBoard.width(), mGameBoard.height());
    qPainter.drawImage(rect, mGameBoard);
    qPainter.drawImage(rect, mGrid);
    offset_x += 410 + 3;

    QRect sMochiGomaRect(offset_x, mGameBoard.height()-komaDaiHeiht, 45, komaDaiHeiht);
    qPainter.drawImage(sMochiGomaRect, mGameBoard);
}


void BoardView::drawKoma(QPainter& qPainter)
{
    const int width = komas[0][0].width();
    const int height = komas[0][0].height();
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            const Masu& m = board(i+1, j+1);
            if(!m.empty()){
                QRect rect(48+width*(8-i)+11, height*j+11, width, height);
                qPainter.drawImage(rect, komas[static_cast<int>(m.get_teban())][static_cast<int>(m.get_koma())]);
            }
        }
    }
}
