#include "combatinfobox.h"

CombatInfoBox::CombatInfoBox(QWidget *parent, Modello *model) : QWidget(parent), Model(model)
{
    QVBoxLayout *mainlayout = new QVBoxLayout();
    QHBoxLayout *ispirazionel = new QHBoxLayout();
    QHBoxLayout *competenzal = new QHBoxLayout();
    QHBoxLayout *infol = new QHBoxLayout();

    Save = new QPushButton(this);
    Edit = new QPushButton(this);

    //ispirazione
    Ispirazione = new QSpinBox(this);
    Ispirazione->setMaximum(9);
    QLabel *labelispirazione = new QLabel("Ispirazione", this);
    labelispirazione->setObjectName("ispiral");
    ispirazionel->addWidget(Ispirazione);
    ispirazionel->addWidget(labelispirazione);

    //competenza
    Competenza = new QSpinBox(this);
    Competenza->setMaximum(9);
    QLabel *labelcompetenza = new QLabel("Competenza", this);
    labelcompetenza->setObjectName("competel");
    competenzal->addWidget(Competenza);
    competenzal->addWidget(labelcompetenza);

    QHBoxLayout *compispiralayout = new QHBoxLayout();
    compispiralayout->addLayout(competenzal);
    compispiralayout->addLayout(ispirazionel);
    compispiralayout->addWidget(Edit);
    compispiralayout->addWidget(Save);
    mainlayout->addLayout(compispiralayout);

    //CA
    CA = new QSpinBox(this);
    CA->setMaximum(40);
    QGroupBox *groupca = new QGroupBox("CA", this);
    QHBoxLayout *groupcal = new QHBoxLayout();
    groupcal->addWidget(CA);
    groupca->setLayout(groupcal);
    infol->addWidget(groupca);

    //iniziativa
    Iniziativa = new QSpinBox(this);
    Iniziativa->setMaximum(10);
    QGroupBox *groupiniziativa = new QGroupBox("Iniziativa", this);
    QHBoxLayout *groupiniziatival = new QHBoxLayout();
    groupiniziatival->addWidget(Iniziativa);
    groupiniziativa->setLayout(groupiniziatival);
    infol->addWidget(groupiniziativa);

    //Velocita
    Velocita = new QDoubleSpinBox(this);
    Velocita->setMaximum(30);
    Velocita->setDecimals(1);
    QGroupBox *groupvelocita = new QGroupBox("Velocita", this);
    QHBoxLayout *groupvelocital = new QHBoxLayout();
    groupvelocital->addWidget(Velocita);
    groupvelocita->setLayout(groupvelocital);
    infol->addWidget(groupvelocita);

    mainlayout->addLayout(infol);
    setLayout(mainlayout);
    setStyle();

    //---Style---
    labelispirazione->setFixedWidth(140);
    ispirazionel->setAlignment(Qt::AlignCenter);
    labelcompetenza->setFixedWidth(140);
    competenzal->setAlignment(Qt::AlignCenter);
    compispiralayout->setContentsMargins(20, 0, 0, 20);
    compispiralayout->setSpacing(10);
    groupca->setAlignment(Qt::AlignCenter);
    groupca->setFixedWidth(120);
    groupcal->setContentsMargins(20, 18, 20, 10);
    groupiniziativa->setAlignment(Qt::AlignCenter);
    groupiniziativa->setFixedWidth(120);
    groupiniziatival->setContentsMargins(20, 18, 20, 10);
    groupvelocita->setAlignment(Qt::AlignCenter);
    groupvelocita->setFixedWidth(120);
    //---End Style---

    connect(Edit, SIGNAL(clicked()), this, SLOT(editClicked()));
    connect(Save, SIGNAL(clicked()), this, SLOT(saveClicked()));
}

void CombatInfoBox::update()
{
    Model->getSelectedPG() ? Edit->setEnabled(true) : Edit->setEnabled(false);

    if (!Model->getSelectedPG()) {
        Ispirazione->setValue(0);
        Competenza->setValue(0);
        CA->setValue(0);
        Iniziativa->setValue(0);
        Velocita->setValue(0);
    } else {
        Ispirazione->setValue((Model->getSelectedPG())->getIspirazione());
        Competenza->setValue((Model->getSelectedPG())->getBonusCompetenza());
        CA->setValue((Model->getSelectedPG())->getClasseArmatura());
        Iniziativa->setValue((Model->getSelectedPG())->getBonusIniziativa());
        Velocita->setValue((Model->getSelectedPG())->getVelocita());
    }
}

void CombatInfoBox::editClicked()
{
    Edit->setVisible(false);
    Save->setVisible(true);

    Ispirazione->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
    Ispirazione->setReadOnly(false);
    Competenza->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
    Competenza->setReadOnly(false);
    CA->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
    CA->setReadOnly(false);
    Iniziativa->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
    Iniziativa->setReadOnly(false);
    Velocita->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
    Velocita->setReadOnly(false);
}

void CombatInfoBox::saveClicked()
{
    Save->setVisible(false);
    Edit->setVisible(true);

    Ispirazione->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Ispirazione->setReadOnly(true);
    Competenza->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Competenza->setReadOnly(true);
    CA->setButtonSymbols(QAbstractSpinBox::NoButtons);
    CA->setReadOnly(true);
    Iniziativa->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Iniziativa->setReadOnly(true);
    Velocita->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Velocita->setReadOnly(true);

    (Model->getSelectedPG())->setIspirazione(Ispirazione->value());
    (Model->getSelectedPG())->setBonusCompetenza(Competenza->value());
    (Model->getSelectedPG())->setClasseArmatura(CA->value());
    (Model->getSelectedPG())->setBonusIniziativa(Iniziativa->value());
    (Model->getSelectedPG())->setVelocita(Velocita->value());
    emit(valuesChanged());
}

void CombatInfoBox::setStyle()
{
    //save edit
    Edit->setIcon(QIcon(QPixmap(":/Resources/Edit.svg")));
    Save->setIcon(QIcon(QPixmap(":/Resources/Save.svg")));
    Edit->setFixedSize(32, 32);
    Save->setFixedSize(32, 32);
    Save->setVisible(false);

    //ispirazione
    Ispirazione->setObjectName("ispira");
    Ispirazione->setReadOnly(true);
    Ispirazione->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Ispirazione->setAlignment(Qt::AlignCenter);
    Ispirazione->setFixedSize(40, 40);

    //competenza
    Competenza->setObjectName("compete");
    Competenza->setReadOnly(true);
    Competenza->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Competenza->setAlignment(Qt::AlignCenter);
    Competenza->setFixedSize(40, 40);

    //CA
    CA->setReadOnly(true);
    CA->setButtonSymbols(QAbstractSpinBox::NoButtons);
    CA->setAlignment(Qt::AlignCenter);
    CA->setFixedSize(80, 70);
    CA->setObjectName("ca");

    //iniziativa
    Iniziativa->setReadOnly(true);
    Iniziativa->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Iniziativa->setAlignment(Qt::AlignCenter);
    Iniziativa->setFixedSize(80, 70);
    Iniziativa->setObjectName("iniz");

    //velocita
    Velocita->setReadOnly(true);
    Velocita->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Velocita->setAlignment(Qt::AlignCenter);
    Velocita->setFixedSize(90, 60);
    Velocita->setObjectName("velo");

    setStyleSheet("#ca, #iniz {font-size:48px;}"
                  "#velo {font-size:34px;}"
                  "#ispira, #compete {font-size:28px;}"
                  "#competel, #ispiral {font-size:20px;}");
}
