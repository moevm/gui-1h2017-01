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

void CubeWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(borderColor, borderWidth));
    painter.setBrush(QBrush(hideColor));
    painter.setRenderHint(QPainter::Antialiasing);

    painter.fillRect(0, 0, this->width(), this->height(), Qt::white);
    float size = (float) this->width() / 6;

    //front
    if (!isHiding) painter.setBrush(QBrush(getQColor(cube->frontColor)));
    for (int i = 0; i < 9; i++) {
        CubeColor color = cube->frontColor;
        if (i < 3) color = cube->mainColors[i];
        if (!isHiding) painter.setBrush(QBrush(getQColor(color)));
        painter.drawRect(size + (i % 3) * size, (2 + i/3) * size, size, size);
    }

    //right
    for (int i = 0; i < 9; i++) {
        QVector<QPoint> points;
        CubeColor color = cube->rightColor;
        if (i < 3) color = cube->mainColors[i+3];
        if (!isHiding) painter.setBrush(QBrush(getQColor(color)));
        int x = 4 * size + (i % 3) * size / 3;
        int y = 2 * size + (i / 3) * size - (i % 3) * size / 3;
        points.append(QPoint(x, y));
        points.append(QPoint(x + size / 3, y - size / 3));
        points.append(QPoint(x + size / 3, y + size - size / 3));
        points.append(QPoint(x, y + size));
        painter.drawPolygon(QPolygon(points));
    }

    //top
    if (!isHiding) painter.setBrush(QBrush(getQColor(cube->upColor)));
    for (int i = 0; i < 9; i++) {
        QVector<QPoint> points;
        int x = size + (3 - i / 3) * size / 3 + (i % 3) * size;
        int y = size + (i / 3) * size / 3;
        points.append(QPoint(x, y));
        points.append(QPoint(x + size, y));
        points.append(QPoint(x + size - size / 3, y + size / 3));
        points.append(QPoint(x - size / 3, y + size / 3));
        painter.drawPolygon(QPolygon(points));
    }

    painter.end();
}
