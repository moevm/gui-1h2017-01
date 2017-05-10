#include "settingsform.h"
#include "ui_settingsform.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <cubecolors.h>
#include <QLocale>
#include <settings.h>
#include <QDebug>
SettingsForm::SettingsForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsForm)
{

    ui->setupUi(this);
    updateUI();
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowCloseButtonHint);
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

int SettingsForm::getLanguage()
{
    return ui->languageBox->currentIndex();
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

void SettingsForm::setLanguage(int index)
{
    ui->languageBox->setCurrentIndex(index);
}

void SettingsForm::updateUI()
{
    QFile fileOut(settingsFile);
    int countAttempts, intColor, intRandomMode, intHardMode, intLanguage;
    bool randomMode, hardMode;

    if(fileOut.exists()){
        fileOut.open(QIODevice::ReadWrite);
        QString str = fileOut.readLine();
        QStringList values ;
        values = str.split(" ");
        fileOut.close();


        CubeColor color;
        Language language;

        try{
            countAttempts = values[1].toInt();
            intColor = values[0].toInt();
            intRandomMode = values[3].toInt();
            randomMode = bool(intRandomMode);
            intHardMode = values[2].toInt();
            hardMode = bool(intHardMode);
            color = (CubeColor) intColor;
            intLanguage = values[4].toInt();
            language = (Language) intLanguage;

        }
        catch(...){
            countAttempts = 20;
            color = WHITE;
            randomMode = hardMode = false;
            language = Russian;
        }

        set_attempts(countAttempts);
        set_color(color);
        setRandomMode(randomMode);
        setHardMode(hardMode);
        setLanguage(intLanguage);


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

    Settings::Instance().attempts = get_attempts();
    Settings::Instance().downColor = (CubeColor) get_color();
    Settings::Instance().doSetupMove = isHardMode();
    Settings::Instance().isMulticolor = isRandomMode();
    Settings::Instance().language = (Language) getLanguage();

    setWindowTitle(Settings::Instance().getStr("sets"));
    ui->buttonBox->buttons().at(0)->setText(Settings::Instance().getStr("save"));
    ui->buttonBox->buttons().at(1)->setText(Settings::Instance().getStr("cancel"));
    ui->attemptsLabel->setText(Settings::Instance().getStr("count of attempts"));
    ui->colorLabel->setText(Settings::Instance().getStr("down color"));
    ui->hardLabel->setText(Settings::Instance().getStr("hard mode"));
    ui->langLabel->setText(Settings::Instance().getStr("lang"));
    ui->randomLabel->setText(Settings::Instance().getStr("multicolor mode"));

    ui->color->clear();
    QStringList colors;
    colors.append(Settings::Instance().getStr("white"));
    colors.append(Settings::Instance().getStr("yellow"));
    colors.append(Settings::Instance().getStr("green"));
    colors.append(Settings::Instance().getStr("blue"));
    colors.append(Settings::Instance().getStr("red"));
    colors.append(Settings::Instance().getStr("orange"));
    ui->color->addItems(colors);
    ui->color->setCurrentIndex(intColor);
    ui->languageBox->clear();

    QStringList langs;
    langs.append(Settings::Instance().getStr("lang_ru"));
    langs.append(Settings::Instance().getStr("lang_en"));
    langs.append(Settings::Instance().getStr("lang_de"));
    ui->languageBox->addItems(langs);
    ui->languageBox->setCurrentIndex(intLanguage);

    ui->buttonBox->buttons().at(0)->setText(Settings::Instance().getStr("save"));
    ui->buttonBox->buttons().at(1)->setText(Settings::Instance().getStr("cancel"));
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
    int language = getLanguage();

    writeStream << QString::number(color) + " " + QString::number(attempts) +
                   " " + QString::number(hardMode) + " " + QString::number(randomMode) + " " + QString::number(language);
    fileOut.flush();
    fileOut.close();

    Settings::Instance().attempts = attempts;
    Settings::Instance().downColor = (CubeColor) color;
    Settings::Instance().doSetupMove = hardMode;
    Settings::Instance().isMulticolor = randomMode;
    Settings::Instance().language = (Language) language;

    updateUI();


}

void SettingsForm::on_buttonBox_rejected()
{
    updateUI();
}
