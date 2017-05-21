#ifndef PLLCASEDRAWER_H
#define PLLCASEDRAWER_H

#include "pllcases.h"
#include <QPainter>

class PLLCaseDrawer{
public:
    static void drawPLLCase(QPainter &painter, PLLCase pllcase, int x, int y, int size, int width, bool hovered,
                            int rotation, bool showStat = false, int percentsStat = 0);
    static float fTheta; // Верхний угол равнобедренного треугольника стрелки в радианах
    static int nwidth; // Ширина основания равнобедренного треугольника стрелки в пикселях

private:
    static void drawArrow(QPainter &painter, int fromPointX, int fromPointY, int toPointX, int toPointY,
                          bool arrowOnEnd, bool arrowOnStart);
    static int centerX;
    static int centerY;
    static int rot;
};

#endif // PLLCASEDRAWER_H
