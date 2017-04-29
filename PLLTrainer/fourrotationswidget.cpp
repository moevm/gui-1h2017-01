#include "fourrotationswidget.h"
#include "cube.h"
#include "pllcasedrawer.h"

FourRotationsWidget::FourRotationsWidget(QWidget *parent) : QWidget(parent)
{
    pllcase = BLANK;
    size = 20;
    width = 4;
}

void FourRotationsWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 2));
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setFont(QFont("arial", size));

    painter.drawText(2 * size, 2 * size - 10, Cube::getPLLName(pllcase));

    for(int i = 0; i < 4; i++){
        PLLCaseDrawer::drawPLLCase(painter, pllcase, 2 + i * 8, 2, size, width, false, i);
    }
}
