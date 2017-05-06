#include "settings.h"

Settings::Settings()
{
    downColor = YELLOW;
    isMulticolor = false;
    doSetupMove = true;
    attempts = 12;
    language = Russian;

    strs = QMap< QPair<QString, Language>, QString >();
    initialized = false;
}

{
}

Settings &Settings::Instance()
{
    static Settings theSingleInstance;
    if(theSingleInstance.initialized == false) theSingleInstance.initMultilang();
    return theSingleInstance;
}

{
}

void Settings::initMultilang()
{
    initialized = true;

    add("start", Russian, "Начать");
    add("start", English, "Start");
    add("start", German, "Anfang");

    add("stop", Russian, "Закончить");
    add("stop", English, "Stop");
    add("stop", German, "Halt");

    add("sets", Russian, "Настройки");
    add("sets", English, "Settings");
    add("sets", German, "Einstellungen");

    add("result", Russian, "Результат");
    add("result", English, "Result");
    add("result", German, "Ergebnis");

    add("no", Russian, "Нет, это");
    add("no", English, "No, it was");
    add("no", German, "Nein, das war es");

    add("yes", Russian, "Правильно");
    add("yes", English, "Right");
    add("yes", German, "Recht");

    add("count of attempts", Russian, "Количество попыток");
    add("count of attempts", English, "Count of attempts");
    add("count of attempts", German, "Graf von Versuchen");

    add("down color", Russian, "Цвет нижней грани");
    add("down color", English, "Color of the bottom side");
    add("down color", German, "Farbe der Unterseite");

    add("multicolor mode", Russian, "Режим случайного цвета нижней грани");
    add("multicolor mode", English, "Random color of the bottom side mode");
    add("multicolor mode", German, "Zufällige Farbe des unteren Seitenmodus");

    add("hard mode", Russian, "Режим усложнённых случаев");
    add("hard mode", English, "Mode with hard cases");
    add("hard mode", German, "Modus mit harten Fällen");

    add("white", Russian, "Белый");
    add("white", English, "White");
    add("white", German, "Weiß");

    add("yellow", Russian, "Жёлтый");
    add("yellow", English, "Yellow");
    add("yellow", German, "Gelb");

    add("blue", Russian, "Синий");
    add("blue", English, "Blue");
    add("blue", German, "Blau");

    add("green", Russian, "Зелёный");
    add("green", English, "Green");
    add("green", German, "Grün");

    add("red", Russian, "Красный");
    add("red", English, "Red");
    add("red", German, "Rot");

    add("orange", Russian, "Оранжевый");
    add("orange", English, "Orange");
    add("orange", German, "Orange");

    add("save", Russian, "Сохранить");
    add("save", English, "Save");
    add("save", German, "Sparen");

    add("cancel", Russian, "Отменить");
    add("cancel", English, "Cancel");
    add("cancel", German, "Stornieren");
}
