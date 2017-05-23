#ifndef STATISTICS_H
#define STATISTICS_H

#include "pllcases.h"
#include <QString>
#include <QMap>
#include <QPair>

class Statistics
{
    const QString statFile = "statistics.txt";
    QMap<PLLCase, QPair<int, int>> map;

public:
    Statistics();
    QPair<int, int> overall;
    QPair<int, int> getStats(PLLCase pllcase);
    void addStats(PLLCase pllcase, bool solved);
};

#endif // STATISTICS_H
