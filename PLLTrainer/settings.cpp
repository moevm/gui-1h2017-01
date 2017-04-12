#include "settings.h"

Settings::Settings()
{
    downColor = WHITE;
    isMulticolor = false;
    doSetupMove = true;
    attempts = 12;
}

const Settings &Settings::Instance()
{
    static Settings theSingleInstance;
    return theSingleInstance;
}
