#include "cubemanager.h"
#include <QDebug>

CubeManager::CubeManager(Cube* cube)
{
    this->cube = cube;
    isSession = false;
    isPaused = false;
    spentTime = QTime(0, 0, 0, 0);
    lastTime = QTime::currentTime();
}

void CubeManager::startSession() {
    currentPLLCase = cube->scrabmle();
    isSession = true;
    currentAttempts = 0;
    currentSuccessfulAttempts = 0;
    spentTime = QTime(0, 0, 0, 0);
    lastTime = QTime::currentTime();
    isPaused = false;
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
    QString timeString = spentTime.toString("mm:ss.zzz");
    timeString.chop(1);
    return timeString;
}

void CubeManager::finishSession() {
    isSession = false;
    isPaused = false;
}

void CubeManager::updateTimer() {

    if (isSession && !isPaused) {
        int ms = lastTime.msecsTo(QTime::currentTime());
        spentTime = spentTime.addMSecs(ms);
    }

    lastTime = QTime::currentTime();
}

void CubeManager::pauseSession() {
    isPaused = true;
}

void CubeManager::continueSession() {
    isPaused = false;
}
