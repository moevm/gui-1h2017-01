#ifndef ABOUTPLLFORM_H
#define ABOUTPLLFORM_H

#include <QWidget>
#include "pllcases.h"

namespace Ui {
class AboutPLLForm;
}

class AboutPLLForm : public QWidget
{
    Q_OBJECT

public:
    explicit AboutPLLForm(QWidget *parent = 0);
    ~AboutPLLForm();

    void showPLLCase(PLLCase pllcase);

private:
    Ui::AboutPLLForm *ui;
};

#endif // ABOUTPLLFORM_H
