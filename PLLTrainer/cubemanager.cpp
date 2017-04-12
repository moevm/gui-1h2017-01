#include "cubemanager.h"
#include <QDebug>

CubeManager::CubeManager(Cube* cube)
{
    this->cube = cube;
    isSession = false;
}

void CubeManager::startSession() {
    currentPLLCase = cube->scrabmle();
    isSession = true;
    currentAttempts = 0;
    currentSuccessfulAttempts = 0;
}

bool CubeManager::checkUserChoice(PLLCase userChoice) {
    bool isCorrect = userChoice == currentPLLCase;
    currentPLLCase = cube->scrabmle();


    //just for debug, don't be scared
    QList<QString> names = {"A1", "A2", "E", "Z", "H", "U1", "U2", "J1", "J2", "R1", "R2",
                               "T", "Y", "F", "V", "N1", "N2", "G1", "G2", "G3", "G4"};
    qDebug() << "(" << names[currentPLLCase] << ")";


    if (isCorrect) currentSuccessfulAttempts++;
    currentAttempts++;
    if (currentAttempts == Settings::Instance().attempts) {
        isSession = false;
    }
    return isCorrect;
}

