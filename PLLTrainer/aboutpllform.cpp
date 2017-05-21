#include "aboutpllform.h"
#include "ui_aboutpllform.h"

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
    this->pllcase = pllcase;

    int ybefore = qrand();
    int uafter = qrand() % 4;

    ui->cube0->cube->scrabmle(pllcase, 0, ybefore % 4, uafter);
    ui->cube1->cube->scrabmle(pllcase, 1, (ybefore + 1) % 4, uafter);
    ui->cube2->cube->scrabmle(pllcase, 2, (ybefore + 2) % 4, uafter);
    ui->cube3->cube->scrabmle(pllcase, 3, (ybefore + 3) % 4, uafter);

    ui->fourCasesOfOnePLL->pllcase = pllcase;

    this->setWindowTitle(Cube::getPLLName(pllcase));

    setText();

    show();
    activateWindow();
}

QList<QString> AboutPLLForm::getStrAlgs(PLLCase pllcase)
{

    QList<QString> res;

    switch (pllcase) {
    case A1:
        res.append("x R' U R' D2 R U' R' D2 R2 x'");
        res.append("x' R2 D2 R' U' R D2 R' U R' x");
        res.append("z F2 R U2 R' U2 F2 L' U2 L U2 z'");
        res.append("x L2 D2 L' U' L D2 L' U L' x'");
        break;
    case A2:
        res.append("x R2 D2 R U R' D2 R U' R x'");
        res.append("x' R U' R D2 R' U R D2 R2 x");
        res.append("z U2 L' U2 L F2 U2 R U2 R' F2 z'");
        res.append("x L U' L D2 L' U L D2 L2 x'");
        break;
    case E:
        res.append("x' R U' R' D R U R' D' R U R' D R U' R' D' x");
        res.append("R2 U R' U' y R U R' U' R U R' U' R U R' y' R U' R2'");
        res.append("x' R U' R' D R U R' D' R U R' D R U' R' D' x");
        res.append("R2 U R' U' y R U R' U' R U R' U' R U R' y' R U' R2'");
        break;
    case Z:
        res.append("M' U' M2' U' M2' U' M' U2 M2' U");
        res.append("M2' U' M2' U' M' U2' M2' U2' M' U2");
        res.append("M' U' M2' U' M2' U' M' U2 M2' U");
        res.append("M2' U' M2' U' M' U2' M2' U2' M' U2");
        break;
    case H:
        res.append("M2' U' M2' U2' M2' U' M2'");
        res.append("M2' U' M2' U2' M2' U' M2'");
        res.append("M2' U' M2' U2' M2' U' M2'");
        res.append("M2' U' M2' U2' M2' U' M2'");
        break;
    case U1:
        res.append("R U' R U R U R U' R' U' R2");
        res.append("M2 u' M u2 M u' M2");
        res.append("R2 U' R' U' R U R U R U' R");
        res.append("R2 U' F B' R2 F' B U' R2");
        break;
    case U2:
        res.append("R2 U R U R' U' R' U' R' U R'");
        res.append("M2 u M' u2 M' u M2");
        res.append("R' U R' U' R' U' R' U R U R2");
        res.append("f' L' U' L U f F R U R' U' F'");
        break;
    case J1:
        res.append("R U R' F' R U R' U' R' F R2 U' R' U'");
        res.append("R U' L U2 R' U R U2 L' R' U'");
        res.append("R L U2 L' U' L U2 R' U L' U'");
        res.append("L U' R U2 L' U L U2 R' L' U'");
        break;
    case J2:
        res.append("R' U2 R U R' U2 z U R' D R U' z'");
        res.append("L' U R' U2 L U' L' U2 R L");
        res.append("L' U2 L U L' U2 R U' L U R'");
        res.append("R' U L' U2 R U' R' U2 R L");
        break;
    case R1:
        res.append("R' U2 R U2 R' F R U R' U' R' F' R2' U'");
        res.append("R2 F R U R U' R' F' R U2 R' U2 R");
        res.append("R U R' U2 R' U2 L R2 U' R' U R' L' U2 R");
        res.append("r' L' U r U L U' r' U' r U2 L' U2 L");
        break;
    case R2:
        res.append("L U2 L' U2 L F' L' U' L U L F L2");
        res.append("R2 B' R' U' R' U R B R' U2 R U2 R'");
        res.append("R U2 R' U2 R B' R' U' R U R B R2 U");
        res.append("L2 F' L' U' L' U L F L' U2 L U2 L'");
        break;
    case T:
        res.append("R U R' U' R' F R2 U' R' U' R U R' F'");
        res.append("x r' U r' d2 r U' r' d2 r2 x' U' M' U2 M");
        res.append("L' U' L U L F' L2 U L U L' U' L F");
        res.append("L U' r U2 l' U l U2 x r2' U M U2 M'");
        break;
    case Y:
        res.append("F R U' R' U' R U R' F' R U R' U' R' F R F'");
        res.append("F' L' U L U L' U' L F L' U' L U L F' L' F");
        res.append("z U2 R' U2 R' U2 R B R B' U2 B R' B' z'");
        res.append("R2 u R2' U R2 D' R' U' R F2' R' U R");
        break;
    case F:
        res.append("R' U' F' R U R' U' R' F R2 U' R' U' R U R' U R");
        res.append("R U' R' U R2 y R U R' U' x U' R' U R U2 x'");
        res.append("L U F L' U' L U L F' L2 U L U L' U' L U' L'");
        res.append("R' U R U' R2 F' U' F U R F R' F' R2 U'");
        break;
    case V:
        res.append("R' U R' d' R' F' R2 U' R' U R' F R F");
        res.append("L' U R U' L U L' U R' U' L U2 R U2 R'");
        res.append("R U' L' U R' U' R U' L U R' U2 L' U2 L");
        res.append("R' U L U' R U R' U L' U' R U2 L U2 L'");
        break;
    case N1:
        res.append("R U R' U R U R' F' R U R' U' R' F R2 U' R' U2 R U' R'");
        res.append("z R' U R' D R2 U' R D' U R' D R2 U' R D' z'");
        res.append("R U R' U R U R' F' R U R' U' R' F R2 U' R' U2 R U' R'");
        res.append("z R' U R' D R2 U' R D' U R' D R2 U' R D' z'");
        break;
    case N2:
        res.append("R' U R U' R' F' U' F R U R' F R' F' R U' R");
        res.append("z' L U' L D' L2 U L' D U' L D' L2 U L' D z");
        res.append("R' U R U' R' F' U' F R U R' F R' F' R U' R");
        res.append("z R' U R' D R2 U' R D' U R' D R2 U' R D' z'");
        break;
    case G1:
        res.append("R2' F2 R U2 R U2 R' F R U R' U' R' F R2");
        res.append("L' U' L U L U' F' L' U' L' U L F U' L U2 L'");
        res.append("R2' u' R U' R U R' u R2 y R U' R'");
        res.append("F2' D' L U' L U L' D F2 R U' R'");
        break;
    case G2:
        res.append("R' F' R F' U' L' U F R' F' L F2 R");
        res.append("U f R f' R2 u' R U' R' U R' u R2");
        res.append("f R f' R2 u' R U' R' U R' u R2");
        res.append("R U R' y' R2 u' R U' R' U R' u R2");
        break;
    case G3:
        res.append("R2' u R' U R' U' R u' R2 y' R' U R");
        res.append("F2' D R' U R' U' R D' F2 L' U L");
        res.append("U' F2' D R' U R' U' R D' F2 L' U L");
        res.append("R L U2 R' L' y' R' U L' U2 R U' L");
        break;
    case G4:
        res.append("F' U' F R2 u R' U R U' R u' R2'");
        res.append("L' U' L y' R2' u R' U R U' R u' R2");
        res.append("R' U L' U2 R U' L y R L U2 L' R'");
        res.append("R' d' F R2 u R' U R U' R u' R2");
        break;
    default:
        res.append("No algorithm");
        res.append("No algorithm");
        res.append("No algorithm");
        res.append("No algorithm");
        break;
    }

    return res;
}

void AboutPLLForm::setText()
{
    QList<QString> strAlgs = getStrAlgs(pllcase);

    QString algs = Settings::Instance().getStr("algs");
    QString forStr = Settings::Instance().getStr("for");
    QString notation = Settings::Instance().getStr("notation");

    algs += "\n\n" + forStr + " 0°:\n" + strAlgs.at(0);
    algs += "\n\n" + forStr + " 90°:\n" + strAlgs.at(1);
    algs += "\n\n" + forStr + " 180°:\n" + strAlgs.at(2);
    algs += "\n\n" + forStr + " 270°:\n" + strAlgs.at(3);

    algs += "\n\n" + notation + " - speedsolving.com/wiki/index.php/3x3x3_notation";

    ui->text->setPlainText(algs);

}
