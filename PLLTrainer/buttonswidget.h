#ifndef BUTTONSWIDGET_H
#define BUTTONSWIDGET_H

#include <QWidget>
#include <QList>
#include <array>
#include "pllcases.h"
#include "cubemanager.h"
#include "mainwindow.h"
#include "pllcasedrawer.h"
#include "aboutpllform.h"

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

    static const int ROWS = 3;
    static const int COLS = 7;

    int size, width;
    PLLCase hoveredCase;

    CubeManager *cubeManager;
    MainWindow *mw;
    AboutPLLForm *aboutPLLForm;

    std::array<ButtonCoordinate*, CASECOUNT> coordinates;

protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

signals:

public slots:
};

#endif // BUTTONSWIDGET_H
