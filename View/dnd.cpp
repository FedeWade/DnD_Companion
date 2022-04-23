#include "dnd.h"

DND::DND(QWidget *parent, Modello *modello) : QWidget(parent), Model(modello)
{
    QHBoxLayout *mainlayout = new QHBoxLayout();
    QHBoxLayout *horizontallayout1 = new QHBoxLayout();
    QHBoxLayout *horizontallayout2 = new QHBoxLayout();
    QVBoxLayout *stskillslayout = new QVBoxLayout();
    QVBoxLayout *infopvlayout = new QVBoxLayout();
    QVBoxLayout *infospells = new QVBoxLayout();
    QVBoxLayout *rightsidelayout = new QVBoxLayout();

    mainlayout->setContentsMargins(0, 0, 0, 0);

    Stats = new StatsBox(this, Model);
    Skills = new SkillsBox(this, Model);
    SavingThrows = new SavingThrowsBox(this, Model);
    CombatInfo = new CombatInfoBox(this, Model);
    Health = new HealthBox(this, Model);
    Equipment = new EquipmentBox(this, Model);
    Spells = new SpellsBox(this, Model);
    Slots = new SpellsSlotsBox(this, Model);
    Info = new BaseInfo(this, Model);
    PGSelection = new PGSelectionBox(this, Model);
    Description = new DescriptionBox(this, Model);

    horizontallayout1->addWidget(Stats);
    stskillslayout->addWidget(SavingThrows);
    stskillslayout->addWidget(Skills);
    horizontallayout1->addLayout(stskillslayout);

    rightsidelayout->addWidget(PGSelection);

    infopvlayout->addWidget(CombatInfo);
    infopvlayout->addWidget(Health);
    infopvlayout->addWidget(Equipment);
    horizontallayout2->addLayout(infopvlayout);

    infospells->addWidget(Info);
    infospells->addWidget(Spells);
    infospells->addWidget(Slots);
    infospells->addWidget(Description);
    horizontallayout2->addLayout(infospells);

    rightsidelayout->addLayout(horizontallayout2);

    mainlayout->addLayout(horizontallayout1);
    mainlayout->addLayout(rightsidelayout);
    setLayout(mainlayout);

    update();
    setObjectName("app");

    mainlayout->setStretchFactor(horizontallayout1, 2);
    mainlayout->setStretchFactor(rightsidelayout, 4);
    stskillslayout->setStretchFactor(SavingThrows, 3);
    stskillslayout->setStretchFactor(Skills, 7);
    infospells->setStretchFactor(Info, 2);
    infospells->setStretchFactor(Spells, 2);
    infospells->setStretchFactor(Slots, 3);
    infospells->setStretchFactor(Description, 3);

    setWindowIcon(QIcon(":/Resources/logonosfondons.png"));
    setWindowTitle("D&D Compagno");

    setStyleSheet(
        "QGroupBox {font-size:22px; background-color: rgb(50,50,50); color:white; border: 2px "
        "solid #15DB95; border-radius:5px; margin-top:10px;}"
        "QGroupBox::title { subcontrol-position: top center; padding: 3px 0px 3px 0px; "
        "margin-top:-22px; margin-bottom: 5px;}"
        "QLabel {font-size:18px; color:white; }"
        "#app {background-color: #2e4a62;}"
        "QSpinBox, QDoubleSpinBox, QTextEdit, QLineEdit {background-color: rgb(200,200,200); } "
        "QSpinBox::hover, QDoubleSpinBox::hover, QTextEdit::hover, QLineEdit::hover "
        "{background-color: white; } "
        "QTextEdit { font-size: 18px; } "
        "QDialog {background-color: rgb(50,50,50); color:white; border: 2px solid #15DB95;} ");

    connect(Stats, SIGNAL(valuesChanged()), this, SLOT(update()));
    connect(CombatInfo, SIGNAL(valuesChanged()), this, SLOT(update()));
    connect(Info, SIGNAL(valuesChanged()), this, SLOT(update()));
    connect(PGSelection, SIGNAL(pgChanged()), this, SLOT(update()));
}

DND::~DND() {}

void DND::update()
{
    PGSelection->update();
    Stats->update();
    Skills->update();
    SavingThrows->update();
    CombatInfo->update();
    Health->update();
    Equipment->update();
    Info->update();

    Incantatore *PG = dynamic_cast<Incantatore *>(
        Model->getSelectedPG()); //se usa incantesimi mostro i riquadri dedicati
    if (PG) {
        Description->setVisible(false);
        Spells->setVisible(true);
        Slots->setVisible(true);
        Spells->update();
        Slots->update();
    } else {
        Spells->setVisible(false);
        Slots->setVisible(false);
        Description->setVisible(true);
        Description->update();
    }
}
