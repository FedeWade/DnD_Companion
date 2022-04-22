#include "savingthrow.h"

SavingThrow::SavingThrow(QWidget *parent, Modello *modello, const std::string &name)
    : Skill(parent, modello, name)
{
    setStyleSheet("QLabel {margin:0px; padding:0px;} ");
}

void SavingThrow::update()
{
    if (!Model->getSelectedPG()) {
        Check->setChecked(false);
        Value->setText("0");
    } else {
        try {
            Check->setChecked((Model->getSelectedPG())->isCompetenteStatistica(Name));
            Value->setText(
                QString::number((Model->getSelectedPG())->getTiroSalvezzaStatistica(Name)));
        } catch (std::exception *exc) {
            ExceptionMessage *errmsg = new ExceptionMessage(this, exc->what());
            errmsg->show();
        }
    }

    if (Check->isChecked())
        Value->setStyleSheet("color:#15DB95;");
    else
        Value->setStyleSheet("color:white;");
}
