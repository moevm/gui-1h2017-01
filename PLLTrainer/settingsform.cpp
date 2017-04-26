#include "settingsform.h"
#include "ui_settingsform.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <cubecolors.h>
#include <settings.h>
SettingsForm::SettingsForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsForm)
{
    ui->setupUi(this);
}

SettingsForm::~SettingsForm()
{
    delete ui;
}

int SettingsForm::get_attempts()
{
    return ui->attemptsCount->value();
}

int SettingsForm::get_color()
{
    return ui->color->currentIndex();
}

bool SettingsForm::isRandomMode()
{
    return ui->randomMode->isChecked();
}

bool SettingsForm::isHardMode()
{
    return ui->easyMode->isChecked();
}

void SettingsForm::set_attempts(int count)
{
    ui->attemptsCount->setValue(count);
}

void SettingsForm::set_color(CubeColor text)
{
    ui->color->setCurrentIndex((int) text);
}

void SettingsForm::setRandomMode(bool value)
{
    ui->randomMode->setChecked(value);
}

void SettingsForm::setHardMode(bool value)
{
    ui->easyMode->setChecked(value);
}

void SettingsForm::updateUI()
{

    QFile fileOut("settings.txt");

    fileOut.open(QIODevice::ReadWrite);
    QString str = fileOut.readLine();
    QStringList values ;
    values = str.split(" ");
    QTextStream out(stdout);
    foreach(QString x, values)
        out << x << endl;
    fileOut.close();

    int countAttempts = values[1].toInt();
    int intColor = values[0].toInt();
    int intRandomMode = values[3].toInt();
    bool randomMode = bool(intRandomMode);
    int intHardMode = values[2].toInt();
    bool hardMode = bool(intHardMode);
    CubeColor color = (CubeColor) intColor;

    set_attempts(countAttempts);
    set_color(color);
    setRandomMode(randomMode);
    setHardMode(hardMode);
}

void SettingsForm::on_buttonBox_accepted()
{
    QFile fileOut("settings.txt");
    fileOut.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
    QTextStream writeStream(&fileOut);

    int color = get_color();
    int attempts = get_attempts();
    bool hardMode = isHardMode();
    bool randomMode = isRandomMode();

    writeStream << QString::number(color) + " " + QString::number(attempts) + " " + QString::number(hardMode) + " " + QString::number(randomMode);
    fileOut.flush();
    fileOut.close();

    Settings::Instance().attempts = attempts;
    Settings::Instance().downColor = (CubeColor) color;
    Settings::Instance().doSetupMove = hardMode;
    Settings::Instance().isMulticolor = randomMode;
}

void SettingsForm::on_buttonBox_rejected()
{
    updateUI();
}
