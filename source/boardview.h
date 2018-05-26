#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include "board.h"
#include <QGraphicsView>
#include <QImage>
#include <QRect>
#include <QWidget>
#include <array>

class BoardView : public QGraphicsView
{
public:
    BoardView(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);

private:
    QImage mGameBoard;
    QImage mGrid;
    std::array<std::array<QImage, 14>, 2> komas;
    Board board;
    void setAlpha(int alpha);
    void drawBoardGrid(QPainter& qPainter);
    void drawKoma(QPainter& qPainter);
};

#endif // BOARDVIEW_H
