#include "stat.h"

Stat::Stat(QWidget *parent, Modello *m, const std::string &name)
    : QWidget(parent), Model(m), Caratteristica(name)
{
    QGroupBox *group = new QGroupBox(QString(QString::fromStdString(Caratteristica)), this);
    QVBoxLayout *mainlayout = new QVBoxLayout();
    QVBoxLayout *boxlayout = new QVBoxLayout();
    group->setObjectName("Stat");

    Valore = new QSpinBox(group);
    Modificatore = new QSpinBox(group);

    boxlayout->addWidget(Valore, 0, Qt::AlignCenter);
    boxlayout->addWidget(Modificatore, 0, Qt::AlignCenter);

    group->setLayout(boxlayout);
    mainlayout->addWidget(group);
    setLayout(mainlayout);

    //---Style---
    setStyle();
    boxlayout->setContentsMargins(0, 10, 0, 10);
    boxlayout->setSpacing(3);
    group->setAlignment(Qt::AlignHCenter);
    group->setMinimumWidth(115);
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    //---End Style---
}

void Stat::update()
{
    if (!Model->getSelectedPG()) {
        Valore->setValue(0);
        Modificatore->setValue(0);
    } else {
        Valore->setValue((Model->getSelectedPG())->getCaratteristica(Caratteristica));
        Modificatore->setValue(
            (Model->getSelectedPG())->getModificatoreCaratteristica(Caratteristica));
    }
}

void Stat::makeEditable()
{
    Valore->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
    Valore->setReadOnly(false);
}

void Stat::makeUneditable()
{
    Valore->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Valore->setReadOnly(true);
}

void Stat::setStyle()
{
    Valore->setObjectName("Valore");
    Valore->setFixedSize(70, 55);
    Valore->setAlignment(Qt::AlignHCenter);
    Valore->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Valore->setReadOnly(true);
    Valore->setMaximum(25);
    Modificatore->setReadOnly(true);
    Modificatore->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Modificatore->setAlignment(Qt::AlignHCenter);
    Modificatore->setMinimum(-5);
    setStyleSheet("QSpinBox {font-size:18px;}"
                  "QSpinBox#Valore {font-size :45px;}"
                  "QGroupBox#Stat{font-size:17px;}");
}
