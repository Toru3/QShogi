#include "boardview.h"
constexpr int komaWidth = 43;
constexpr int komaHeight = 48;
constexpr int boardWidth = 410;
constexpr int boardHeight = 454;
constexpr int mochiGomaKinds = 7;
constexpr int komaDaiHeiht = komaHeight*mochiGomaKinds+3*(mochiGomaKinds-1);

BoardView::BoardView(QWidget *parent) : QGraphicsView(parent)
{
    connect(this,SIGNAL(komaFocusChanged()),this->viewport(),SLOT(update()));
    mGameBoard.load("image/ban/ban_kaya_a.png");
    mGrid.load("image/masu/masu_dot_xy.png");
    const QString koma[14] = {
        "fu", "kyo",  "kei",  "gin",  "kaku", "hi", "kin", "ou",
        "to", "nkyo", "nkei", "ngin", "uma",  "ryu"
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
    mFocus.load("image/focus/focus_bold_b.png");
    focus.setX(-1);
    focus.setY(-1);
    focused_grid.setX(-1);
    focused_grid.setY(-1);
}

void BoardView::paintEvent(QPaintEvent *)
{
    QPainter qPainter(viewport());
    drawBoardGrid(qPainter);
    drawKoma(qPainter);
}

void BoardView::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        const QPoint point = event->pos();
        QRect gKomaDai(0, 0, komaWidth+2, komaDaiHeiht);
        QRect boardRect(gKomaDai.width()+3, 0, boardWidth, boardHeight);
        QRect sKomaDai(boardRect.x()+boardRect.width()+3,
                boardHeight-komaDaiHeiht, komaWidth+2, komaDaiHeiht);
        for(int j=0; j<mochiGomaKinds; j++){
            QRect rect(0, (komaHeight+3)*(6-j), komaWidth, komaHeight);
            if(rect.contains(point)){
                QPoint old_focused_grid = focused_grid;
                focused_grid.setX(0);
                focused_grid.setY(6-j);
                qDebug() << focused_grid;
                if(old_focused_grid.x()>=0 && old_focused_grid.y()>=0){
                    board.move(old_focused_grid.x(), old_focused_grid.y(),
                            focused_grid.x(), focused_grid.y());
                    focused_grid.setX(-1);
                    focused_grid.setY(-1);
                }
            }
        }
        for(int j=0; j<mochiGomaKinds; j++){
            QRect rect(48+410+3, boardHeight-komaDaiHeiht+(komaHeight+3)*j, komaWidth, komaHeight);
            if(rect.contains(point)){
                QPoint old_focused_grid = focused_grid;
                focused_grid.setX(10);
                focused_grid.setY(j+3);
                qDebug() << focused_grid;
                if(old_focused_grid.x()>=0 && old_focused_grid.y()>=0){
                    board.move(old_focused_grid.x(), old_focused_grid.y(),
                            focused_grid.x(), focused_grid.y());
                    focused_grid.setX(-1);
                    focused_grid.setY(-1);
                }
            }
        }
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                QRect rect(komaWidth+5+komaWidth*(8-i)+11, komaHeight*j+11, komaWidth, komaHeight);
                if(rect.contains(point)){
                    QPoint old_focused_grid = focused_grid;
                    focused_grid.setX(i+1);
                    focused_grid.setY(j+1);
                    qDebug() << focused_grid;
                    if(old_focused_grid.x()>=0 && old_focused_grid.y()>=0){
                        board.move(old_focused_grid.x(), old_focused_grid.y(),
                                focused_grid.x(), focused_grid.y());
                        focused_grid.setX(-1);
                        focused_grid.setY(-1);
                    }
                }
            }
        }
        if(gKomaDai.contains(point) || boardRect.contains(point) || sKomaDai.contains(point)){
            focus = point;
            emit komaFocusChanged();
        }
    }else if(event->button()==Qt::RightButton){
        focus.setX(-1);
        focus.setY(-1);
        focused_grid.setX(-1);
        focused_grid.setY(-1);
        qDebug() << focused_grid;
        emit komaFocusChanged();
    }
}

void BoardView::setAlpha(int alpha)
{
    for(int x=0; x<boardWidth; x++){
        for(int y=0; y<boardHeight; y++){
            QColor color(mGameBoard.pixel(x, y));
            color.setAlpha(alpha);
            mGameBoard.setPixel(x, y, color.rgba());
        }
    }
}

void BoardView::drawBoardGrid(QPainter& qPainter)
{
    QRect gKomaDai(0, 0, komaWidth+2, komaDaiHeiht);
    QRect boardRect(gKomaDai.width()+3, 0, boardWidth, boardHeight);
    QRect sKomaDai(boardRect.x()+boardRect.width()+3, boardHeight-komaDaiHeiht, komaWidth+2, komaDaiHeiht);
    qPainter.drawImage(gKomaDai, mGameBoard);
    qPainter.drawImage(sKomaDai, mGameBoard);
    qPainter.drawImage(boardRect, mGameBoard);
    qPainter.drawImage(boardRect, mGrid);
}

void BoardView::drawKoma(QPainter& qPainter)
{
    constexpr int index[7] = {5, 4, 6, 3, 2, 1, 0};
    for(int j=0; j<mochiGomaKinds; j++){
        unsigned char n = board.mochi(1, index[j]);
        if(n==0){ continue; }
        QRect rect(0, (komaHeight+3)*(6-j), komaWidth, komaHeight);
        if(focused_grid.x()==0 && focused_grid.y()==6-j){ qPainter.drawImage(rect, mFocus); }
        qPainter.drawImage(rect, komas[1][index[j]]);
        if(n>=2){
            char s[4]={0};
            sprintf(s, "%d", static_cast<int>(n));
            qPainter.drawText(rect, s);
        }
    }
    for(int j=0; j<mochiGomaKinds; j++){
        unsigned char n = board.mochi(0, index[j]);
        if(n==0){ continue; }
        QRect rect(48+410+3, boardHeight-komaDaiHeiht+(komaHeight+3)*j, komaWidth, komaHeight);
        if(focused_grid.x()==10 && focused_grid.y()==j+3){ qPainter.drawImage(rect, mFocus); }
        qPainter.drawImage(rect, komas[0][index[j]]);
        if(n>=2){
            char s[4]={0};
            sprintf(s, "%d", static_cast<int>(n));
            qPainter.drawText(rect, s);
        }
    }
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            const Masu& m = board(i+1, j+1);
            if(m.empty()){ continue; }
            QRect rect(komaWidth+5+komaWidth*(8-i)+11, komaHeight*j+11, komaWidth, komaHeight);
            if(focused_grid.x()==i+1 && focused_grid.y()==j+1){ qPainter.drawImage(rect, mFocus); }
            int t = static_cast<int>(m.get_teban());
            int k = static_cast<int>(m.get_koma());
            qPainter.drawImage(rect, komas[t][k]);
        }
    }
}
