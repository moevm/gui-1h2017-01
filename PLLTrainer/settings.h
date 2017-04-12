#ifndef SETTINGS_H
#define SETTINGS_H

#include "cubecolors.h"

class Settings
{
public:
    static const Settings& Instance();

    CubeColor downColor;
    bool isMulticolor;
    bool doSetupMove; // Сделать ли дополнительный ход после применения PLL алгоритма
    int attempts;

private:
    Settings();
};

#endif // SETTINGS_H
