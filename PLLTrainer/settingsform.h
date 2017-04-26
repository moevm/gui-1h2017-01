#ifndef SETTINGSFORM_H
#define SETTINGSFORM_H

#include <QDialog>
#include <string>
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

    void set_attempts(int count);
    void set_color(CubeColor text);
    void setRandomMode(bool value);
    void setHardMode(bool value);

    void updateUI();


private slots:

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::SettingsForm *ui;

};

#endif // SETTINGSFORM_H
