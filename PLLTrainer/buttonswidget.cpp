#include "buttonswidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QCursor>
#include "cube.h"
#include <cmath>

ButtonsWidget::ButtonsWidget(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    size = 20;
    width = 4;
    hoveredCase = BLANK;
    showStat = false;

    aboutPLLForm = new AboutPLLForm();

    for(int i = 0; i < CASECOUNT; i++){
        coordinates[i] = new ButtonCoordinate(2 + (i % COLS) * 5, 2 + (i / COLS) * 5, (PLLCase) i);
    }
}

void ButtonsWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPair<int, int> currStat;
    painter.setPen(QPen(Qt::black, 2));
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setFont(QFont("arial", size));

    for(ButtonCoordinate* currButton: coordinates){

        currStat = Settings::Instance().stat.getStats(currButton->pllcase);

        painter.drawText(currButton->x * size, currButton->y * size - 5, Cube::getPLLName(currButton->pllcase));

        PLLCaseDrawer::drawPLLCase(painter, currButton->pllcase, currButton->x, currButton->y, size, width,
            hoveredCase == currButton->pllcase, 0, showStat, (int) (100.0 * (currStat.second - currStat.first) / currStat.second));
    }

    if(showStat){
        QString stat;
        QPair<int, int> overall = Settings::Instance().stat.overall;

        stat += Settings::Instance().getStr("errors") + ": ";
        stat += QString::number(overall.second - overall.first) + " ";
        stat += Settings::Instance().getStr("out of") + " ";
        stat += QString::number(overall.second) + ". ";
        stat += Settings::Instance().getStr("percent") + " ";
        stat += QString::number((int) (100.0 * (overall.second - overall.first) / overall.second)) + "%";

        painter.drawText(QRect(2 * size , 15 * size, 33 * size, 3 * size), stat, QTextOption(Qt::AlignCenter));
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
        setCursor(Qt::ArrowCursor);
    }
    else if(!cubeManager->isSession){
        setCursor(Qt::WhatsThisCursor);
    }

    update();
}

void ButtonsWidget::mousePressEvent(QMouseEvent *)
{
    if(hoveredCase != BLANK && !cubeManager->isSession){
        aboutPLLForm->showPLLCase(hoveredCase);
    }
    if(hoveredCase == BLANK || !cubeManager->isSession || cubeManager->isPaused) return;

    PLLCase actualPLLCase = cubeManager->currentPLLCase;
    bool res = cubeManager->checkUserChoice(hoveredCase);
    mw->firstLetter = Qt::Key_No;
    mw->setResults(res, actualPLLCase);
}
