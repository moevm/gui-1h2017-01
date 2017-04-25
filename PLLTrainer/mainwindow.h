#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cubewidget.h"
#include "cubemanager.h"
#include <QKeyEvent>
#include <QList>
#include <QString>
#include <QTimer>
#include "settingsform.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    const int UPDATE_TIME = 40;

    CubeManager* cubeManager;
    explicit MainWindow(QWidget *parent = 0);
    void setResults(bool result, PLLCase lastPLLCase);
    Qt::Key firstLetter;
    QTimer* timer;
    ~MainWindow();

private slots:
    void on_startButton_clicked();
    void updateTimer();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    SettingsForm *settingsform;
    void keyPressEvent(QKeyEvent *event);
    QList<QString> pllNames = {"A1", "A2", "E", "Z", "H", "U1", "U2", "J1", "J2", "R1", "R2",
                               "T", "Y", "F", "V", "N1", "N2", "G1", "G2", "G3", "G4"};


};

#endif // MAINWINDOW_H
