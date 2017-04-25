#include "buttonswidget.h"
#include <QPainter>
#include <QMouseEvent>
#include "cube.h"

#include <QDebug>

ButtonsWidget::ButtonsWidget(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    size = 20;
    hoveredCase = BLANK;

    coordinates = {new ButtonCoordinate(2, 2, A1), new ButtonCoordinate(7, 2, A2), new ButtonCoordinate(12, 2, E),
                   new ButtonCoordinate(17, 2, Z), new ButtonCoordinate(22, 2, H), new ButtonCoordinate(27, 2, U1),
                   new ButtonCoordinate(32, 2, U2), new ButtonCoordinate(2, 7, J1), new ButtonCoordinate(7, 7, J2),
                   new ButtonCoordinate(12, 7, R1), new ButtonCoordinate(17, 7, R2), new ButtonCoordinate(22, 7, T),
                   new ButtonCoordinate(27, 7, Y), new ButtonCoordinate(32, 7, F), new ButtonCoordinate(2, 12, V),
                   new ButtonCoordinate(7, 12, N1), new ButtonCoordinate(12, 12, N2), new ButtonCoordinate(17, 12, G1),
                   new ButtonCoordinate(22, 12, G2), new ButtonCoordinate(27, 12, G3), new ButtonCoordinate(32, 12, G4)};
}

void ButtonsWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 2));
    //painter.setBrush(QBrush(cubeCoreColor));

    painter.setFont(QFont("arial",20));

    for(ButtonCoordinate* currButton: coordinates){
        if(hoveredCase == currButton->pllcase){
            painter.setPen(QPen(Qt::white, 2));
            painter.setBrush(QBrush(Qt::black));

            drawPLLCase(painter, currButton);

            painter.setPen(QPen(Qt::black, 2));
            painter.setBrush(QBrush(QColor(0,0,0,0)));
        }
        else{
            drawPLLCase(painter, currButton);
        }
    }
}

void ButtonsWidget::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    bool hoveredSomething = false;

    for(ButtonCoordinate* currButton: coordinates){
        if(x > currButton->x * size && x < (currButton->x + 3) * size &&
                y > currButton->y * size && y < (currButton->y + 3) * size){
            hoveredCase = currButton->pllcase;
            hoveredSomething = true;
            break;
        }
    }

    if(!hoveredSomething){
        hoveredCase = BLANK;
    }

    update();
}

void ButtonsWidget::mousePressEvent(QMouseEvent *event)
{
    if(hoveredCase == BLANK || !cubeManager->isSession) return;

    PLLCase actualPLLCase = cubeManager->currentPLLCase;
    bool res = cubeManager->checkUserChoice(hoveredCase);
    mw->firstLetter = Qt::Key_No;
    mw->setResults(res, actualPLLCase);
}

void ButtonsWidget::drawPLLCase(QPainter &painter, ButtonCoordinate* currButton)
{
    painter.drawRect(currButton->x * size, currButton->y * size, 3 * size, 3 * size);
    //painter.drawText(QRect(currButton->x * size, currButton->y * size, 3 * size, 3 * size),
    //                 Cube::getPLLName(currButton->pllcase), QTextOption(Qt::AlignCenter));
    painter.drawText(currButton->x * size, currButton->y * size - 5, Cube::getPLLName(currButton->pllcase));

    switch (currButton->pllcase) {
    case A1:

        break;
    default:
        break;
    }

}
