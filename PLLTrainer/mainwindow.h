#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cubewidget.h"
#include "cubemanager.h"
#include <QKeyEvent>
#include <QList>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CubeManager* cubeManager;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    Qt::Key firstLetter;
    void keyPressEvent(QKeyEvent *event);
    QList<QString> pllNames = {"A1", "A2", "E", "Z", "H", "U1", "U2", "J1", "J2", "R1", "R2",
                               "T", "Y", "F", "V", "N1", "N2", "G1", "G2", "G3", "G4"};


};

#endif // MAINWINDOW_H
