#include "skillsbox.h"

SkillsBox::SkillsBox(QWidget *parent, Modello *modello) : QWidget(parent), Model(modello)
{
    QVBoxLayout *mainlayout = new QVBoxLayout();
    grouplayout = new QVBoxLayout(this);
    QGroupBox *group = new QGroupBox("Abilità", this);

    Edit = new QPushButton(this);
    Save = new QPushButton(this);

    grouplayout->addWidget(Edit, 0, Qt::AlignRight);
    grouplayout->addWidget(Save, 0, Qt::AlignRight);

    Acrobazia = new Skill(this, Model, "Acrobazia");
    grouplayout->addWidget(Acrobazia, 0, Qt::AlignCenter);
    AddestrareAnimali = new Skill(this, Model, "Addestrare animali");
    grouplayout->addWidget(AddestrareAnimali, 0, Qt::AlignCenter);
    Arcano = new Skill(this, Model, "Arcano");
    grouplayout->addWidget(Arcano, 0, Qt::AlignCenter);
    Atletica = new Skill(this, Model, "Atletica");
    grouplayout->addWidget(Atletica, 0, Qt::AlignCenter);
    Furtivita = new Skill(this, Model, "Furtività");
    grouplayout->addWidget(Furtivita, 0, Qt::AlignCenter);
    Indagare = new Skill(this, Model, "Indagare");
    grouplayout->addWidget(Indagare, 0, Qt::AlignCenter);
    Inganno = new Skill(this, Model, "Inganno");
    grouplayout->addWidget(Inganno, 0, Qt::AlignCenter);
    Intimidire = new Skill(this, Model, "Intimidire");
    grouplayout->addWidget(Intimidire, 0, Qt::AlignCenter);
    Intrattenere = new Skill(this, Model, "Intrattenere");
    grouplayout->addWidget(Intrattenere, 0, Qt::AlignCenter);
    Intuizione = new Skill(this, Model, "Intuizione");
    grouplayout->addWidget(Intuizione, 0, Qt::AlignCenter);
    Medicina = new Skill(this, Model, "Medicina");
    grouplayout->addWidget(Medicina, 0, Qt::AlignCenter);
    Natura = new Skill(this, Model, "Natura");
    grouplayout->addWidget(Natura, 0, Qt::AlignCenter);
    Percezione = new Skill(this, Model, "Percezione");
    grouplayout->addWidget(Percezione, 0, Qt::AlignCenter);
    Persuasione = new Skill(this, Model, "Persuasione");
    grouplayout->addWidget(Persuasione, 0, Qt::AlignCenter);
    RapiditaDiMano = new Skill(this, Model, "Rapidità di mano");
    grouplayout->addWidget(RapiditaDiMano, 0, Qt::AlignCenter);
    Religione = new Skill(this, Model, "Religione");
    grouplayout->addWidget(Religione, 0, Qt::AlignCenter);
    Sopravvivenza = new Skill(this, Model, "Sopravvivenza");
    grouplayout->addWidget(Sopravvivenza, 0, Qt::AlignCenter);
    Storia = new Skill(this, Model, "Storia");
    grouplayout->addWidget(Storia, 0, Qt::AlignCenter);

    group->setLayout(grouplayout);
    mainlayout->addWidget(group);

    setLayout(mainlayout);

    //---Style---
    setStyle();
    grouplayout->setContentsMargins(10, 0, 0, 10);
    group->setAlignment(Qt::AlignCenter);
    group->setMinimumWidth(225);

    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    //---End Style---

    connect(Edit, SIGNAL(clicked()), this, SLOT(editClicked()));
    connect(Save, SIGNAL(clicked()), this, SLOT(saveClicked()));

}

void SkillsBox::setStyle()
{
    Edit->setIcon(QIcon(QPixmap(":/Resources/Edit.svg")));
    Save->setIcon(QIcon(QPixmap(":/Resources/Save.svg")));

    Edit->setFixedSize(32, 32);
    Save->setFixedSize(32, 32);
    Save->setVisible(false);
    setStyleSheet("QLabel {font-size:18px;}");
}

void SkillsBox::update()
{
    Model->getSelectedPG() ? Edit->setEnabled(true) : Edit->setEnabled(false);

    for (int i = 2; i < 20; i++) { //skippo i primi 2 elementi che sono Save e Edit
        QLayoutItem *item = grouplayout->itemAt(i);
        Skill *skill = static_cast<Skill *>(item->widget());
        skill->update();
    }
}

void SkillsBox::editClicked()
{
    Edit->clearFocus();
    Edit->setVisible(false);
    Save->setVisible(true);

    for (int i = 2; i < 20; i++) { //skippo i primi 2 elementi che sono Save e Edit
        QLayoutItem *item = grouplayout->itemAt(i);
        Skill *skill = static_cast<Skill *>(item->widget());
        skill->makeCheckable();
    }
}

void SkillsBox::saveClicked()
{
    Save->setVisible(false);
    Edit->setVisible(true);

    for (int i = 2; i < 20; i++) { //skippo i primi 2 elementi che sono Save e Edit
        QLayoutItem *item = grouplayout->itemAt(i);
        Skill *skill = static_cast<Skill *>(item->widget());

        try {
            (Model->getSelectedPG())->setCompetenzaAbilita(skill->Name, skill->Check->isChecked());
        } catch (std::exception *exc) {
            ExceptionMessage *errmsg = new ExceptionMessage(this, exc->what());
            errmsg->show();
            update();
        }

        skill->makeUncheckable();
    }
    update();
}
