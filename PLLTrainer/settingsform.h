#ifndef SETTINGSFORM_H
#define SETTINGSFORM_H

#include <QDialog>
#include "cubecolors.h"

namespace Ui {
class SettingsForm;
}

class SettingsForm : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsForm(QWidget *parent = 0);
    ~SettingsForm();
    int get_attempts();
    int get_color();
    bool isRandomMode();
    bool isHardMode();
    int getLanguage();

    void set_attempts(int count);
    void set_color(CubeColor text);
    void setRandomMode(bool value);
    void setHardMode(bool value);
    void setLanguage(int index);

    void updateUI();

    const QString settingsFile = "settings.txt";


private slots:

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();


private:
    Ui::SettingsForm *ui;

};

#endif // SETTINGSFORM_H
