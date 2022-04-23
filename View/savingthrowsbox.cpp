#include "savingthrowsbox.h"

SavingThrowsBox::SavingThrowsBox(QWidget *parent, Modello *modello)
    : QWidget(parent), Model(modello)
{
    QVBoxLayout *mainlayout = new QVBoxLayout();
    grouplayout = new QVBoxLayout(this);
    grouplayout->setContentsMargins(10, 0, 0, 10);
    QGroupBox *group = new QGroupBox("Tiri Salvezza", this);
    group->setAlignment(Qt::AlignCenter);
    group->setMinimumWidth(215);

    Edit = new QPushButton(this);
    Save = new QPushButton(this);

    grouplayout->addWidget(Edit, 0, Qt::AlignRight);
    grouplayout->addWidget(Save, 0, Qt::AlignRight);

    //inizializzo i vari TS
    Forza = new SavingThrow(this, Model, "Forza");
    grouplayout->addWidget(Forza, 0, Qt::AlignCenter);
    Destrezza = new SavingThrow(this, Model, "Destrezza");
    grouplayout->addWidget(Destrezza, 0, Qt::AlignCenter);
    Costituzione = new SavingThrow(this, Model, "Costituzione");
    grouplayout->addWidget(Costituzione, 0, Qt::AlignCenter);
    Intelligenza = new SavingThrow(this, Model, "Intelligenza");
    grouplayout->addWidget(Intelligenza, 0, Qt::AlignCenter);
    Saggezza = new SavingThrow(this, Model, "Saggezza");
    grouplayout->addWidget(Saggezza, 0, Qt::AlignCenter);
    Carisma = new SavingThrow(this, Model, "Carisma");
    grouplayout->addWidget(Carisma, 0, Qt::AlignCenter);

    group->setLayout(grouplayout);
    mainlayout->addWidget(group);

    setLayout(mainlayout);

    connect(Edit, SIGNAL(clicked()), this, SLOT(editClicked()));
    connect(Save, SIGNAL(clicked()), this, SLOT(saveClicked()));
    setStyle();
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
}

void SavingThrowsBox::setStyle()
{
    Edit->setIcon(QIcon(QPixmap(":/Resources/Edit.svg")));
    Save->setIcon(QIcon(QPixmap(":/Resources/Save.svg")));

    Edit->setFixedSize(32, 32);
    Save->setFixedSize(32, 32);
    Save->setVisible(false);
    setStyleSheet("QLabel {font-size:18px;}");
}

void SavingThrowsBox::update()
{
    Model->getSelectedPG() ? Edit->setEnabled(true) : Edit->setEnabled(false);

    for (int i = 2; i < 8; i++) { //skippo i primi 2 elementi che sono Save e Edit
        QLayoutItem *item = grouplayout->itemAt(i);
        SavingThrow *ST = static_cast<SavingThrow *>(item->widget());
        ST->update();
    }
}

void SavingThrowsBox::editClicked()
{
    Edit->setVisible(false);
    Save->setVisible(true);

    for (int i = 2; i < 8; i++) { //skippo i primi 2 elementi che sono Save e Edit
        QLayoutItem *item = grouplayout->itemAt(i);
        SavingThrow *ST = static_cast<SavingThrow *>(item->widget());
        ST->makeCheckable();
    }
}

void SavingThrowsBox::saveClicked()
{
    Save->setVisible(false);
    Edit->setVisible(true);

    for (int i = 2; i < 8; i++) { //skippo i primi 2 elementi che sono Save e Edit
        QLayoutItem *item = grouplayout->itemAt(i);
        SavingThrow *ST = static_cast<SavingThrow *>(item->widget());
        try {
            (Model->getSelectedPG())->setCompetenzaStatistica(ST->Name, ST->Check->isChecked());

        } catch (std::exception *exc) {
            ExceptionMessage *errmsg = new ExceptionMessage(this, exc->what());
            errmsg->show();
        }

        ST->makeUncheckable();
    }
    update();
}
