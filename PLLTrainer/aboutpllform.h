#ifndef ABOUTPLLFORM_H
#define ABOUTPLLFORM_H

#include <QWidget>
#include <QList>
#include <QString>
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
    QList<QString> getStrAlgs(PLLCase pllcase);
    PLLCase pllcase;
    void setText();

private:
    Ui::AboutPLLForm *ui;
};

#endif // ABOUTPLLFORM_H
