#ifndef CUBEMANAGER_H
#define CUBEMANAGER_H
#include <QTime>
#include <QString>
#include "cube.h"

class CubeManager
{
public:

    bool isSession;
    bool isPaused;
    int currentAttempts;
    int currentSuccessfulAttempts;
    PLLCase currentPLLCase;
    QTime spentTime, lastTime;

    CubeManager(Cube* cube);
    void startSession();
    void pauseSession();
    void continueSession();
    void updateTimer();
    bool checkUserChoice(PLLCase userChoice);
    QString getTimerValueString();
    void finishSession();



private:

    Cube* cube;




};


#endif // CUBEMANAGER_H
