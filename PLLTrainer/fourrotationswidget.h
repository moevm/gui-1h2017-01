#ifndef FOURROTATIONSWIDGET_H
#define FOURROTATIONSWIDGET_H

#include <QWidget>
#include "pllcases.h"

class FourRotationsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FourRotationsWidget(QWidget *parent = 0);
    PLLCase pllcase;
    int size;
    int width;

protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // FOURROTATIONSWIDGET_H
