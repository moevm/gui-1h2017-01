#include "buttonswidget.h"
#include <QPainter>
#include <QMouseEvent>
#include "cube.h"

#include <QDebug>

ButtonsWidget::ButtonsWidget(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    size = 20;
    width = 4;
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

        //painter.drawText(QRect(currButton->x * size, currButton->y * size, 3 * size, 3 * size),
        //                 Cube::getPLLName(currButton->pllcase), QTextOption(Qt::AlignCenter));
        painter.drawText(currButton->x * size, currButton->y * size - 5, Cube::getPLLName(currButton->pllcase));

        if(hoveredCase == currButton->pllcase){
            painter.setBrush(QBrush(Qt::black));
            painter.drawRect(currButton->x * size, currButton->y * size, 3 * size, 3 * size);
            painter.setPen(QPen(Qt::white, 2));


            drawPLLCase(painter, currButton);

            painter.setPen(QPen(Qt::black, 2));
            painter.setBrush(QBrush(QColor(0,0,0,0)));
        }
        else{
            painter.drawRect(currButton->x * size, currButton->y * size, 3 * size, 3 * size);
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

    switch (currButton->pllcase) {
    case A1:
        drawArrow(painter, 4*size+size/2-width/2, 5*size-size/2-width/2, 2*size+size/2+width/2, 3*size-size/2+width/2, true, false);
        drawArrow(painter, 2*size+size/2+width/2, 2*size+size/2, 4*size+size/2, 2*size+size/2, true, false);
        drawArrow(painter, 4*size+size/2, 2*size+size/2+width/2, 4*size+size/2, 4*size+size/2-width/2, true, false);
        break;
    case A2:
        drawArrow(painter, 9*size+size/2-width/2, 4*size+size/2-width/2, 7*size+size/2+width/2, 2*size+size/2+width/2, false, true);
        drawArrow(painter, 7*size+size/2+width/2, 2*size+size/2, 9*size+size/2-width/2, 2*size+size/2, false, true);
        drawArrow(painter, 9*size+size/2, 2*size+size/2, 9*size+size/2, 4*size+size/2-width/2, false, true);
        break;
    case E:
        drawArrow(painter, 12*size+size/2, 2*size+size/2-width/2, 12*size+size/2, 4*size+size/2+width/2, true, true);
        drawArrow(painter, 14*size+size/2, 2*size+size/2-width/2, 14*size+size/2, 4*size+size/2+width/2, true, true);
        break;
    case Z:
        drawArrow(painter, 17*size+size/2-width/2, 3*size+size/2+width/2, 18*size+size/2+width/2, 2*size+size/2-width/2, true, true);
        drawArrow(painter, 18*size+size/2-width/2, 4*size+size/2+width/2, 19*size+size/2+width/2, 3*size+size/2-width/2, true, true);
        break;
    case H:
        drawArrow(painter, 23*size+size/2, 2*size+size/2-width/2, 23*size+size/2, 4*size+size/2+width/2, true, true);
        drawArrow(painter, 22*size+size/2-width/2, 3*size+size/2, 24*size+size/2+width/2, 3*size+size/2, true, true);
        break;
    case U1:
        drawArrow(painter, 27*size+size/2+width/2, 3*size+size/2+width/2, 28*size+size/2, 4*size+size/2, true, false);
        drawArrow(painter, 28*size+size/2+width/2, 4*size+size/2-width/2, 29*size+size/2-width/2, 3*size+size/2+width/2, true, false);
        drawArrow(painter, 29*size+size/2-width/2, 3*size+size/2, 27*size+size/2+width/2, 3*size+size/2, true, false);
        break;
    case U2:
        drawArrow(painter, 32*size+size/2+width/2, 3*size+size/2+width/2, 33*size+size/2-width/2, 4*size+size/2-width/2, false, true);
        drawArrow(painter, 33*size+size/2, 4*size+size/2, 34*size+size/2-width/2, 3*size+size/2+width/2, false, true);
        drawArrow(painter, 34*size+size/2-width/2, 3*size+size/2, 32*size+size/2+width/2, 3*size+size/2, false, true);
        break;
    case J1:
        drawArrow(painter, 4*size+size/2, 7*size+size/2-width/2, 4*size+size/2, 9*size+size/2+width/2, true, true);
        drawArrow(painter, 3*size+size/2-width/2, 9*size+size/2+width/2, 4*size+size/2-width/2, 8*size+size/2+width/2, true, true);
        break;
    case J2:
        drawArrow(painter, 9*size+size/2, 7*size+size/2-width/2, 9*size+size/2, 9*size+size/2+width/2, true, true);
        drawArrow(painter, 8*size+size/2-width/2, 7*size+size/2-width/2, 9*size+size/2-width/2, 8*size+size/2-width/2, true, true);
        break;
    case R1:
        drawArrow(painter, 12*size+size/2-width/2, 7*size+size/2, 14*size+size/2+width/2, 7*size+size/2, true, true);
        drawArrow(painter, 13*size+size/2-width/2, 9*size+size/2+width/2, 14*size+size/2+width/2, 8*size+size/2-width/2, true, true);
        break;
    case R2:
        drawArrow(painter, 17*size+size/2-width/2, 7*size+size/2, 19*size+size/2+width/2, 7*size+size/2, true, true);
        drawArrow(painter, 17*size+size/2-width/2, 8*size+size/2-width/2, 18*size+size/2+width/2, 9*size+size/2+width/2, true, true);
        break;
    case T:
        drawArrow(painter, 22*size+size/2-width/2, 8*size+size/2, 24*size+size/2-width/2, 8*size+size/2, true, true);
        drawArrow(painter, 24*size+size/2, 7*size+size/2-width/2, 24*size+size/2, 9*size+size/2+width/2, true, true);
        break;
    case Y:
        drawArrow(painter, 27*size+size/2-width/2, 7*size+size/2-width/2, 29*size+size/2+width/2, 9*size+size/2+width/2, true, true);
        drawArrow(painter, 27*size+size/2-width/2, 8*size+size/2+width/2, 28*size+size/2+width/2, 7*size+size/2-width/2, true, true);
        break;
    case F:
        drawArrow(painter, 33*size+size/2, 7*size+size/2-width/2, 33*size+size/2, 9*size+size/2+width/2, true, true);
        drawArrow(painter, 34*size+size/2, 7*size+size/2-width/2, 34*size+size/2, 9*size+size/2+width/2, true, true);
        break;
    case V:
        drawArrow(painter, 3*size+size/2-width/2, 12*size+size/2-width/2, 4*size+size/2+width/2, 13*size+size/2+width/2, true, true);
        drawArrow(painter, 2*size+size/2-width/2, 12*size+size/2-width/2, 4*size+size/2+width/2, 14*size+size/2+width/2, true, true);
        break;
    case N1:
        drawArrow(painter, 7*size+size/2-width/2, 13*size+size/2, 9*size+size/2+width/2, 13*size+size/2, true, true);
        drawArrow(painter, 7*size+size/2-width/2, 14*size+size/2+width/2, 9*size+size/2+width/2, 12*size+size/2, true, true);
        break;
    case N2:
        drawArrow(painter, 12*size+size/2-width/2, 13*size+size/2, 14*size+size/2+width/2, 13*size+size/2, true, true);
        drawArrow(painter, 12*size+size/2-width/2, 12*size+size/2-width/2, 14*size+size/2+width/2, 14*size+size/2+width/2, true, true);
        break;
    case G1:
        drawArrow(painter, 19*size+size/2-width/2, 14*size+size/2-width/2, 17*size+size/2+width/2, 12*size+size/2+width/2, false, true);
        drawArrow(painter, 17*size+size/2+width/2, 12*size+size/2, 19*size+size/2-width/2, 12*size+size/2, false, true);
        drawArrow(painter, 19*size+size/2, 12*size+size/2, 19*size+size/2, 14*size+size/2-width/2, false, true);
        drawArrow(painter, 17*size+size/2+width/2, 13*size+size/2-width/2, 18*size+size/2, 12*size+size/2, true, false);
        drawArrow(painter, 18*size+size/2+width/2, 12*size+size/2+width/2, 19*size+size/2-width/2, 13*size+size/2-width/2, true, false);
        drawArrow(painter, 19*size+size/2-width/2, 13*size+size/2, 17*size+size/2+width/2, 13*size+size/2, true, false);
        break;
    case G2:
        drawArrow(painter, 24*size+size/2-width/2, 14*size+size/2-width/2, 22*size+size/2+width/2, 12*size+size/2+width/2, true, false);
        drawArrow(painter, 22*size+size/2+width/2, 12*size+size/2, 24*size+size/2, 12*size+size/2, true, false);
        drawArrow(painter, 24*size+size/2, 12*size+size/2+width/2, 24*size+size/2, 14*size+size/2-width/2, true, false);
        drawArrow(painter, 22*size+size/2+width/2, 13*size+size/2-width/2, 23*size+size/2-width/2, 12*size+size/2+width/2, false, true);
        drawArrow(painter, 23*size+size/2, 12*size+size/2, 24*size+size/2-width/2, 13*size+size/2-width/2, false, true);
        drawArrow(painter, 24*size+size/2-width/2, 13*size+size/2, 22*size+size/2+width/2, 13*size+size/2, false, true);
        break;
    case G3:
        drawArrow(painter, 27*size+size/2, 14*size+size/2-width/2, 27*size+size/2, 12*size+size/2, true, false);
        drawArrow(painter, 27*size+size/2+width/2, 12*size+size/2, 29*size+size/2-width/2, 12*size+size/2, true, false);
        drawArrow(painter, 29*size+size/2-width/2, 12*size+size/2+width/2, 27*size+size/2+width/2, 14*size+size/2-width/2, true, false);
        drawArrow(painter, 27*size+size/2+width/2, 13*size+size/2-width/2, 28*size+size/2-width/2, 12*size+size/2+width/2, false, true);
        drawArrow(painter, 28*size+size/2, 12*size+size/2, 29*size+size/2-width/2, 13*size+size/2-width/2, false, true);
        drawArrow(painter, 29*size+size/2-width/2, 13*size+size/2, 27*size+size/2+width/2, 13*size+size/2, false, true);
        break;
    case G4:
        drawArrow(painter, 32*size+size/2, 14*size+size/2-width/2, 32*size+size/2, 12*size+size/2+width/2, false, true);
        drawArrow(painter, 32*size+size/2, 12*size+size/2, 34*size+size/2-width/2, 12*size+size/2, false, true);
        drawArrow(painter, 34*size+size/2-width/2, 12*size+size/2+width/2, 32*size+size/2+width/2, 14*size+size/2-width/2, false, true);
        drawArrow(painter, 32*size+size/2+width/2, 13*size+size/2-width/2, 33*size+size/2, 12*size+size/2, true, false);
        drawArrow(painter, 33*size+size/2+width/2, 12*size+size/2+width/2, 34*size+size/2-width/2, 13*size+size/2-width/2, true, false);
        drawArrow(painter, 34*size+size/2-width/2, 13*size+size/2, 32*size+size/2+width/2, 13*size+size/2, true, false);
        break;
    default:
        break;
    }

}

void ButtonsWidget::drawArrow(QPainter &painter, int fromPointX, int fromPointY, int toPointX, int toPointY, bool arrowOnEnd, bool arrowOnStart)
{

    float fTheta = 0.8;
    int nwidth = 8;

    float temp, lineVectorX, lineVectorY, pointOnLineX, pointOnLineY, normalVectorX, normalVectorY;
    float leftPointX, leftPointY, rightPointX, rightPointY;
    float lineLength, tPointOnLine, tNormal;

    QVector<QPoint> p;
    QBrush b = painter.brush();
    QPen q = painter.pen();

    if(b == QBrush(Qt::black)){
        painter.setBrush(Qt::white);
    }
    else{
        painter.setBrush(Qt::black);
    }

    for(int i = 0; i < 2; i++){
        if(i == 0 && arrowOnEnd || i == 1 && arrowOnStart){

            if(i == 1 && arrowOnStart){
                temp = fromPointX;
                fromPointX = toPointX;
                toPointX = temp;

                temp = fromPointY;
                fromPointY = toPointY;
                toPointY = temp;
            }

            lineVectorX = toPointX - fromPointX;
            lineVectorY = toPointY - fromPointY;
            lineLength = std::sqrt(lineVectorX * lineVectorX + lineVectorY * lineVectorY);

            tPointOnLine = nwidth / (2 * (std::tan(fTheta) / 2) * lineLength);

            pointOnLineX = toPointX - tPointOnLine * lineVectorX;
            pointOnLineY = toPointY - tPointOnLine * lineVectorY;

            normalVectorX = -lineVectorY;
            normalVectorY = lineVectorX;

            tNormal = nwidth / (2 * lineLength);

            leftPointX = pointOnLineX + tNormal * normalVectorX;
            leftPointY = pointOnLineY + tNormal * normalVectorY;

            rightPointX = pointOnLineX - tNormal * normalVectorX;
            rightPointY = pointOnLineY - tNormal * normalVectorY;

            painter.drawLine(fromPointX, fromPointY, pointOnLineX, pointOnLineY);

            p.clear();

            p.append(QPoint(toPointX, toPointY));
            p.append(QPoint(leftPointX, leftPointY));
            p.append(QPoint(rightPointX, rightPointY));

            painter.setPen(QPen(q.color(), 0));
            painter.drawPolygon(QPolygon(p));
            painter.setPen(QPen(q.color(), 2));
        }
    }

    painter.setBrush(b);
}
