#include "spellsslotsbox.h"

SpellsSlotsBox::SpellsSlotsBox(QWidget *parent, Modello *model) : QWidget(parent), Model(model)
{
    QVBoxLayout *mainlayout = new QVBoxLayout();
    QGroupBox *group = new QGroupBox("Slot incantesimi", this);
    group->setAlignment(Qt::AlignCenter);
    QVBoxLayout *grouplayout = new QVBoxLayout();
    grouplayout->setContentsMargins(0, 0, 0, 0);

    Edit = new QPushButton(this);
    Save = new QPushButton(this);

    grouplayout->addWidget(Edit, 0, Qt::AlignRight);
    grouplayout->addWidget(Save, 0, Qt::AlignRight);

    Grid = new QGridLayout();
    Grid->setAlignment(Qt::AlignCenter);
    Grid->setVerticalSpacing(25);
    Grid->setContentsMargins(15, 5, 15, 15);

    Lvl1 = new Slot(this, Model, 1);
    Grid->addWidget(Lvl1, 0, 0);
    Lvl2 = new Slot(this, Model, 2);
    Grid->addWidget(Lvl2, 0, 1);
    Lvl3 = new Slot(this, Model, 3);
    Grid->addWidget(Lvl3, 0, 2);
    Lvl4 = new Slot(this, Model, 4);
    Grid->addWidget(Lvl4, 1, 0);
    Lvl5 = new Slot(this, Model, 5);
    Grid->addWidget(Lvl5, 1, 1);
    Lvl6 = new Slot(this, Model, 6);
    Grid->addWidget(Lvl6, 1, 2);
    Lvl7 = new Slot(this, Model, 7);
    Grid->addWidget(Lvl7, 2, 0);
    Lvl8 = new Slot(this, Model, 8);
    Grid->addWidget(Lvl8, 2, 1);
    Lvl9 = new Slot(this, Model, 9);
    Grid->addWidget(Lvl9, 2, 2);

    SpellsDesc = new QTextEdit(this);
    SpellsDesc->setMinimumSize(250, 260);

    Grid->addWidget(SpellsDesc, 0, 3, 3, 3, Qt::AlignBottom);
    grouplayout->addLayout(Grid);

    group->setLayout(grouplayout);

    mainlayout->addWidget(group);
    setLayout(mainlayout);
    setStyle();

    connect(Edit, SIGNAL(clicked()), this, SLOT(editClicked()));
    connect(Save, SIGNAL(clicked()), this, SLOT(saveClicked()));
    connect(SpellsDesc, SIGNAL(textChanged()), this, SLOT(applySpellsListChanges()));
}

void SpellsSlotsBox::update()
{
    for (int i = 0; i < 9; i++) {
        QLayoutItem *item = Grid->itemAtPosition(i / 3, i % 3);
        Slot *slot = static_cast<Slot *>(item->widget());
        slot->update();
    }
    Incantatore *PG = static_cast<Incantatore *>(Model->getSelectedPG());
    SpellsDesc->setPlainText(QString::fromStdString(PG->getDescIncantesimi()));
}

void SpellsSlotsBox::editClicked()
{
    Edit->setVisible(false);
    Save->setVisible(true);

    for (int i = 0; i < 9; i++) {
        QLayoutItem *item = Grid->itemAtPosition(i / 3, i % 3);
        Slot *slot = static_cast<Slot *>(item->widget());
        slot->makeEditable();
    }
}

void SpellsSlotsBox::saveClicked()
{
    Save->setVisible(false);
    Edit->setVisible(true);

    for (int i = 0; i < 9; i++) {
        QLayoutItem *item = Grid->itemAtPosition(i / 3, i % 3);
        Slot *slot = static_cast<Slot *>(item->widget());
        slot->makeUneditable();
        slot->applyChanges();
    }
}

void SpellsSlotsBox::applySpellsListChanges()
{
    if (Model->getSelectedPG()) {
        Incantatore *PG = static_cast<Incantatore *>(Model->getSelectedPG());
        PG->setDescIncantesimi((SpellsDesc->toPlainText()).toStdString());
    }
}

void SpellsSlotsBox::setStyle()
{
    Edit->setIcon(QIcon(QPixmap(":/Resources/Edit.svg")));
    Save->setIcon(QIcon(QPixmap(":/Resources/Save.svg")));

    Edit->setFixedSize(32, 32);
    Save->setFixedSize(32, 32);
    Save->setVisible(false);

    setStyleSheet(" QLabel { font-size: 18px; } "
                  " QSpinBox {font-size: 22px; }");
}
