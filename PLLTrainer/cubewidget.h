#ifndef CUBEWIDGET_H
#define CUBEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QColor>

class CubeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CubeWidget(QWidget *parent = 0);
    int SIZE;
    QColor upColor;
    QColor frontColor;
    QColor rightColor;
    QColor mainColors[6];

protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // CUBEWIDGET_H
