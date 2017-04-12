#ifndef CUBE_H
#define CUBE_H

#include "settings.h"
#include "cubecolors.h"
#include <QList>

enum PLLCase{
    A1, A2, E, Z, H, U1, U2, J1, J2, R1, R2, T, Y, F, V, N1, N2, G1, G2, G3, G4
};

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

    CubeColor upColor;
    CubeColor frontColor;
    CubeColor rightColor;
    CubeColor mainColors[6];
};

#endif // CUBE_H
