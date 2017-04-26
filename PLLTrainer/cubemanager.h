#ifndef CUBEMANAGER_H
#define CUBEMANAGER_H
#include <QTime>
#include <QString>
#include "cube.h"

class CubeManager
{
public:

    bool isSession;
    int currentAttempts;
    int currentSuccessfulAttempts;
    PLLCase currentPLLCase;
    QTime startTime;
    QTime finishTime;

    CubeManager(Cube* cube);
    void startSession();
    bool checkUserChoice(PLLCase userChoice);
    QString getTimerValueString();
    void finishSession();



private:

    Cube* cube;




};


#endif // CUBEMANAGER_H
