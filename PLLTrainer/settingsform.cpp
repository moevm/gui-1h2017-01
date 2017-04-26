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
    QFile fileOut(settingsFile);

    if(fileOut.exists()){
        fileOut.open(QIODevice::ReadWrite);
        QString str = fileOut.readLine();
        QStringList values ;
        values = str.split(" ");
        fileOut.close();

        int countAttempts, intColor, intRandomMode, intHardMode;
        bool randomMode, hardMode;
        CubeColor color;

        try{
            countAttempts = values[1].toInt();
            intColor = values[0].toInt();
            intRandomMode = values[3].toInt();
            randomMode = bool(intRandomMode);
            intHardMode = values[2].toInt();
            hardMode = bool(intHardMode);
            color = (CubeColor) intColor;
        }
        catch(...){
            countAttempts = 20;
            color = WHITE;
            randomMode = hardMode = false;
        }

        set_attempts(countAttempts);
        set_color(color);
        setRandomMode(randomMode);
        setHardMode(hardMode);
    }
    else{
        QFile file(settingsFile);
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            stream << "0 20 0 0";

            set_attempts(20);
            set_color(WHITE);
            setRandomMode(0);
            setHardMode(0);
        }
        file.close();
    }
}

void SettingsForm::on_buttonBox_accepted()
{
    QFile fileOut(settingsFile);
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
