#ifndef CUBE_H
#define CUBE_H

#include "settings.h"
#include "cubecolors.h"
#include "pllcases.h"
#include <QList>
#include <QString>
#include <array>

class Cube
{
public:
    Cube();

    static const int CASECOUNT = 21;
    static const int SIDECOUNT = 6;
    static const int ROTATESCOUNT = 4;
    static const int PIECESPERSIDE = 9;

    PLLCase scrabmle();
    std::array<int, PIECESPERSIDE - 1> getAlgorithm(PLLCase pllCase);
    static const QString getPLLName(PLLCase pllCase);

    CubeColor upColor;
    CubeColor frontColor;
    CubeColor rightColor;
    CubeColor mainColors[6];
};

#endif // CUBE_H
