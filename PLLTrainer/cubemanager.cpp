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
    startTime = QTime::currentTime();
}

bool CubeManager::checkUserChoice(PLLCase userChoice) {

    bool isCorrect = userChoice == currentPLLCase;
    currentPLLCase = cube->scrabmle();
    if (isCorrect) currentSuccessfulAttempts++;
    currentAttempts++;
    if (currentAttempts == Settings::Instance().attempts) finishSession();
    return isCorrect;
}

QString CubeManager::getTimerValueString() {
    int ms;
    if (isSession) ms = startTime.msecsTo(QTime::currentTime());
    else ms = startTime.msecsTo(finishTime);
    QTime time(0, 0, 0, 0);
    time = time.addMSecs(ms);
    QString timeString = time.toString("mm:ss.zzz");
    timeString.chop(1);
    return timeString;
}

void CubeManager::finishSession() {
    isSession = false;
    finishTime = QTime::currentTime();
    qDebug() << "finish set";
}

