#include "aboutpllform.h"
#include "ui_aboutpllform.h"
#include <QTime>

AboutPLLForm::AboutPLLForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutPLLForm)
{
    ui->setupUi(this);
}

AboutPLLForm::~AboutPLLForm()
{
    delete ui;
}

void AboutPLLForm::showPLLCase(PLLCase pllcase)
{
    int ybefore = qrand();

    ui->cube0->cube->scrabmle(pllcase, 0, ybefore % 4);
    ui->cube1->cube->scrabmle(pllcase, 1, (ybefore + 1) % 4);
    ui->cube2->cube->scrabmle(pllcase, 2, (ybefore + 2) % 4);
    ui->cube3->cube->scrabmle(pllcase, 3, (ybefore + 3) % 4);

    ui->fourCasesOfOnePLL->pllcase = pllcase;

    show();
    activateWindow();
}
