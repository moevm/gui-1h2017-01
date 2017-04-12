#include "settings.h"

Settings::Settings()
{
    downColor = WHITE;
    isMulticolor = false;
    doSetupMove = true;
}

const Settings &Settings::Instance()
{
    static Settings theSingleInstance;
    return theSingleInstance;
}
