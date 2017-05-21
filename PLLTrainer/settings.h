#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMap>
#include <QPair>
#include <QString>
#include "cubecolors.h"
#include "statistics.h"

enum Language{
    Russian, English, German
};

class Settings
{
public:
    static Settings& Instance();

    CubeColor downColor;
    bool isMulticolor;
    bool doSetupMove; // Сделать ли дополнительный ход после применения PLL алгоритма
    int attempts;
    Language language;
    Statistics stat;

    QString getStr(QString str);

private:
    bool initialized;
    QMap< QPair<QString, Language>, QString > strs;
    Settings();
    void add(QString str, Language lang, QString res);
    void initMultilang();
};

#endif // SETTINGS_H
