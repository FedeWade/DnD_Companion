#include "statsbox.h"

StatsBox::StatsBox(QWidget *parent, Modello *modello) : QWidget(parent), Model(modello)
{
    QVBoxLayout *grouplayout = new QVBoxLayout();
    QVBoxLayout *mainlayout = new QVBoxLayout();
    QGroupBox *group = new QGroupBox("Caratteristiche", this);

    Edit = new QPushButton(this);
    Save = new QPushButton(this);

    grouplayout->addWidget(Edit, 0, Qt::AlignRight);
    grouplayout->addWidget(Save, 0, Qt::AlignRight);

    Forza = new Stat(this, Model, "Forza");
    grouplayout->addWidget(Forza, 0, Qt::AlignCenter);
    Destrezza = new Stat(this, Model, "Destrezza");
    grouplayout->addWidget(Destrezza, 0, Qt::AlignCenter);
    Costituzione = new Stat(this, Model, "Costituzione");
    grouplayout->addWidget(Costituzione, 0, Qt::AlignCenter);
    Intelligenza = new Stat(this, Model, "Intelligenza");
    grouplayout->addWidget(Intelligenza, 0, Qt::AlignCenter);
    Saggezza = new Stat(this, Model, "Saggezza");
    grouplayout->addWidget(Saggezza, 0, Qt::AlignCenter);
    Carisma = new Stat(this, Model, "Carisma");
    grouplayout->addWidget(Carisma, 0, Qt::AlignCenter);

    group->setLayout(grouplayout);
    mainlayout->addWidget(group);

    setLayout(mainlayout);
    setStyle();

    //---Style---
    group->setAlignment(Qt::AlignCenter);
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    grouplayout->setContentsMargins(0, 9, 0, 0);
    grouplayout->setSpacing(0);
    group->setMinimumWidth(190);
    //---End Style---

    connect(Edit, SIGNAL(clicked()), this, SLOT(editClicked()));
    connect(Save, SIGNAL(clicked()), this, SLOT(saveClicked()));

}

void StatsBox::update()
{
    Model->getSelectedPG() ? Edit->setEnabled(true) : Edit->setEnabled(false);

    Forza->update();
    Destrezza->update();
    Costituzione->update();
    Intelligenza->update();
    Saggezza->update();
    Carisma->update();
}

void StatsBox::editClicked()
{
    Edit->setVisible(false);
    Save->setVisible(true);

    Forza->makeEditable();
    Destrezza->makeEditable();
    Costituzione->makeEditable();
    Intelligenza->makeEditable();
    Saggezza->makeEditable();
    Carisma->makeEditable();
}

void StatsBox::saveClicked()
{
    Save->setVisible(false);
    Edit->setVisible(true);

    Forza->makeUneditable();
    Destrezza->makeUneditable();
    Costituzione->makeUneditable();
    Intelligenza->makeUneditable();
    Saggezza->makeUneditable();
    Carisma->makeUneditable();

    (Model->getSelectedPG())->setForza(Forza->Valore->value());
    (Model->getSelectedPG())->setDestrezza(Destrezza->Valore->value());
    (Model->getSelectedPG())->setCostituzione(Costituzione->Valore->value());
    (Model->getSelectedPG())->setIntelligenza(Intelligenza->Valore->value());
    (Model->getSelectedPG())->setSaggezza(Saggezza->Valore->value());
    (Model->getSelectedPG())->setCarisma(Carisma->Valore->value());

    emit(valuesChanged());
}

void StatsBox::setStyle() const
{
    Edit->setIcon(QIcon(QPixmap(":/Resources/Edit.svg")));
    Save->setIcon(QIcon(QPixmap(":/Resources/Save.svg")));

    Edit->setFixedSize(32, 32);
    Save->setFixedSize(32, 32);
    Save->setVisible(false);
}
