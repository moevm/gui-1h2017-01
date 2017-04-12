#include "cubewidget.h"

CubeWidget::CubeWidget(QWidget *parent) : QWidget(parent)
{
    cube = new Cube();
    size = 20;
    width = 4;
    cubeCoreColor = QColor(Qt::black);
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

    painter.setPen(QPen(cubeCoreColor, width));
    painter.setBrush(QBrush(getQColor(cube->mainColors[0])));

    // Рисуем переднюю часть

    QVector<QPoint> p;

    p.append(QPoint(1*size, 4*size));
    p.append(QPoint(4*size, 4*size));
    p.append(QPoint(4*size, 7*size));
    p.append(QPoint(1*size, 7*size));

    painter.drawPolygon(QPolygon(p));

    painter.setBrush(QBrush(getQColor(cube->mainColors[1])));

    p.clear();

    p.append(QPoint(4*size, 4*size));
    p.append(QPoint(7*size, 4*size));
    p.append(QPoint(7*size, 7*size));
    p.append(QPoint(4*size, 7*size));

    painter.drawPolygon(QPolygon(p));

    painter.setBrush(QBrush(getQColor(cube->mainColors[2])));

    p.clear();

    p.append(QPoint(7*size, 4*size));
    p.append(QPoint(10*size, 4*size));
    p.append(QPoint(10*size, 7*size));
    p.append(QPoint(7*size, 7*size));

    painter.drawPolygon(QPolygon(p));

    painter.setBrush(QBrush(getQColor(cube->frontColor)));

    p.clear();

    p.append(QPoint(1*size, 7*size));
    p.append(QPoint(4*size, 7*size));
    p.append(QPoint(4*size, 10*size));
    p.append(QPoint(1*size, 10*size));

    painter.drawPolygon(QPolygon(p));

    p.clear();

    p.append(QPoint(4*size, 7*size));
    p.append(QPoint(7*size, 7*size));
    p.append(QPoint(7*size, 10*size));
    p.append(QPoint(4*size, 10*size));

    painter.drawPolygon(QPolygon(p));

    p.clear();

    p.append(QPoint(7*size, 7*size));
    p.append(QPoint(10*size, 7*size));
    p.append(QPoint(10*size, 10*size));
    p.append(QPoint(7*size, 10*size));

    painter.drawPolygon(QPolygon(p));

    p.clear();

    p.append(QPoint(1*size, 10*size));
    p.append(QPoint(4*size, 10*size));
    p.append(QPoint(4*size, 13*size));
    p.append(QPoint(1*size, 13*size));

    painter.drawPolygon(QPolygon(p));

    p.clear();

    p.append(QPoint(4*size, 10*size));
    p.append(QPoint(7*size, 10*size));
    p.append(QPoint(7*size, 13*size));
    p.append(QPoint(4*size, 13*size));

    painter.drawPolygon(QPolygon(p));


    p.clear();

    p.append(QPoint(7*size, 10*size));
    p.append(QPoint(10*size, 10*size));
    p.append(QPoint(10*size, 13*size));
    p.append(QPoint(7*size, 13*size));

    painter.drawPolygon(QPolygon(p));

    // Рисуем верхнюю часть

    painter.setBrush(QBrush(getQColor(cube->upColor)));

    p.clear();

    p.append(QPoint(2*size, 3*size));
    p.append(QPoint(5*size, 3*size));
    p.append(QPoint(4*size, 4*size));
    p.append(QPoint(1*size, 4*size));

    painter.drawPolygon(QPolygon(p));

    p.clear();

    p.append(QPoint(5*size, 3*size));
    p.append(QPoint(8*size, 3*size));
    p.append(QPoint(7*size, 4*size));
    p.append(QPoint(4*size, 4*size));

    painter.drawPolygon(QPolygon(p));

    p.clear();

    p.append(QPoint(8*size, 3*size));
    p.append(QPoint(11*size, 3*size));
    p.append(QPoint(10*size, 4*size));
    p.append(QPoint(7*size, 4*size));

    painter.drawPolygon(QPolygon(p));

    p.clear();

    p.append(QPoint(3*size, 2*size));
    p.append(QPoint(6*size, 2*size));
    p.append(QPoint(5*size, 3*size));
    p.append(QPoint(2*size, 3*size));

    painter.drawPolygon(QPolygon(p));

    p.clear();

    p.append(QPoint(6*size, 2*size));
    p.append(QPoint(9*size, 2*size));
    p.append(QPoint(8*size, 3*size));
    p.append(QPoint(5*size, 3*size));

    painter.drawPolygon(QPolygon(p));

    p.clear();

    p.append(QPoint(9*size, 2*size));
    p.append(QPoint(12*size, 2*size));
    p.append(QPoint(11*size, 3*size));
    p.append(QPoint(8*size, 3*size));

    painter.drawPolygon(QPolygon(p));

    p.clear();

    p.append(QPoint(4*size, 1*size));
    p.append(QPoint(7*size, 1*size));
    p.append(QPoint(6*size, 2*size));
    p.append(QPoint(3*size, 2*size));

    painter.drawPolygon(QPolygon(p));

    p.clear();

    p.append(QPoint(7*size, 1*size));
    p.append(QPoint(10*size, 1*size));
    p.append(QPoint(9*size, 2*size));
    p.append(QPoint(6*size, 2*size));

    painter.drawPolygon(QPolygon(p));

    p.clear();

    p.append(QPoint(10*size, 1*size));
    p.append(QPoint(13*size, 1*size));
    p.append(QPoint(12*size, 2*size));
    p.append(QPoint(9*size, 2*size));

    painter.drawPolygon(QPolygon(p));

    // Рисуем правую часть

    painter.setBrush(QBrush(getQColor(cube->mainColors[3])));

    p.clear();

    p.append(QPoint(10*size, 4*size));
    p.append(QPoint(11*size, 3*size));
    p.append(QPoint(11*size, 6*size));
    p.append(QPoint(10*size, 7*size));

    painter.drawPolygon(QPolygon(p));

    painter.setBrush(QBrush(getQColor(cube->mainColors[4])));

    p.clear();

    p.append(QPoint(11*size, 3*size));
    p.append(QPoint(12*size, 2*size));
    p.append(QPoint(12*size, 5*size));
    p.append(QPoint(11*size, 6*size));

    painter.drawPolygon(QPolygon(p));

    painter.setBrush(QBrush(getQColor(cube->mainColors[5])));

    p.clear();

    p.append(QPoint(12*size, 2*size));
    p.append(QPoint(13*size, 1*size));
    p.append(QPoint(13*size, 4*size));
    p.append(QPoint(12*size, 5*size));

    painter.drawPolygon(QPolygon(p));

    painter.setBrush(QBrush(getQColor(cube->rightColor)));

    p.clear();

    p.append(QPoint(10*size, 7*size));
    p.append(QPoint(11*size, 6*size));
    p.append(QPoint(11*size, 9*size));
    p.append(QPoint(10*size, 10*size));

    painter.drawPolygon(QPolygon(p));

    p.clear();

    p.append(QPoint(11*size, 6*size));
    p.append(QPoint(12*size, 5*size));
    p.append(QPoint(12*size, 8*size));
    p.append(QPoint(11*size, 9*size));

    painter.drawPolygon(QPolygon(p));

    p.clear();

    p.append(QPoint(12*size, 5*size));
    p.append(QPoint(13*size, 4*size));
    p.append(QPoint(13*size, 7*size));
    p.append(QPoint(12*size, 8*size));

    painter.drawPolygon(QPolygon(p));

    p.clear();

    p.append(QPoint(10*size, 10*size));
    p.append(QPoint(11*size, 9*size));
    p.append(QPoint(11*size, 12*size));
    p.append(QPoint(10*size, 13*size));

    painter.drawPolygon(QPolygon(p));

    p.clear();

    p.append(QPoint(11*size, 9*size));
    p.append(QPoint(12*size, 8*size));
    p.append(QPoint(12*size, 11*size));
    p.append(QPoint(11*size, 12*size));

    painter.drawPolygon(QPolygon(p));

    p.clear();

    p.append(QPoint(12*size, 8*size));
    p.append(QPoint(13*size, 7*size));
    p.append(QPoint(13*size, 10*size));
    p.append(QPoint(12*size, 11*size));

    painter.drawPolygon(QPolygon(p));
}
