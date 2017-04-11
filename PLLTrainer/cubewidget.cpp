#include "cubewidget.h"

CubeWidget::CubeWidget(QWidget *parent) : QWidget(parent)
{
    SIZE = 20;
    upColor = QColor(Qt::white);
    rightColor = QColor(Qt::blue);
    frontColor = QColor(Qt::red);
    mainColors[0] = QColor(Qt::red);
    mainColors[1] = QColor(Qt::red);
    mainColors[2] = QColor(Qt::red);
    mainColors[3] = QColor(Qt::blue);
    mainColors[4] = QColor(Qt::blue);
    mainColors[5] = QColor(Qt::blue);
}

void CubeWidget::changeCurrColors(QColor u, QColor f, QColor r,
                                  QColor c1, QColor c2, QColor c3,
                                  QColor c4, QColor c5, QColor c6)
{
    upColor = u;
    frontColor = f;
    rightColor = r;
    mainColors[0] = c1;
    mainColors[1] = c2;
    mainColors[2] = c3;
    mainColors[3] = c4;
    mainColors[4] = c5;
    mainColors[5] = c6;
}

void CubeWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 4));
    painter.setBrush(QBrush(mainColors[0], Qt::SolidPattern));

    // Рисуем переднюю часть

    QVector<QPoint> p;

    p.append(QPoint(1*SIZE, 4*SIZE));
    p.append(QPoint(4*SIZE, 4*SIZE));
    p.append(QPoint(4*SIZE, 7*SIZE));
    p.append(QPoint(1*SIZE, 7*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    painter.setBrush(QBrush(mainColors[1], Qt::SolidPattern));

    p.clear();

    p.append(QPoint(4*SIZE, 4*SIZE));
    p.append(QPoint(7*SIZE, 4*SIZE));
    p.append(QPoint(7*SIZE, 7*SIZE));
    p.append(QPoint(4*SIZE, 7*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    painter.setBrush(QBrush(mainColors[2], Qt::SolidPattern));

    p.clear();

    p.append(QPoint(7*SIZE, 4*SIZE));
    p.append(QPoint(10*SIZE, 4*SIZE));
    p.append(QPoint(10*SIZE, 7*SIZE));
    p.append(QPoint(7*SIZE, 7*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    painter.setBrush(QBrush(frontColor, Qt::SolidPattern));

    p.clear();

    p.append(QPoint(1*SIZE, 7*SIZE));
    p.append(QPoint(4*SIZE, 7*SIZE));
    p.append(QPoint(4*SIZE, 10*SIZE));
    p.append(QPoint(1*SIZE, 10*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    p.clear();

    p.append(QPoint(4*SIZE, 7*SIZE));
    p.append(QPoint(7*SIZE, 7*SIZE));
    p.append(QPoint(7*SIZE, 10*SIZE));
    p.append(QPoint(4*SIZE, 10*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    p.clear();

    p.append(QPoint(7*SIZE, 7*SIZE));
    p.append(QPoint(10*SIZE, 7*SIZE));
    p.append(QPoint(10*SIZE, 10*SIZE));
    p.append(QPoint(7*SIZE, 10*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    p.clear();

    p.append(QPoint(1*SIZE, 10*SIZE));
    p.append(QPoint(4*SIZE, 10*SIZE));
    p.append(QPoint(4*SIZE, 13*SIZE));
    p.append(QPoint(1*SIZE, 13*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    p.clear();

    p.append(QPoint(4*SIZE, 10*SIZE));
    p.append(QPoint(7*SIZE, 10*SIZE));
    p.append(QPoint(7*SIZE, 13*SIZE));
    p.append(QPoint(4*SIZE, 13*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);


    p.clear();

    p.append(QPoint(7*SIZE, 10*SIZE));
    p.append(QPoint(10*SIZE, 10*SIZE));
    p.append(QPoint(10*SIZE, 13*SIZE));
    p.append(QPoint(7*SIZE, 13*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);


    // Рисуем верхнюю часть

    painter.setBrush(QBrush(upColor, Qt::SolidPattern));

    p.clear();

    p.append(QPoint(2*SIZE, 3*SIZE));
    p.append(QPoint(5*SIZE, 3*SIZE));
    p.append(QPoint(4*SIZE, 4*SIZE));
    p.append(QPoint(1*SIZE, 4*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    p.clear();

    p.append(QPoint(5*SIZE, 3*SIZE));
    p.append(QPoint(8*SIZE, 3*SIZE));
    p.append(QPoint(7*SIZE, 4*SIZE));
    p.append(QPoint(4*SIZE, 4*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    p.clear();

    p.append(QPoint(8*SIZE, 3*SIZE));
    p.append(QPoint(11*SIZE, 3*SIZE));
    p.append(QPoint(10*SIZE, 4*SIZE));
    p.append(QPoint(7*SIZE, 4*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    p.clear();

    p.append(QPoint(3*SIZE, 2*SIZE));
    p.append(QPoint(6*SIZE, 2*SIZE));
    p.append(QPoint(5*SIZE, 3*SIZE));
    p.append(QPoint(2*SIZE, 3*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    p.clear();

    p.append(QPoint(6*SIZE, 2*SIZE));
    p.append(QPoint(9*SIZE, 2*SIZE));
    p.append(QPoint(8*SIZE, 3*SIZE));
    p.append(QPoint(5*SIZE, 3*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    p.clear();

    p.append(QPoint(9*SIZE, 2*SIZE));
    p.append(QPoint(12*SIZE, 2*SIZE));
    p.append(QPoint(11*SIZE, 3*SIZE));
    p.append(QPoint(8*SIZE, 3*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    p.clear();

    p.append(QPoint(4*SIZE, 1*SIZE));
    p.append(QPoint(7*SIZE, 1*SIZE));
    p.append(QPoint(6*SIZE, 2*SIZE));
    p.append(QPoint(3*SIZE, 2*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    p.clear();

    p.append(QPoint(7*SIZE, 1*SIZE));
    p.append(QPoint(10*SIZE, 1*SIZE));
    p.append(QPoint(9*SIZE, 2*SIZE));
    p.append(QPoint(6*SIZE, 2*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    p.clear();

    p.append(QPoint(10*SIZE, 1*SIZE));
    p.append(QPoint(13*SIZE, 1*SIZE));
    p.append(QPoint(12*SIZE, 2*SIZE));
    p.append(QPoint(9*SIZE, 2*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    // Рисуем правую часть

    painter.setBrush(QBrush(mainColors[3], Qt::SolidPattern));

    p.clear();

    p.append(QPoint(10*SIZE, 4*SIZE));
    p.append(QPoint(11*SIZE, 3*SIZE));
    p.append(QPoint(11*SIZE, 6*SIZE));
    p.append(QPoint(10*SIZE, 7*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    painter.setBrush(QBrush(mainColors[4], Qt::SolidPattern));

    p.clear();

    p.append(QPoint(11*SIZE, 3*SIZE));
    p.append(QPoint(12*SIZE, 2*SIZE));
    p.append(QPoint(12*SIZE, 5*SIZE));
    p.append(QPoint(11*SIZE, 6*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    painter.setBrush(QBrush(mainColors[5], Qt::SolidPattern));

    p.clear();

    p.append(QPoint(12*SIZE, 2*SIZE));
    p.append(QPoint(13*SIZE, 1*SIZE));
    p.append(QPoint(13*SIZE, 4*SIZE));
    p.append(QPoint(12*SIZE, 5*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    painter.setBrush(QBrush(rightColor, Qt::SolidPattern));

    p.clear();

    p.append(QPoint(10*SIZE, 7*SIZE));
    p.append(QPoint(11*SIZE, 6*SIZE));
    p.append(QPoint(11*SIZE, 9*SIZE));
    p.append(QPoint(10*SIZE, 10*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    p.clear();

    p.append(QPoint(11*SIZE, 6*SIZE));
    p.append(QPoint(12*SIZE, 5*SIZE));
    p.append(QPoint(12*SIZE, 8*SIZE));
    p.append(QPoint(11*SIZE, 9*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    p.clear();

    p.append(QPoint(12*SIZE, 5*SIZE));
    p.append(QPoint(13*SIZE, 4*SIZE));
    p.append(QPoint(13*SIZE, 7*SIZE));
    p.append(QPoint(12*SIZE, 8*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    p.clear();

    p.append(QPoint(10*SIZE, 10*SIZE));
    p.append(QPoint(11*SIZE, 9*SIZE));
    p.append(QPoint(11*SIZE, 12*SIZE));
    p.append(QPoint(10*SIZE, 13*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    p.clear();

    p.append(QPoint(11*SIZE, 9*SIZE));
    p.append(QPoint(12*SIZE, 8*SIZE));
    p.append(QPoint(12*SIZE, 11*SIZE));
    p.append(QPoint(11*SIZE, 12*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    p.clear();

    p.append(QPoint(12*SIZE, 8*SIZE));
    p.append(QPoint(13*SIZE, 7*SIZE));
    p.append(QPoint(13*SIZE, 10*SIZE));
    p.append(QPoint(12*SIZE, 11*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);
}
