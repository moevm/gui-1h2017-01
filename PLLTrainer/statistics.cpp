#include "statistics.h"
#include <QFile>
#include <QTextStream>

Statistics::Statistics()
{
    map = QMap<PLLCase, QPair<int, int>>();
    overall = QPair<int, int>(0, 0);

    QFile fileOut(statFile);

    if(fileOut.exists()){

        fileOut.open(QIODevice::ReadWrite);

        QString str = fileOut.readLine();
        QStringList values;
        values = str.split(" ");
        fileOut.close();

        try{
            int v1, v2;
            for(int i = 0; i < CASECOUNT; i++){
                v1 = values[2*i].toInt();
                v2 = values[2*i+1].toInt();
                map.insert((PLLCase) i, QPair<int, int>(v1, v2));
                overall.first += v1;
                overall.second += v2;
            }
        }
        catch(...){
            for(int i = 0; i < CASECOUNT; i++){
                map.insert((PLLCase) i, QPair<int, int>(0, 0));
            }
        }
    }
    else{
        QFile file(statFile);
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);

            for(int i = 0; i < CASECOUNT; i++){
                stream << "0 0 ";
                map.insert((PLLCase) i, QPair<int, int>(0, 0));
            }
        }
        file.close();
    }
}

QPair<int, int> Statistics::getStats(PLLCase pllcase)
{
    return map.value(pllcase, QPair<int, int>(0, 0));
}

void Statistics::addStats(PLLCase pllcase, bool solved)
{
    QPair<int, int> current = getStats(pllcase);

    if(solved){
        current.first++;
        overall.first++;
    }
    current.second++;
    overall.second++;

    map.insert(pllcase, current);

    QFile fileOut(statFile);
    fileOut.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
    QTextStream writeStream(&fileOut);

    for(int i = 0; i < CASECOUNT; i++){
        current = getStats((PLLCase) i);
        writeStream << QString::number(current.first) + " " + QString::number(current.second) + " ";
    }

    fileOut.flush();
    fileOut.close();
}
