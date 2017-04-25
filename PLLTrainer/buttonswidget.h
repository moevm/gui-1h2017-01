#ifndef BUTTONSWIDGET_H
#define BUTTONSWIDGET_H

#include <QWidget>
#include <QList>
#include <array>
#include "pllcases.h"
#include <array>

#include "cubemanager.h"
#include "mainwindow.h"

struct ButtonCoordinate{
    int x;
    int y;
    PLLCase pllcase;

    ButtonCoordinate(int _x, int _y, PLLCase _pllcase){
        x = _x;
        y = _y;
        pllcase = _pllcase;
    }
};

class ButtonsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ButtonsWidget(QWidget *parent = 0);

    int size;
    PLLCase hoveredCase;

    CubeManager *cubeManager;
    MainWindow *mw;

    std::array<ButtonCoordinate*, 21> coordinates;

protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void drawPLLCase(QPainter &painter, ButtonCoordinate* currButton);

signals:

public slots:
};

#endif // BUTTONSWIDGET_H
