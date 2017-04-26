#include "settings.h"

Settings::Settings()
{
    downColor =   YELLOW;
    isMulticolor = false;
    doSetupMove = true;
    attempts = 12;
}

Settings &Settings::Instance()
{
    static Settings theSingleInstance;
    return theSingleInstance;
}
