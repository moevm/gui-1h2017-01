#include "settingsform.h"
#include "ui_settingsform.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <cubecolors.h>

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
    switch (ui->color->currentIndex()) {
        case 0: return 0;
        case 1: return 1;
        case 2: return 2;
        case 3: return 3;
        case 4: return 4;
        case 5: return 5;
    }
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
    switch(text){
    std::cout<< text;
    case GREEN:
        ui->color->setCurrentIndex(4);
        break;
    case RED:
        ui->color->setCurrentIndex(2);
        break;
    case BLUE:
        ui->color->setCurrentIndex(5);
        break;
    case WHITE:
        ui->color->setCurrentIndex(1);
        break;
    case YELLOW:
        ui->color->setCurrentIndex(0);
        break;
    case ORANGE:
        ui->color->setCurrentIndex(3);
        break;
    }

}

void SettingsForm::setRandomMode(bool value)
{
    ui->randomMode->setChecked(value);
}

void SettingsForm::setHardMode(bool value)
{
    ui->easyMode->setChecked(value);
}

//void SettingsForm::on_buttonBox_clicked(QAbstractButton *button)
//{

//}

void SettingsForm::on_buttonBox_accepted()
{
    QFile fileOut("settings.txt");
    fileOut.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
    QTextStream writeStream(&fileOut);
    int color = get_color();
    int attempts = get_attempts();
    bool hardMode = isHardMode();
    bool randomMode = isRandomMode();
    QString stringAttempts = QString::number(attempts);
    writeStream << QString::number(color) + " " + stringAttempts + " " + QString::number(hardMode) + " " + QString::number(randomMode);
    fileOut.flush();
    fileOut.close();
}
