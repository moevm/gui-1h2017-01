#include "pllcasedrawer.h"

float PLLCaseDrawer::fTheta = 0.8;
int PLLCaseDrawer::nwidth = 8;

void PLLCaseDrawer::drawPLLCase(QPainter &painter, PLLCase pllcase, int x, int y, int size, int width, bool hovered)
{

    QBrush saveBrush = painter.brush();
    QPen savePen = painter.pen();

    nwidth = width * 2;

    if(hovered){
        painter.setBrush(QBrush(Qt::black));
        painter.drawRect(x * size, y * size, 3 * size, 3 * size);
        painter.setPen(QPen(Qt::white, width/2));
    }
    else{
        painter.setBrush(QBrush(Qt::white));
        painter.drawRect(x * size, y * size, 3 * size, 3 * size);
        painter.setPen(QPen(Qt::black, width/2));
    }

    switch (pllcase) {
    case A1:
        drawArrow(painter, (x+2)*size+size/2-width/2, (y+3)*size-size/2-width/2, x*size+size/2+width/2, (y+1)*size-size/2+width/2, true, false);
        drawArrow(painter, x*size+size/2+width/2, y*size+size/2, (x+2)*size+size/2, y*size+size/2, true, false);
        drawArrow(painter, (x+2)*size+size/2, y*size+size/2+width/2, (x+2)*size+size/2, (y+2)*size+size/2-width/2, true, false);
        break;
    case A2:
        drawArrow(painter, (x+2)*size+size/2-width/2, (y+2)*size+size/2-width/2, x*size+size/2+width/2, y*size+size/2+width/2, false, true);
        drawArrow(painter, x*size+size/2+width/2, y*size+size/2, (x+2)*size+size/2-width/2, y*size+size/2, false, true);
        drawArrow(painter, (x+2)*size+size/2, y*size+size/2, (x+2)*size+size/2, (y+2)*size+size/2-width/2, false, true);
        break;
    case E:
        drawArrow(painter, x*size+size/2, y*size+size/2-width/2, x*size+size/2, (y+2)*size+size/2+width/2, true, true);
        drawArrow(painter, (x+2)*size+size/2, y*size+size/2-width/2, (x+2)*size+size/2, (y+2)*size+size/2+width/2, true, true);
        break;
    case Z:
        drawArrow(painter, x*size+size/2-width/2, (y+1)*size+size/2+width/2, (x+1)*size+size/2+width/2, y*size+size/2-width/2, true, true);
        drawArrow(painter, (x+1)*size+size/2-width/2, (y+2)*size+size/2+width/2, (x+2)*size+size/2+width/2, (y+1)*size+size/2-width/2, true, true);
        break;
    case H:
        drawArrow(painter, (x+1)*size+size/2, y*size+size/2-width/2, (x+1)*size+size/2, (y+2)*size+size/2+width/2, true, true);
        drawArrow(painter, x*size+size/2-width/2, (y+1)*size+size/2, (x+2)*size+size/2+width/2, (y+1)*size+size/2, true, true);
        break;
    case U1:
        drawArrow(painter, x*size+size/2+width/2, (y+1)*size+size/2+width/2, (x+1)*size+size/2, (y+2)*size+size/2, true, false);
        drawArrow(painter, (x+1)*size+size/2+width/2, (y+2)*size+size/2-width/2, (x+2)*size+size/2-width/2, (y+1)*size+size/2+width/2, true, false);
        drawArrow(painter, (x+2)*size+size/2-width/2, (y+1)*size+size/2, x*size+size/2+width/2, (y+1)*size+size/2, true, false);
        break;
    case U2:
        drawArrow(painter, x*size+size/2+width/2, (y+1)*size+size/2+width/2, (x+1)*size+size/2-width/2, (y+2)*size+size/2-width/2, false, true);
        drawArrow(painter, (x+1)*size+size/2, (y+2)*size+size/2, (x+2)*size+size/2-width/2, (y+1)*size+size/2+width/2, false, true);
        drawArrow(painter, (x+2)*size+size/2-width/2, (y+1)*size+size/2, x*size+size/2+width/2, (y+1)*size+size/2, false, true);
        break;
    case J1:
        drawArrow(painter, (x+2)*size+size/2, y*size+size/2-width/2, (x+2)*size+size/2, (y+2)*size+size/2+width/2, true, true);
        drawArrow(painter, (x+1)*size+size/2-width/2, (y+2)*size+size/2+width/2, (x+2)*size+size/2-width/2, (y+1)*size+size/2+width/2, true, true);
        break;
    case J2:
        drawArrow(painter, (x+2)*size+size/2, y*size+size/2-width/2, (x+2)*size+size/2, (y+2)*size+size/2+width/2, true, true);
        drawArrow(painter, (x+1)*size+size/2-width/2, y*size+size/2-width/2, (x+2)*size+size/2-width/2, (y+1)*size+size/2-width/2, true, true);
        break;
    case R1:
        drawArrow(painter, x*size+size/2-width/2, y*size+size/2, (x+2)*size+size/2+width/2, y*size+size/2, true, true);
        drawArrow(painter, (x+1)*size+size/2-width/2, (y+2)*size+size/2+width/2, (x+2)*size+size/2+width/2, (y+1)*size+size/2-width/2, true, true);
        break;
    case R2:
        drawArrow(painter, x*size+size/2-width/2, y*size+size/2, (x+2)*size+size/2+width/2, y*size+size/2, true, true);
        drawArrow(painter, x*size+size/2-width/2, (y+1)*size+size/2-width/2, (x+1)*size+size/2+width/2, (y+2)*size+size/2+width/2, true, true);
        break;
    case T:
        drawArrow(painter, x*size+size/2-width/2, (y+1)*size+size/2, (x+2)*size+size/2-width/2, (y+1)*size+size/2, true, true);
        drawArrow(painter, (x+2)*size+size/2, y*size+size/2-width/2, (x+2)*size+size/2, (y+2)*size+size/2+width/2, true, true);
        break;
    case Y:
        drawArrow(painter, x*size+size/2-width/2, y*size+size/2-width/2, (x+2)*size+size/2+width/2, (y+2)*size+size/2+width/2, true, true);
        drawArrow(painter, x*size+size/2-width/2, (y+1)*size+size/2+width/2, (x+1)*size+size/2+width/2, y*size+size/2-width/2, true, true);
        break;
    case F:
        drawArrow(painter, (x+1)*size+size/2, y*size+size/2-width/2, (x+1)*size+size/2, (y+2)*size+size/2+width/2, true, true);
        drawArrow(painter, (x+2)*size+size/2, y*size+size/2-width/2, (x+2)*size+size/2, (y+2)*size+size/2+width/2, true, true);
        break;
    case V:
        drawArrow(painter, (x+1)*size+size/2-width/2, y*size+size/2-width/2, (x+2)*size+size/2+width/2, (y+1)*size+size/2+width/2, true, true);
        drawArrow(painter, x*size+size/2-width/2, y*size+size/2-width/2, (x+2)*size+size/2+width/2, (y+2)*size+size/2+width/2, true, true);
        break;
    case N1:
        drawArrow(painter, x*size+size/2-width/2, (y+1)*size+size/2, (x+2)*size+size/2+width/2, (y+1)*size+size/2, true, true);
        drawArrow(painter, x*size+size/2-width/2, (y+2)*size+size/2+width/2, (x+2)*size+size/2+width/2, y*size+size/2, true, true);
        break;
    case N2:
        drawArrow(painter, x*size+size/2-width/2, (y+1)*size+size/2, (x+2)*size+size/2+width/2, (y+1)*size+size/2, true, true);
        drawArrow(painter, x*size+size/2-width/2, y*size+size/2-width/2, (x+2)*size+size/2+width/2, (y+2)*size+size/2+width/2, true, true);
        break;
    case G1:
        drawArrow(painter, (x+2)*size+size/2-width/2, (y+2)*size+size/2-width/2, x*size+size/2+width/2, y*size+size/2+width/2, false, true);
        drawArrow(painter, x*size+size/2+width/2, y*size+size/2, (x+2)*size+size/2-width/2, y*size+size/2, false, true);
        drawArrow(painter, (x+2)*size+size/2, y*size+size/2, (x+2)*size+size/2, (y+2)*size+size/2-width/2, false, true);
        drawArrow(painter, x*size+size/2+width/2, (y+1)*size+size/2-width/2, (x+1)*size+size/2, y*size+size/2, true, false);
        drawArrow(painter, (x+1)*size+size/2+width/2, y*size+size/2+width/2, (x+2)*size+size/2-width/2, (y+1)*size+size/2-width/2, true, false);
        drawArrow(painter, (x+2)*size+size/2-width/2, (y+1)*size+size/2, x*size+size/2+width/2, (y+1)*size+size/2, true, false);
        break;
    case G2:
        drawArrow(painter, (x+2)*size+size/2-width/2, (y+2)*size+size/2-width/2, x*size+size/2+width/2, y*size+size/2+width/2, true, false);
        drawArrow(painter, x*size+size/2+width/2, y*size+size/2, (x+2)*size+size/2, y*size+size/2, true, false);
        drawArrow(painter, (x+2)*size+size/2, y*size+size/2+width/2, (x+2)*size+size/2, (y+2)*size+size/2-width/2, true, false);
        drawArrow(painter, x*size+size/2+width/2, (y+1)*size+size/2-width/2, (x+1)*size+size/2-width/2, y*size+size/2+width/2, false, true);
        drawArrow(painter, (x+1)*size+size/2, y*size+size/2, (x+2)*size+size/2-width/2, (y+1)*size+size/2-width/2, false, true);
        drawArrow(painter, (x+2)*size+size/2-width/2, (y+1)*size+size/2, x*size+size/2+width/2, (y+1)*size+size/2, false, true);
        break;
    case G3:
        drawArrow(painter, x*size+size/2, (y+2)*size+size/2-width/2, x*size+size/2, y*size+size/2, true, false);
        drawArrow(painter, x*size+size/2+width/2, y*size+size/2, (x+2)*size+size/2-width/2, y*size+size/2, true, false);
        drawArrow(painter, (x+2)*size+size/2-width/2, y*size+size/2+width/2, x*size+size/2+width/2, (y+2)*size+size/2-width/2, true, false);
        drawArrow(painter, x*size+size/2+width/2, (y+1)*size+size/2-width/2, (x+1)*size+size/2-width/2, y*size+size/2+width/2, false, true);
        drawArrow(painter, (x+1)*size+size/2, y*size+size/2, (x+2)*size+size/2-width/2, (y+1)*size+size/2-width/2, false, true);
        drawArrow(painter, (x+2)*size+size/2-width/2, (y+1)*size+size/2, x*size+size/2+width/2, (y+1)*size+size/2, false, true);
        break;
    case G4:
        drawArrow(painter, x*size+size/2, (y+2)*size+size/2-width/2, x*size+size/2, y*size+size/2+width/2, false, true);
        drawArrow(painter, x*size+size/2, y*size+size/2, (x+2)*size+size/2-width/2, y*size+size/2, false, true);
        drawArrow(painter, (x+2)*size+size/2-width/2, y*size+size/2+width/2, x*size+size/2+width/2, (y+2)*size+size/2-width/2, false, true);
        drawArrow(painter, x*size+size/2+width/2, (y+1)*size+size/2-width/2, (x+1)*size+size/2, y*size+size/2, true, false);
        drawArrow(painter, (x+1)*size+size/2+width/2, y*size+size/2+width/2, (x+2)*size+size/2-width/2, (y+1)*size+size/2-width/2, true, false);
        drawArrow(painter, (x+2)*size+size/2-width/2, (y+1)*size+size/2, x*size+size/2+width/2, (y+1)*size+size/2, true, false);
        break;
    default:
        break;
    }

    painter.setPen(savePen);
    painter.setBrush(saveBrush);
}

void PLLCaseDrawer::drawArrow(QPainter &painter, int fromPointX, int fromPointY, int toPointX, int toPointY,
                              bool arrowOnEnd, bool arrowOnStart)
{

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
            lineLength = sqrt(lineVectorX * lineVectorX + lineVectorY * lineVectorY);

            tPointOnLine = nwidth / (2 * (tan(fTheta) / 2) * lineLength);

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
