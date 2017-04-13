#include "cube.h"
#include <QTime>
#include <array>
Cube::Cube()
{
    upColor = WHITE;
    rightColor = BLUE;
    frontColor = RED;
    mainColors[0] = RED;
    mainColors[1] = RED;
    mainColors[2] = RED;
    mainColors[3] = BLUE;
    mainColors[4] = BLUE;
    mainColors[5] = BLUE;
}

PLLCase Cube::scrabmle()
{

    CubeColor downColor;
    qsrand(QTime::currentTime().msec());

    if(Settings::Instance().isMulticolor){
        downColor = (CubeColor)(qrand() % SIDECOUNT);
    }
    else{
        downColor = Settings::Instance().downColor;
    }

    int yAfter = qrand() % ROTATESCOUNT;
    int yBefore = qrand() % ROTATESCOUNT;
    int uAfter = Settings::Instance().doSetupMove? qrand() % ROTATESCOUNT: 0;

    PLLCase pllCase = (PLLCase)(qrand() % CASECOUNT);

    std::array<CubeColor, ROTATESCOUNT> sideColors;

    switch (downColor) {
    case WHITE:
        sideColors = {GREEN, RED, BLUE, ORANGE};
        upColor = YELLOW;
        break;
    case YELLOW:
        sideColors = {GREEN, ORANGE, BLUE, RED};
        upColor = WHITE;
        break;
    case GREEN:
        sideColors = {WHITE, ORANGE, YELLOW, RED};
        upColor = BLUE;
        break;
    case BLUE:
        sideColors = {WHITE, RED, YELLOW, ORANGE};
        upColor = GREEN;
        break;
    case RED:
        sideColors = {WHITE, GREEN, YELLOW, BLUE};
        upColor = ORANGE;
        break;
    case ORANGE:
        sideColors = {WHITE, BLUE, YELLOW, GREEN};
        upColor = RED;
        break;
    default:
        sideColors = {GREEN, RED, BLUE, ORANGE};
        upColor = WHITE;
        break;
    }

    std::array<CubeColor, ROTATESCOUNT * 2> sideColorsDoubled;

    for(int i = 0; i < ROTATESCOUNT * 2; i++){
        sideColorsDoubled[i] = sideColors[(yBefore + i) % ROTATESCOUNT];
    }

    rightColor = sideColorsDoubled[ROTATESCOUNT * 2 - 1];
    frontColor = sideColorsDoubled[0];

    std::array<int, PIECESPERSIDE - 1> algo = getAlgorithm(pllCase);
    std::array<int, PIECESPERSIDE - 1> rotatedAlgo;

    // модификация алгоритма в зависимости от поворота
    for(int i = 2 * yAfter; i < PIECESPERSIDE - 1 + 2 * yAfter; i++){
        rotatedAlgo[i - 2 * yAfter] = algo[i % (PIECESPERSIDE - 1)];
    }

    mainColors[0] = sideColorsDoubled[rotatedAlgo[0] + uAfter];
    mainColors[1] = sideColorsDoubled[rotatedAlgo[1] + uAfter];
    mainColors[2] = sideColorsDoubled[rotatedAlgo[2] + uAfter];

    CubeColor tempColor = sideColorsDoubled[PIECESPERSIDE - 2];
    for(int i = PIECESPERSIDE - 2; i > 0; i--){
        sideColorsDoubled[i] = sideColorsDoubled[i - 1];
    }
    sideColorsDoubled[0] = tempColor;

    mainColors[3] = sideColorsDoubled[rotatedAlgo[2] + uAfter];
    mainColors[4] = sideColorsDoubled[rotatedAlgo[3] + uAfter];
    mainColors[5] = sideColorsDoubled[rotatedAlgo[4] + uAfter];

    return pllCase;
}

std::array<int, Cube::PIECESPERSIDE - 1> Cube::getAlgorithm(PLLCase pllCase)
{
    std::array<int, Cube::PIECESPERSIDE - 1> algo;
    switch (pllCase) {
    case A1:
        algo = {0, 0, 2, 0, 1, 0, 1, 0};
        break;
    case A2:
        algo = {0, 0, 3, 0, 3, 0, 2, 0};
        break;
    case E:
        algo = {1, 0, 3, 0, 1, 0, 3, 0};
        break;
    case Z:
        algo = {0, 3, 0, 1, 0, 3, 0, 1};
        break;
    case H:
        algo = {0, 2, 0, 2, 0, 2, 0, 2};
        break;
    case U1:
        algo = {0, 3, 0, 2, 0, 0, 0, 3};
        break;
    case U2:
        algo = {0, 1, 0, 1, 0, 0, 0, 2};
        break;
    case J1:
        algo = {0, 3, 3, 1, 1, 0, 0, 0};
        break;
    case J2:
        algo = {0, 0, 3, 3, 1, 1, 0, 0};
        break;
    case R1:
        algo = {0, 3, 0, 1, 3, 0, 1, 0};
        break;
    case R2:
        algo = {0, 1, 0, 0, 3, 0, 1, 3};
        break;
    case T:
        algo = {0, 0, 3, 2, 1, 0, 0, 2};
        break;
    case Y:
        algo = {0, 0, 2, 0, 0, 3, 2, 1};
        break;
    case F:
        algo = {0, 2, 3, 0, 1, 2, 0, 0};
        break;
    case V:
        algo = {0, 0, 2, 3, 0, 1, 2, 0};
        break;
    case N1:
        algo = {2, 0, 0, 2, 2, 0, 0, 2};
        break;
    case N2:
        algo = {0, 0, 2, 2, 0, 0, 2, 2};
        break;
    case G1:
        algo = {0, 0, 3, 2, 3, 1, 2, 1};
        break;
    case G2:
        algo = {0, 0, 2, 3, 1, 3, 1, 2};
        break;
    case G3:
        algo = {1, 0, 0, 3, 2, 3, 1, 2};
        break;
    case G4:
        algo = {2, 0, 0, 2, 3, 1, 3, 1};
        break;
    default:
        algo = {0, 0, 0, 0, 0, 0, 0, 0};
        break;
    }
    return algo;
}

const QString Cube::getPLLName(PLLCase pllCase)
{
    switch (pllCase) {
    case A1:
        return "A1";
    case A2:
        return "A2";
    case E:
        return "E";
    case Z:
        return "Z";
    case H:
        return "H";
    case U1:
        return "U1";
    case U2:
        return "U2";
    case J1:
        return "J1";
    case J2:
        return "J2";
    case R1:
        return "R1";
    case R2:
        return "R2";
    case T:
        return "T";
    case Y:
        return "Y";
    case F:
        return "F";
    case V:
        return "V";
    case N1:
        return "N1";
    case N2:
        return "N2";
    case G1:
        return "G1";
    case G2:
        return "G2";
    case G3:
        return "G3";
    case G4:
        return "G4";
    default:
        return "BLANK";
    }
}
