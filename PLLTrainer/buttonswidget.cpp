#include "buttonswidget.h"
#include <QPainter>
#include <QMouseEvent>
#include "cube.h"
#include "math.h"
#include <QDebug>

ButtonsWidget::ButtonsWidget(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    size = 20;
    width = 4;
    hoveredCase = BLANK;

    for(int i = 0; i < CASECOUNT; i++){
        coordinates[i] = new ButtonCoordinate(2 + (i % COLS) * 5, 2 + (i / COLS) * 5, (PLLCase) i);
    }
}

void ButtonsWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 2));
    //painter.setBrush(QBrush(cubeCoreColor));
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setFont(QFont("arial",20));

    for(ButtonCoordinate* currButton: coordinates){

        painter.drawText(currButton->x * size, currButton->y * size - 5, Cube::getPLLName(currButton->pllcase));

        if(hoveredCase == currButton->pllcase){
            PLLCaseDrawer::drawPLLCase(painter, currButton->pllcase, currButton->x, currButton->y, size, width, true);
        }
        else{
            PLLCaseDrawer::drawPLLCase(painter, currButton->pllcase, currButton->x, currButton->y, size, width, false);
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
