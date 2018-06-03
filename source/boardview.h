#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include "board.h"
#include <QGraphicsView>
#include <QImage>
#include <QRect>
#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QTimer>
#include <array>

class BoardView : public QGraphicsView
{
    Q_OBJECT
public:
    BoardView(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);

signals:
    void komaFocusChanged();

private:
    QImage mGameBoard;
    QImage mGrid;
    std::array<std::array<QImage, 14>, 2> komas;
    QImage mFocus;
    Board board;
    QPoint focus;
    void setAlpha(int alpha);
    void drawBoardGrid(QPainter& qPainter);
    void drawKoma(QPainter& qPainter);
};

#endif // BOARDVIEW_H
