#ifndef CUBEMANAGER_H
#define CUBEMANAGER_H
#include "cube.h"

class CubeManager
{
public:

    bool isSession;
    int currentAttempts;
    int currentSuccessfulAttempts;
    PLLCase currentPLLCase;

    CubeManager(Cube* cube);
    void startSession();
    bool checkUserChoice(PLLCase userChoice);


private:

    Cube* cube;




};


#endif // CUBEMANAGER_H
