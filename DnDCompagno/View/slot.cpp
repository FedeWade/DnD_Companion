#include "slot.h"

Slot::Slot(QWidget *parent, Modello *model, unsigned int lvl) : QWidget(parent), Model(model), Lvl(lvl)
{
    QVBoxLayout *mainlayout = new QVBoxLayout();
    mainlayout->setAlignment(Qt::AlignCenter);
    mainlayout->setSpacing(0);
    mainlayout->setContentsMargins(5, 0, 5, 0);

    QLabel *slotlabel = new QLabel("Lvl." + QString::number(Lvl), this);
    slotlabel->setAlignment(Qt::AlignCenter);
    Spells = new QSpinBox(this);
    Spells->setReadOnly(true);
    Spells->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Spells->setAlignment(Qt::AlignCenter);

    Spells->setFixedSize(45, 40);
    Spells->setMaximum(50);

    mainlayout->addWidget(slotlabel);
    mainlayout->addWidget(Spells);
    setLayout(mainlayout);
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
}

void Slot::update()
{
    Incantatore *PG = static_cast<Incantatore *>(Model->getSelectedPG());
    Spells->setValue(PG->getSlotIncantesimo(Lvl));
}

void Slot::makeEditable()
{
    Spells->setReadOnly(false);
    Spells->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
}

void Slot::makeUneditable()
{
    Spells->setReadOnly(true);
    Spells->setButtonSymbols(QAbstractSpinBox::NoButtons);
}

void Slot::applyChanges()
{
    Incantatore *PG = static_cast<Incantatore *>(Model->getSelectedPG());
    PG->setSlotIncantesimo(Lvl, Spells->value());
}
