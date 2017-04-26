#ifndef CUBEWIDGET_H
#define CUBEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QColor>
#include "cube.h"

class CubeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CubeWidget(QWidget *parent = 0);\

    QColor getQColor(CubeColor color);

    Cube *cube;
    int size;
    int borderWidth;
    bool isHiding;

    QColor cubeCoreColor;
    QColor borderColor;
    QColor hideColor;


protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // CUBEWIDGET_H
