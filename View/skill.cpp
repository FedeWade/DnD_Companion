#include "skill.h"

Skill::Skill(QWidget *parent, Modello *modello, const std::string &name)
    : QWidget(parent), Name(name), Model(modello)
{
    QHBoxLayout *mainlayout = new QHBoxLayout();
    mainlayout->setSpacing(30);
    mainlayout->setContentsMargins(10, 1, 1, 0);

    Check = new QCheckBox(this);
    Check->setVisible(false);

    Value = new QLabel(this);
    QLabel *SkillName = new QLabel(QString(QString::fromStdString(Name)), this);

    mainlayout->addWidget(Check, 0, Qt::AlignRight);
    mainlayout->addWidget(Value, 0, Qt::AlignRight);
    mainlayout->addWidget(SkillName, 0, Qt::AlignLeft);

    setLayout(mainlayout);

    SkillName->setFixedWidth(153);
    Value->setAlignment(Qt::AlignRight);
    Value->setFixedWidth(25);
    Check->setFixedWidth(25);
}

void Skill::update()
{
    if (!Model->getSelectedPG()) {
        Check->setChecked(false);
        Value->setText("0");
    } else {
        try {
            Check->setChecked((Model->getSelectedPG())->isCompetenteAbilita(Name));
            Value->setText(QString::number((Model->getSelectedPG())->getValoreAbilita(Name)));
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

void Skill::makeCheckable()
{
    Value->setVisible(false);
    Check->setVisible(true);
}

void Skill::makeUncheckable()
{
    Check->setVisible(false);
    Value->setVisible(true);
}
