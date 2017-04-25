#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cubemanager.h"
#include <QDebug>
#include "settingsform.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->cubeManager = new CubeManager(ui->cubeWidget->cube);
    ui->buttons->cubeManager = this->cubeManager;
    ui->buttons->mw = this;
    timer = new QTimer(this);
    settingsform = new SettingsForm(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
    connect(ui->pushButton, SIGNAL(clicked()), settingsform , SLOT(show()));
    timer->start(UPDATE_TIME);

}

void MainWindow::setResults(bool result, PLLCase lastPLLCase)
{
    QString succAttempts = QString::number(cubeManager->currentSuccessfulAttempts);
    QString attempts = QString::number(cubeManager->currentAttempts);

    if (result) {
        ui->resultLabel->setText("Right! (" + succAttempts + "/" + attempts + ")");
        ui->resultLabel->setStyleSheet("QLabel { color : green; }");
    }
    else {
        ui->resultLabel->setText("No, that was " + pllNames[lastPLLCase] + " (" + succAttempts + "/" + attempts + ")");
        ui->resultLabel->setStyleSheet("QLabel { color : red; }");
    }
    if (cubeManager->currentAttempts == Settings::Instance().attempts) {
        int rate = 100 * (float) cubeManager->currentSuccessfulAttempts / Settings::Instance().attempts;
        ui->totalResultLabel->setText("Your result: " + QString::number(rate) + "%");
    }

    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    cubeManager->startSession();
    ui->resultLabel->clear();
    ui->totalResultLabel->clear();
    update();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {

    if (!cubeManager->isSession) return;

    PLLCase lastPLLCase = cubeManager->currentPLLCase;
    bool isCorrect = false;
    switch (event->key()) {

    //one-letter cases
    case Qt::Key_E:
        isCorrect = cubeManager->checkUserChoice(E);
        break;
    case Qt::Key_Z:
        isCorrect = cubeManager->checkUserChoice(Z);
        break;
    case Qt::Key_H:
        isCorrect = cubeManager->checkUserChoice(H);
        break;
    case Qt::Key_T:
        isCorrect = cubeManager->checkUserChoice(T);
        break;
    case Qt::Key_Y:
        isCorrect = cubeManager->checkUserChoice(Y);
        break;
    case Qt::Key_F:
        isCorrect = cubeManager->checkUserChoice(F);
        break;
    case Qt::Key_V:
        isCorrect = cubeManager->checkUserChoice(V);
        break;

    //first letter save in two-letter cases
    case Qt::Key_A:
        firstLetter = Qt::Key_A;
        return;
    case Qt::Key_U:
        firstLetter = Qt::Key_U;
        return;
    case Qt::Key_J:
        firstLetter = Qt::Key_J;
        return;
    case Qt::Key_R:
        firstLetter = Qt::Key_R;
        return;
    case Qt::Key_N:
        firstLetter = Qt::Key_N;
        return;
    case Qt::Key_G:
        firstLetter = Qt::Key_G;
        return;

    //second letter check in two-letter cases
    case Qt::Key_1:
        switch (firstLetter) {
        case Qt::Key_A:
            isCorrect = cubeManager->checkUserChoice(A1);
            break;
        case Qt::Key_U:
            isCorrect = cubeManager->checkUserChoice(U1);
            break;
        case Qt::Key_J:
            isCorrect = cubeManager->checkUserChoice(J1);
            break;
        case Qt::Key_R:
            isCorrect = cubeManager->checkUserChoice(R1);
            break;
        case Qt::Key_N:
            isCorrect = cubeManager->checkUserChoice(N1);
            break;
        case Qt::Key_G:
            isCorrect = cubeManager->checkUserChoice(G1);
            break;
        default:
            firstLetter = Qt::Key_No;
            return;
        }
        break;

    case Qt::Key_2:
        switch (firstLetter) {
        case Qt::Key_A:
            isCorrect = cubeManager->checkUserChoice(A2);
            break;
        case Qt::Key_U:
            isCorrect = cubeManager->checkUserChoice(U2);
            break;
        case Qt::Key_J:
            isCorrect = cubeManager->checkUserChoice(J2);
            break;
        case Qt::Key_R:
            isCorrect = cubeManager->checkUserChoice(R2);
            break;
        case Qt::Key_N:
            isCorrect = cubeManager->checkUserChoice(N2);
            break;
        case Qt::Key_G:
            isCorrect = cubeManager->checkUserChoice(G2);
            break;
        default:
            firstLetter = Qt::Key_No;
            return;
        }
        break;

    case Qt::Key_3:
        if (firstLetter == Qt::Key_G) isCorrect = cubeManager->checkUserChoice(G3);
        else {
            firstLetter = Qt::Key_No;
            return;
        }
        break;

    case Qt::Key_4:
        if (firstLetter == Qt::Key_G) isCorrect = cubeManager->checkUserChoice(G4);
        else {
            firstLetter = Qt::Key_No;
            return;
        }
        break;

    default:
        firstLetter = Qt::Key_No;
        return;
    }

    setResults(isCorrect, lastPLLCase);
}


void MainWindow::updateTimer() {
    ui->timerLabel->setText(cubeManager->getTimerValueString());
}

void MainWindow::on_pushButton_clicked()
{

}
