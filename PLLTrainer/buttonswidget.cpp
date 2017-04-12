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

    int index = 0;
    for(std::pair<int, int> currButton: coordinates){
        if(hoveredCase == (PLLCase) index){
            painter.setPen(QPen(Qt::white, 2));
            painter.setBrush(QBrush(Qt::black));

            painter.drawRect(currButton.first * size, currButton.second * size, 3 * size, 3 * size);
            painter.drawText(QRect(currButton.first * size, currButton.second * size, 3 * size, 3 * size),
                             "A1", QTextOption(Qt::AlignCenter));

            painter.setPen(QPen(Qt::black, 2));
            painter.setBrush(QBrush(QColor(0,0,0,0)));
        }
        else{
            painter.drawRect(currButton.first * size, currButton.second * size, 3 * size, 3 * size);
            painter.drawText(QRect(currButton.first * size, currButton.second * size, 3 * size, 3 * size),
                             "A1", QTextOption(Qt::AlignCenter));
        }

        index++;
    }
}

void ButtonsWidget::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    bool hoveredSomething = false;
    int index = 0;

    for(std::pair<int, int> currButton: coordinates){
        if(x > currButton.first * size && x < (currButton.first + 3) * size &&
                y > currButton.second * size && y < (currButton.second + 3) * size){
            hoveredCase = (PLLCase) index;
            hoveredSomething = true;
            break;
        }
        index++;
    }

    if(!hoveredSomething){
        hoveredCase = BLANK;
    }

    update();
}

void ButtonsWidget::mousePressEvent(QMouseEvent *event)
{

}
