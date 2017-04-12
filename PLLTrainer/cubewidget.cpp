#include "cubewidget.h"

CubeWidget::CubeWidget(QWidget *parent) : QWidget(parent)
{
    cube = new Cube();
}

QColor CubeWidget::getQColor(CubeColor color)
{
    switch (color) {
    case WHITE:
        return QColor(Qt::white);
    case YELLOW:
        return QColor(Qt::yellow);
    case BLUE:
        return QColor(Qt::blue);
    case GREEN:
        return QColor(Qt::green);
    case RED:
        return QColor(Qt::red);
    case ORANGE:
        return QColor(255, 165, 0);
    default:
        return QColor(Qt::black);
    }
}

void CubeWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 4));
    painter.setBrush(QBrush(getQColor(cube->mainColors[0]), Qt::SolidPattern));

    int SIZE = cube->SIZE;

    // Рисуем переднюю часть

    QVector<QPoint> p;

    p.append(QPoint(1*SIZE, 4*SIZE));
    p.append(QPoint(4*SIZE, 4*SIZE));
    p.append(QPoint(4*SIZE, 7*SIZE));
    p.append(QPoint(1*SIZE, 7*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    painter.setBrush(QBrush(getQColor(cube->mainColors[1]), Qt::SolidPattern));

    p.clear();

    p.append(QPoint(4*SIZE, 4*SIZE));
    p.append(QPoint(7*SIZE, 4*SIZE));
    p.append(QPoint(7*SIZE, 7*SIZE));
    p.append(QPoint(4*SIZE, 7*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    painter.setBrush(QBrush(getQColor(cube->mainColors[2]), Qt::SolidPattern));

    p.clear();

    p.append(QPoint(7*SIZE, 4*SIZE));
    p.append(QPoint(10*SIZE, 4*SIZE));
    p.append(QPoint(10*SIZE, 7*SIZE));
    p.append(QPoint(7*SIZE, 7*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    painter.setBrush(QBrush(getQColor(cube->frontColor), Qt::SolidPattern));

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

    painter.setBrush(QBrush(getQColor(cube->upColor), Qt::SolidPattern));

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

    painter.setBrush(QBrush(getQColor(cube->mainColors[3]), Qt::SolidPattern));

    p.clear();

    p.append(QPoint(10*SIZE, 4*SIZE));
    p.append(QPoint(11*SIZE, 3*SIZE));
    p.append(QPoint(11*SIZE, 6*SIZE));
    p.append(QPoint(10*SIZE, 7*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    painter.setBrush(QBrush(getQColor(cube->mainColors[4]), Qt::SolidPattern));

    p.clear();

    p.append(QPoint(11*SIZE, 3*SIZE));
    p.append(QPoint(12*SIZE, 2*SIZE));
    p.append(QPoint(12*SIZE, 5*SIZE));
    p.append(QPoint(11*SIZE, 6*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    painter.setBrush(QBrush(getQColor(cube->mainColors[5]), Qt::SolidPattern));

    p.clear();

    p.append(QPoint(12*SIZE, 2*SIZE));
    p.append(QPoint(13*SIZE, 1*SIZE));
    p.append(QPoint(13*SIZE, 4*SIZE));
    p.append(QPoint(12*SIZE, 5*SIZE));

    painter.drawPolygon(QPolygon(p), Qt::OddEvenFill);

    painter.setBrush(QBrush(getQColor(cube->rightColor), Qt::SolidPattern));

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
