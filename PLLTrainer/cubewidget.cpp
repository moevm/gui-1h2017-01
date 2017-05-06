#include "cubewidget.h"

CubeWidget::CubeWidget(QWidget *parent) : QWidget(parent)
{
    cube = new Cube();
    size = 20;
    cubeCoreColor = QColor(Qt::black);
    borderWidth = 4;
    borderColor = QColor(Qt::black);
    hideColor = QColor(Qt::gray);
    isHiding = false;
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

void CubeWidget::paintEvent(QPaintEvent *)
{
    size = this->width() / 14;
    borderWidth = size / 5;

    QPainter painter(this);
    painter.setPen(QPen(borderColor, borderWidth));
    painter.setBrush(QBrush(hideColor));

    //front
    if (!isHiding) painter.setBrush(QBrush(getQColor(cube->frontColor)));
    for (int i = 0; i < 9; i++) {
        CubeColor color = cube->frontColor;
        if (i < 3) color = cube->mainColors[i];
        if (!isHiding) painter.setBrush(QBrush(getQColor(color)));
        painter.drawRect(size + (i % 3) * 3 * size, 4 * size + (i / 3) * 3 * size, 3 * size, 3 * size);
    }

    //right
    for (int i = 0; i < 9; i++) {
        QVector<QPoint> points;
        CubeColor color = cube->rightColor;
        if (i < 3) color = cube->mainColors[i+3];
        if (!isHiding) painter.setBrush(QBrush(getQColor(color)));
        int x = 10 * size + (i % 3) * size;
        int y = 4 * size + (i / 3) * 3 * size - (i % 3) * size;
        points.append(QPoint(x, y));
        points.append(QPoint(x + size, y - size));
        points.append(QPoint(x + size, y + 2 * size));
        points.append(QPoint(x, y + 3 * size));
        painter.drawPolygon(QPolygon(points));
    }

    //top
    if (!isHiding) painter.setBrush(QBrush(getQColor(cube->upColor)));
    for (int i = 0; i < 9; i++) {
        QVector<QPoint> points;
        int x = 2 * size + (i / 3) * size + (i % 3) * 3 * size;
        int y = 3 * size - (i / 3) * size;
        points.append(QPoint(x, y));
        points.append(QPoint(x + 3 * size, y));
        points.append(QPoint(x + 2 * size, y + size));
        points.append(QPoint(x - size, y + size));
        painter.drawPolygon(QPolygon(points));
    }
}

