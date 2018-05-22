#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QGraphicsView>
#include <QImage>
#include <QRect>
#include <QWidget>

class BoardView : public QGraphicsView
{
public:
    BoardView(QWidget *parent = 0) : QGraphicsView(parent)
    {
      setAlpha(255);
      mRect = QRect(0, 0, mQImage.width(), mQImage.height());
    }

    void paintEvent(QPaintEvent *)
    {
      QPainter qPainter(viewport());
      QRect rect(0, 0, mQImage.width(), mQImage.height());
      mQImage.load("image/ban/ban_kaya_a.png");
      qPainter.drawImage(rect, mQImage, mRect, Qt::ColorOnly|Qt::DiffuseAlphaDither|Qt::PreferDither);
      mQImage.load("image/masu/masu_dot_xy.png");
      qPainter.drawImage(rect, mQImage, mRect, Qt::ColorOnly|Qt::DiffuseAlphaDither|Qt::PreferDither);
   }

private:
    QImage mQImage;
    QRect mRect;

    void setAlpha(int alpha)
    {
      for (int x = 0, width = mQImage.width(); x < width; ++x)
        for (int y = 0, height = mQImage.height(); y < height; ++y) {
          QColor color(mQImage.pixel(x, y));
          color.setAlpha(alpha);
          mQImage.setPixel(x, y, color.rgba());
        }
    }
};

#endif // BOARDVIEW_H
