#include "healthbox.h"

HealthBox::HealthBox(QWidget *parent, Modello *modello) : QWidget(parent), Model(modello)
{
    QVBoxLayout *mainlayout = new QVBoxLayout();
    QGroupBox *group = new QGroupBox("Punti Vita", this);
    group->setAlignment(Qt::AlignCenter); //style
    QVBoxLayout *grouplayout = new QVBoxLayout();
    QHBoxLayout *hplayout = new QHBoxLayout();
    QHBoxLayout *buttonslayout = new QHBoxLayout();
    hplayout->setContentsMargins(0, 0, 0, 0);
    buttonslayout->setContentsMargins(0, 15, 0, 0);
    grouplayout->setContentsMargins(10, 0, 0, 10);

    Edit = new QPushButton(this);
    Save = new QPushButton(this);

    grouplayout->addWidget(Edit, 0, Qt::AlignRight);
    grouplayout->addWidget(Save, 0, Qt::AlignRight);

    CurrentHP = new QSpinBox(this);
    CurrentHP->setObjectName("currhp");
    CurrentHP->setMaximum(999);

    QLabel *slash = new QLabel("/", this);
    slash->setObjectName("slash");
    slash->setMaximumWidth(25);

    MaxHP = new QSpinBox(this);
    MaxHP->setObjectName("maxhp");
    MaxHP->setMaximum(999);

    hplayout->addWidget(CurrentHP, 1, Qt::AlignBottom);
    hplayout->addWidget(slash, 1, Qt::AlignBottom);
    hplayout->addWidget(MaxHP, 1, Qt::AlignBottom);

    Plus1 = new QPushButton("+1", this);
    Plus1->setObjectName("plus1");
    Plus5 = new QPushButton("+5", this);
    Plus5->setObjectName("plus5");
    Minus1 = new QPushButton("-1", this);
    Minus1->setObjectName("minus1");
    Minus5 = new QPushButton("-5", this);
    Minus5->setObjectName("minus5");

    buttonslayout->addWidget(Minus5);
    buttonslayout->addWidget(Minus1);
    buttonslayout->addWidget(Plus1);
    buttonslayout->addWidget(Plus5);

    //parte inferiore
    QHBoxLayout *lowerlayout = new QHBoxLayout();
    lowerlayout->setContentsMargins(0, 10, 0, 0);

    //dado vita
    QGroupBox *hitdicegroup = new QGroupBox("Dado vita", this);
    hitdicegroup->setObjectName("hitdicegroup");
    hitdicegroup->setAlignment(Qt::AlignCenter);
    hitdicegroup->setFixedWidth(90);
    QVBoxLayout *hdgrouplayout = new QVBoxLayout();

    HitDice = new QSpinBox(this);
    HitDice->setObjectName("hitdice");
    HitDice->setAlignment(Qt::AlignHCenter);
    HitDice->setButtonSymbols(QAbstractSpinBox::NoButtons);
    HitDice->setReadOnly(true);

    hdgrouplayout->addWidget(HitDice, 0, Qt::AlignCenter);
    hitdicegroup->setLayout(hdgrouplayout);
    lowerlayout->addWidget(hitdicegroup);

    //tscontro morte
    QGroupBox *deathgroup = new QGroupBox("TS contro morte", this);
    deathgroup->setObjectName("hitdicegroup");
    deathgroup->setAlignment(Qt::AlignCenter);
    deathgroup->setFixedSize(220, 88);
    QVBoxLayout *deathgrouplayout = new QVBoxLayout();
    deathgrouplayout->setContentsMargins(30, 14, 30, 14);

    QHBoxLayout *succeslayout = new QHBoxLayout();
    QLabel *succes = new QLabel("Successi", this);
    succes->setFixedWidth(80);
    QCheckBox *succes1 = new QCheckBox(this);
    QCheckBox *succes2 = new QCheckBox(this);
    QCheckBox *succes3 = new QCheckBox(this);
    succeslayout->addWidget(succes, 0, Qt::AlignLeft);
    succeslayout->addWidget(succes1, 0, Qt::AlignRight);
    succeslayout->addWidget(succes2, 0, Qt::AlignRight);
    succeslayout->addWidget(succes3, 0, Qt::AlignRight);
    deathgrouplayout->addLayout(succeslayout);

    QHBoxLayout *insucceslayout = new QHBoxLayout();
    QLabel *insucces = new QLabel("Fallimenti", this);
    insucces->setFixedWidth(80);
    QCheckBox *insucces1 = new QCheckBox(this);
    QCheckBox *insucces2 = new QCheckBox(this);
    QCheckBox *insucces3 = new QCheckBox(this);
    insucceslayout->addWidget(insucces, 0, Qt::AlignLeft);
    insucceslayout->addWidget(insucces1, 0, Qt::AlignRight);
    insucceslayout->addWidget(insucces2, 0, Qt::AlignRight);
    insucceslayout->addWidget(insucces3, 0, Qt::AlignRight);
    deathgrouplayout->addLayout(insucceslayout);

    deathgroup->setLayout(deathgrouplayout);
    lowerlayout->addWidget(deathgroup);

    grouplayout->addLayout(hplayout);
    grouplayout->addLayout(buttonslayout);
    grouplayout->addLayout(lowerlayout);

    group->setLayout(grouplayout);

    mainlayout->addWidget(group);
    setLayout(mainlayout);
    setStyle();

    connect(Edit, SIGNAL(clicked()), this, SLOT(editClicked()));
    connect(Save, SIGNAL(clicked()), this, SLOT(saveClicked()));
    connect(Plus1, SIGNAL(clicked()), this, SLOT(add1hp()));
    connect(Plus5, SIGNAL(clicked()), this, SLOT(add5hp()));
    connect(Minus1, SIGNAL(clicked()), this, SLOT(remove1hp()));
    connect(Minus5, SIGNAL(clicked()), this, SLOT(remove5hp()));

    connect(CurrentHP, SIGNAL(valueChanged(int)), this, SLOT(applyCurrentHPChanges(int)));
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
}

void HealthBox::update()
{
    if (!Model->getSelectedPG()) {
        Edit->setEnabled(false);
        Plus1->setEnabled(false);
        Plus5->setEnabled(false);
        Minus1->setEnabled(false);
        Minus5->setEnabled(false);
        CurrentHP->setReadOnly(true);

        CurrentHP->setValue(0);
        MaxHP->setValue(0);
        HitDice->setValue(0);
    } else {
        Edit->setEnabled(true);
        Plus1->setEnabled(true);
        Plus5->setEnabled(true);
        Minus1->setEnabled(true);
        Minus5->setEnabled(true);
        CurrentHP->setReadOnly(false);

        CurrentHP->setValue((Model->getSelectedPG())->getPuntiVita());
        MaxHP->setValue((Model->getSelectedPG())->getPuntiVitaMassimi());
        HitDice->setValue((Model->getSelectedPG())->getDadoVita());
    }
}

void HealthBox::editClicked()
{
    Edit->setVisible(false);
    Save->setVisible(true);

    MaxHP->setReadOnly(false);
    MaxHP->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
}

void HealthBox::saveClicked()
{
    Save->setVisible(false);
    Edit->setVisible(true);

    MaxHP->setReadOnly(true);
    MaxHP->setButtonSymbols(QAbstractSpinBox::NoButtons);

    (Model->getSelectedPG())->setPuntiVitaMassimi(MaxHP->value());
}

void HealthBox::add1hp()
{
    CurrentHP->setValue(CurrentHP->value() + 1);
}

void HealthBox::add5hp()
{
    CurrentHP->setValue(CurrentHP->value() + 5);
}

void HealthBox::remove1hp()
{
    CurrentHP->setValue(CurrentHP->value() - 1);
}

void HealthBox::remove5hp()
{
    CurrentHP->setValue(CurrentHP->value() - 5);
}

void HealthBox::applyCurrentHPChanges(int i)
{
    if (Model->getSelectedPG())
        (Model->getSelectedPG())->setPuntiVita(i);
}

void HealthBox::setStyle()
{
    Edit->setIcon(QIcon(QPixmap(":/Resources/Edit.svg")));
    Save->setIcon(QIcon(QPixmap(":/Resources/Save.svg")));

    Edit->setFixedSize(32, 32);
    Save->setFixedSize(32, 32);
    Save->setVisible(false);

    CurrentHP->setAlignment(Qt::AlignHCenter);
    CurrentHP->setButtonSymbols(QAbstractSpinBox::NoButtons);
    CurrentHP->setFixedSize(90, 70);

    MaxHP->setAlignment(Qt::AlignHCenter);
    MaxHP->setButtonSymbols(QAbstractSpinBox::NoButtons);
    MaxHP->setReadOnly(true);
    MaxHP->setFixedSize(70, 50);

    Plus1->setFixedSize(44, 44);
    Plus5->setFixedSize(44, 44);
    Minus1->setFixedSize(44, 44);
    Minus5->setFixedSize(44, 44);

    HitDice->setFixedSize(45, 45);

    setStyleSheet(
        "#currhp {font-size:50px; }"
        "#maxhp {font-size:35px;}"
        "#slash {font-size:50px; color:#15DB95; }"
        "#plus1, #plus5, #minus1, #minus5 {font-size:20px; border:2px solid rgb(200,200,200); "
        "border-radius:5px; background-color: rgb(30,30,30);}"
        "#plus1, #plus5 {color:#15DB95;}"
        "#plus1::hover, #plus5::hover {border: 2px solid #15DB95; background-color: rgb(50,50,50);}"
        "#minus1, #minus5 {color:red;}"
        "#minus1::hover, #minus5::hover {border: 2px solid red; background-color: rgb(50,50,50);}"
        "#hitdicegroup, #deathgroup {font-size:17px;}"
        "#hitdice {font-size:25px;}");
}
