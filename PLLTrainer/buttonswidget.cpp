#include "buttonswidget.h"
#include <QPainter>
#include <QMouseEvent>

#include <QDebug>

ButtonsWidget::ButtonsWidget(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    size = 20;
    hoveredCase = BLANK;

    coordinates = {std::pair<int, int>(2, 1), std::pair<int, int>(7, 1), std::pair<int, int>(12, 1),
                  std::pair<int, int>(17, 1), std::pair<int, int>(22, 1), std::pair<int, int>(27, 1),
                  std::pair<int, int>(32, 1), std::pair<int, int>(2, 6), std::pair<int, int>(7, 6),
                  std::pair<int, int>(12, 6), std::pair<int, int>(17, 6), std::pair<int, int>(22, 6),
                  std::pair<int, int>(27, 6), std::pair<int, int>(32, 6), std::pair<int, int>(2, 11),
                  std::pair<int, int>(7, 11), std::pair<int, int>(12, 11), std::pair<int, int>(17, 11),
                  std::pair<int, int>(22, 11), std::pair<int, int>(27, 11), std::pair<int, int>(32, 11)};
}

void ButtonsWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 2));
    //painter.setBrush(QBrush(cubeCoreColor));

    painter.setFont(QFont("arial",20));

    if(hoveredCase == A1){
        painter.setPen(QPen(Qt::white, 2));
        painter.setBrush(QBrush(Qt::black));
    }
    painter.drawRect(2*size, 1*size, 3*size, 3*size);
    painter.drawText(QRect(2*size, 1*size, 3*size, 3*size), "A1", QTextOption(Qt::AlignCenter));
    if(hoveredCase == A1){
        painter.setPen(QPen(Qt::black, 2));
        painter.setBrush(QBrush(QColor(0,0,0,0)));
    }



    painter.drawRect(7*size, 1*size, 3*size, 3*size);
    painter.drawText(QRect(7*size, 1*size, 3*size, 3*size), "A2", QTextOption(Qt::AlignCenter));
    painter.drawRect(12*size, 1*size, 3*size, 3*size);
    painter.drawText(QRect(12*size, 1*size, 3*size, 3*size), "E", QTextOption(Qt::AlignCenter));
    painter.drawRect(17*size, 1*size, 3*size, 3*size);
    painter.drawText(QRect(17*size, 1*size, 3*size, 3*size), "Z", QTextOption(Qt::AlignCenter));
    painter.drawRect(22*size, 1*size, 3*size, 3*size);
    painter.drawText(QRect(22*size, 1*size, 3*size, 3*size), "H", QTextOption(Qt::AlignCenter));
    painter.drawRect(27*size, 1*size, 3*size, 3*size);
    painter.drawText(QRect(27*size, 1*size, 3*size, 3*size), "U1", QTextOption(Qt::AlignCenter));
    painter.drawRect(32*size, 1*size, 3*size, 3*size);
    painter.drawText(QRect(32*size, 1*size, 3*size, 3*size), "U2", QTextOption(Qt::AlignCenter));

    painter.drawRect(2*size, 6*size, 3*size, 3*size);
    painter.drawText(QRect(2*size, 6*size, 3*size, 3*size), "J1", QTextOption(Qt::AlignCenter));
    painter.drawRect(7*size, 6*size, 3*size, 3*size);
    painter.drawText(QRect(7*size, 6*size, 3*size, 3*size), "J2", QTextOption(Qt::AlignCenter));
    painter.drawRect(12*size, 6*size, 3*size, 3*size);
    painter.drawText(QRect(12*size, 6*size, 3*size, 3*size), "R1", QTextOption(Qt::AlignCenter));
    painter.drawRect(17*size, 6*size, 3*size, 3*size);
    painter.drawText(QRect(17*size, 6*size, 3*size, 3*size), "R2", QTextOption(Qt::AlignCenter));
    painter.drawRect(22*size, 6*size, 3*size, 3*size);
    painter.drawText(QRect(22*size, 6*size, 3*size, 3*size), "T", QTextOption(Qt::AlignCenter));
    painter.drawRect(27*size, 6*size, 3*size, 3*size);
    painter.drawText(QRect(27*size, 6*size, 3*size, 3*size), "Y", QTextOption(Qt::AlignCenter));
    painter.drawRect(32*size, 6*size, 3*size, 3*size);
    painter.drawText(QRect(32*size, 6*size, 3*size, 3*size), "F", QTextOption(Qt::AlignCenter));

    painter.drawRect(2*size, 11*size, 3*size, 3*size);
    painter.drawText(QRect(2*size, 11*size, 3*size, 3*size), "V", QTextOption(Qt::AlignCenter));
    painter.drawRect(7*size, 11*size, 3*size, 3*size);
    painter.drawText(QRect(7*size, 11*size, 3*size, 3*size), "N1", QTextOption(Qt::AlignCenter));
    painter.drawRect(12*size, 11*size, 3*size, 3*size);
    painter.drawText(QRect(12*size, 11*size, 3*size, 3*size), "N2", QTextOption(Qt::AlignCenter));
    painter.drawRect(17*size, 11*size, 3*size, 3*size);
    painter.drawText(QRect(17*size, 11*size, 3*size, 3*size), "G1", QTextOption(Qt::AlignCenter));
    painter.drawRect(22*size, 11*size, 3*size, 3*size);
    painter.drawText(QRect(22*size, 11*size, 3*size, 3*size), "G2", QTextOption(Qt::AlignCenter));
    painter.drawRect(27*size, 11*size, 3*size, 3*size);
    painter.drawText(QRect(27*size, 11*size, 3*size, 3*size), "G3", QTextOption(Qt::AlignCenter));
    painter.drawRect(32*size, 11*size, 3*size, 3*size);
    painter.drawText(QRect(32*size, 11*size, 3*size, 3*size), "G4", QTextOption(Qt::AlignCenter));
}

void ButtonsWidget::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    if(x > 2*size && x < 5*size && y > 1*size && y < 4*size){
        hoveredCase = A1;
    }
    else{
        hoveredCase = BLANK;
    }

    update();
}

void ButtonsWidget::mousePressEvent(QMouseEvent *event)
{

}
