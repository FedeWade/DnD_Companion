#include "spellsbox.h"

SpellsBox::SpellsBox(QWidget *parent, Modello *model) : QWidget(parent), Model(model)
{
    QVBoxLayout *mainlayout = new QVBoxLayout();
    QHBoxLayout *infolayout = new QHBoxLayout();

    QGroupBox *infogroup = new QGroupBox("Incantatore", this);
    infogroup->setAlignment(Qt::AlignCenter);
    infogroup->setContentsMargins(10, 0, 10, 10);

    //carratteristica da incantatore
    QVBoxLayout *statlayout = new QVBoxLayout();
    statlayout->setAlignment(Qt::AlignCenter);
    QLabel *statlabel = new QLabel("Caratteristica\nda incantatore", this);
    statlabel->setAlignment(Qt::AlignCenter);
    Stat = new QLineEdit(this);
    statlayout->addWidget(statlabel);
    statlayout->addWidget(Stat, 0, Qt::AlignCenter);

    //cd tiro salvezza incantesimi
    QVBoxLayout *cdlayout = new QVBoxLayout();
    cdlayout->setAlignment(Qt::AlignCenter);
    QLabel *cdlabel = new QLabel("CD tiro salvezza\nincantesimi", this);
    cdlabel->setAlignment(Qt::AlignCenter);
    CD = new QSpinBox(this);
    cdlayout->addWidget(cdlabel);
    cdlayout->addWidget(CD, 0, Qt::AlignCenter);

    //bonus attacco incanntesimi
    QVBoxLayout *bonuslayout = new QVBoxLayout();
    bonuslayout->setAlignment(Qt::AlignCenter);
    QLabel *bonuslabel = new QLabel("Bonus attacco\nincantesimi", this);
    bonuslabel->setAlignment(Qt::AlignCenter);
    SpellAttackBonus = new QSpinBox(this);
    bonuslayout->addWidget(bonuslabel);
    bonuslayout->addWidget(SpellAttackBonus, 0, Qt::AlignCenter);

    Stat->setReadOnly(true);
    CD->setReadOnly(true);
    SpellAttackBonus->setReadOnly(true);
    CD->setButtonSymbols(QAbstractSpinBox::NoButtons);
    SpellAttackBonus->setButtonSymbols(QAbstractSpinBox::NoButtons);

    infolayout->addLayout(statlayout);
    infolayout->addLayout(cdlayout);
    infolayout->addLayout(bonuslayout);

    infogroup->setLayout(infolayout);

    mainlayout->addWidget(infogroup);
    setLayout(mainlayout);
    setStyle();
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
}

void SpellsBox::update()
{
    Incantatore *PG = static_cast<Incantatore *>(
        Model->getSelectedPG()); //sarà sicuramente un incantatore, me ne sarei accorto su update() di dnd

    Stat->setText(QString(QString::fromStdString(PG->getCaratteristicaIncantatore())));
    CD->setValue(PG->getCDTiroSalvezzaIncantesimo());
    SpellAttackBonus->setValue(PG->getModificatoreAttaccoIncantesimo());
}

void SpellsBox::setStyle()
{
    Stat->setObjectName("stat");
    CD->setObjectName("cd");
    SpellAttackBonus->setObjectName("spellbonus");

    Stat->setAlignment(Qt::AlignCenter);
    CD->setAlignment(Qt::AlignCenter);
    SpellAttackBonus->setAlignment(Qt::AlignCenter);

    Stat->setFixedSize(100, 35);
    CD->setFixedSize(50, 35);
    SpellAttackBonus->setFixedSize(50, 35);

    setStyleSheet(" #stat { font-size: 18px; } "
                  " #cd, #spellbonus { font-size:22px; }");
}
