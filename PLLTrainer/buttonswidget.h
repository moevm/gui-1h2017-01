#ifndef BUTTONSWIDGET_H
#define BUTTONSWIDGET_H

#include <QWidget>
#include <QList>
#include "pllcases.h"
#include <array>


class ButtonsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ButtonsWidget(QWidget *parent = 0);

    int size;
    PLLCase hoveredCase;

    std::array<std::pair<int, int>, 21> coordinates;

protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

signals:

public slots:
};

#endif // BUTTONSWIDGET_H
