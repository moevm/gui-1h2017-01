#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cubemanager.h"
#include <QDebug>
#include "settingsform.h"
#include "settings.h"
#include <string>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowIcon(QIcon(QString("icon.ico")));
    ui->setupUi(this);
    qsrand(QTime::currentTime().msec());
    this->cubeManager = new CubeManager(ui->cubeWidget->cube);
    ui->stopButton->setDisabled(true);
    ui->pauseButton->setDisabled(true);
    ui->buttons->cubeManager = this->cubeManager;
    ui->buttons->mw = this;
    timer = new QTimer(this);
    settingsform = new SettingsForm(this);

    settingsform->updateUI();
    Settings::Instance().attempts = settingsform->get_attempts();
    Settings::Instance().downColor = (CubeColor) settingsform->get_color();
    Settings::Instance().doSetupMove = settingsform->isHardMode();
    Settings::Instance().isMulticolor = settingsform->isRandomMode();
    Settings::Instance().language = (Language) settingsform->getLanguage();

    connect(settingsform, SIGNAL(windowTitleChanged(QString)), this, SLOT(updateLanguage()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
    connect(ui->settingsButton, SIGNAL(clicked()), settingsform , SLOT(show()));

    updateLanguage();
    timer->start(UPDATE_TIME);

    ui->startButton->setFocusPolicy(Qt::NoFocus);
    ui->stopButton->setFocusPolicy(Qt::NoFocus);
    ui->settingsButton->setFocusPolicy(Qt::NoFocus);
    ui->pauseButton->setFocusPolicy(Qt::NoFocus);
    ui->statButton->setFocusPolicy(Qt::NoFocus);


}

void MainWindow::setResults(bool result, PLLCase lastPLLCase)
{
    QString succAttempts = QString::number(cubeManager->currentSuccessfulAttempts);
    QString attempts = QString::number(cubeManager->currentAttempts);

    if (result) {
        ui->resultLabel->setText(Settings::Instance().getStr("yes")+"! (" + succAttempts + "/" + attempts + ")");
        ui->resultLabel->setStyleSheet("QLabel { color : green; }");

        Settings::Instance().stat.addStats(lastPLLCase, true);
    }
    else {
        ui->resultLabel->setText(Settings::Instance().getStr("no")+ " " +
                                 pllNames[lastPLLCase] + " (" + succAttempts + "/" + attempts + ")");
        ui->resultLabel->setStyleSheet("QLabel { color : red; }");

        Settings::Instance().stat.addStats(lastPLLCase, false);
    }

    if (cubeManager->currentAttempts == Settings::Instance().attempts) {
        int rate = 100 * (float) cubeManager->currentSuccessfulAttempts / Settings::Instance().attempts;
        ui->totalResultLabel->setText(Settings::Instance().getStr("result")+": " + QString::number(rate) + "%");
        ui->settingsButton->setEnabled(true);
        ui->pauseButton->setDisabled(true);
    }

    update();
}

MainWindow::~MainWindow()
{
    ui->buttons->aboutPLLForm->close();
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    cubeManager->startSession();
    ui->resultLabel->clear();
    ui->totalResultLabel->clear();
    ui->stopButton->setEnabled(true);
    ui->settingsButton->setEnabled(false);
    ui->pauseButton->setEnabled(true);
    ui->cubeWidget->isHiding = false;
    ui->cubeWidget->update();
    ui->pauseButton->setText(Settings::Instance().getStr("pause"));
    update();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {

    if (!cubeManager->isSession) {
        switch (event->key()) {
        case Qt::Key_Space:
            on_startButton_clicked();
            break;
        default:
            break;
        }
        return;
    }

    PLLCase lastPLLCase = cubeManager->currentPLLCase;
    bool isCorrect = false;
    switch (event->key()) {

    case Qt::Key_Space:
        on_stopButton_clicked();
        break;

    case Qt::Key_Shift:
        on_pauseButton_clicked();
        return;
    }

    if (cubeManager->isPaused) return;

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
    cubeManager->updateTimer();
    ui->timerLabel->setText(cubeManager->getTimerValueString());
}

void MainWindow::on_stopButton_clicked()
{
    cubeManager->finishSession();
    int rate;
    if(cubeManager->currentAttempts == 0){
        rate = 0;
    }
    else{
        rate = 100 * (float) cubeManager->currentSuccessfulAttempts / cubeManager->currentAttempts;
    }
    ui->totalResultLabel->setText(Settings::Instance().getStr("result") + ": " + QString::number(rate) + "%");
    ui->pauseButton->setText(Settings::Instance().getStr("pause"));
    ui->stopButton->setDisabled(true);
    ui->pauseButton->setDisabled(true);
    ui->settingsButton->setEnabled(true);
    ui->cubeWidget->isHiding = false;
    ui->cubeWidget->update();
}

void MainWindow::updateLanguage() {
    ui->startButton->setText(Settings::Instance().getStr("start"));
    ui->stopButton->setText(Settings::Instance().getStr("stop"));
    ui->settingsButton->setText(Settings::Instance().getStr("sets"));
    ui->pauseButton->setText(Settings::Instance().getStr("pause"));

    if(ui->buttons->showStat){
        ui->statButton->setText(Settings::Instance().getStr("hide stat"));
    }
    else{
        ui->statButton->setText(Settings::Instance().getStr("show stat"));
    }

    ui->totalResultLabel->setText("");
    ui->resultLabel->setText("");

    ui->buttons->aboutPLLForm->setText();
}

void MainWindow::on_pauseButton_clicked()
{
    if (!cubeManager->isSession) return;

    if (cubeManager->isPaused) {
        cubeManager->continueSession();
        ui->pauseButton->setText(Settings::Instance().getStr("pause"));
        ui->cubeWidget->isHiding = false;
        ui->cubeWidget->update();
    }
    else {
        cubeManager->pauseSession();
        ui->pauseButton->setText(Settings::Instance().getStr("continue"));
        ui->cubeWidget->isHiding = true;
        ui->cubeWidget->update();
    }
}

void MainWindow::on_statButton_clicked()
{
    ui->buttons->showStat = !ui->buttons->showStat;

    if(ui->buttons->showStat){
        ui->statButton->setText(Settings::Instance().getStr("hide stat"));
    }
    else{
        ui->statButton->setText(Settings::Instance().getStr("show stat"));
    }

    update();
}
