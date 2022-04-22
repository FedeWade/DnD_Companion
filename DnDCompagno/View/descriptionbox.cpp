#include "descriptionbox.h"

DescriptionBox::DescriptionBox(QWidget *parent, Modello *model) : QWidget(parent), Model(model)
{
    QVBoxLayout *mainlayout = new QVBoxLayout();
    QGroupBox *descgroup = new QGroupBox("Descrizione", this);
    QGroupBox *trattigroup = new QGroupBox("Tratti e Privilegi", this);
    QVBoxLayout *descl = new QVBoxLayout();
    QVBoxLayout *trattil = new QVBoxLayout();

    Description = new QTextEdit(this);
    Traits = new QTextEdit(this);

    descl->addWidget(Description);
    trattil->addWidget(Traits);
    descgroup->setLayout(descl);
    trattigroup->setLayout(trattil);
    mainlayout->addWidget(descgroup);
    mainlayout->addWidget(trattigroup);
    setLayout(mainlayout);

    //---Style---
    descl->setContentsMargins(15, 15, 15, 15);
    trattil->setContentsMargins(15, 15, 15, 15);
    descgroup->setAlignment(Qt::AlignCenter);
    trattigroup->setAlignment(Qt::AlignCenter);
    descgroup->setMinimumSize(475, 250);
    trattigroup->setMinimumSize(475, 290);
    //---End Style---

    connect(Description, SIGNAL(textChanged()), this, SLOT(applyDescriptionChanges()));
    connect(Traits, SIGNAL(textChanged()), this, SLOT(applyTraitsChanges()));
}

void DescriptionBox::update()
{
    if (Model->getSelectedPG()) {
        Description->setReadOnly(false);
        Traits->setReadOnly(false);
        Description->setPlainText(
            QString::fromStdString((Model->getSelectedPG())->getDescrizione()));
        Traits->setPlainText(QString::fromStdString((Model->getSelectedPG())->getTrattiPrivilegi()));
    } else {
        Description->setReadOnly(true);
        Traits->setReadOnly(true);
        Description->setPlainText("");
        Traits->setPlainText("");
    }
}

void DescriptionBox::applyDescriptionChanges()
{
    if (Model->getSelectedPG())
        (Model->getSelectedPG())->setDescrizione((Description->toPlainText()).toStdString());
}

void DescriptionBox::applyTraitsChanges()
{
    if (Model->getSelectedPG())
        (Model->getSelectedPG())->setTrattiPrivilegi((Traits->toPlainText()).toStdString());
}
